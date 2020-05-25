#include "PostgisDemo.h"


PostgisDemo::PostgisDemo(QWidget * parent) :
    QWidget(parent),
    mCanvas(this),
    mToolDrawRect(&mCanvas)
{
    ui.setupUi(this);

    // 在主窗体的竖直布局最后添加画布组件
    ui.lytMain->addWidget(&mCanvas);

    // 添加 PostGIS 数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    if (!db.isValid())
    {
        QMessageBox::critical(this, u8"错误", u8"不支持指定的数据库类型。");
        return;
    }
    db.setHostName("192.168.142.3");
    db.setDatabaseName("gisdb");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("foreversyke");
    db.setConnectOptions("connect_timeout=3");
    db.open();
    if (!db.isOpen())
    {
        QMessageBox::critical(this, u8"错误", u8"打开数据库失败。");
        return;
    }

    // 建立指向数据库中的表的资源 URI
    QgsDataSourceUri uri;
    uri.setConnection(db.hostName(), QString::number(db.port()), db.databaseName(), db.userName(), db.password());
    uri.setDataSource("public", "gadm36_chn_3", "geom");

    // 尝试从指定的 URL 创建图层
    QgsVectorLayer* pVectorLayer = new QgsVectorLayer(uri.uri(), u8"县级行政区", "postgres");
    if (!pVectorLayer->isValid()) {
        QMessageBox::critical(this, u8"错误", QString(u8"图层加载失败：%1").arg(pVectorLayer->error().message(QgsErrorMessage::Format::Text)));
        return;
    }

    // 关闭 PostGIS 数据库连接
    db.close();

    // 将图层添加到画布上并缩放到图层
    mCanvas.setLayers(QList<QgsMapLayer*>() << pVectorLayer);
    mCanvas.zoomToFullExtent();

    // 测试统计查询按钮点击信号
    QObject::connect(ui.btnRunStatistics, &QPushButton::clicked, this, &PostgisDemo::onTestStatisticsQueryButtonClicked);

    // 绘制裁切矩形按钮点击信号
    QObject::connect(ui.btnDrawRect, &QPushButton::toggled, this, &PostgisDemo::onDrawPolygonButtonClicked);

    // 执行裁切按钮点击信号
    QObject::connect(ui.btnRunClip, &QPushButton::clicked, this, &PostgisDemo::onRunClipButtonClicked);
}

void PostgisDemo::onTestStatisticsQueryButtonClicked()
{

    // 传入 SQL 语句建立 QSqlQueryModel
    QSqlQueryModel* pModel = new QSqlQueryModel;
    pModel->setQuery("SELECT \"name_1\" AS \"province_name\", COUNT(0) AS \"county_count\" FROM \"gadm36_chn_3\" GROUP BY \"name_1\"", QSqlDatabase::database());
    pModel->setHeaderData(0, Qt::Horizontal, u8"省级行政区名");
    pModel->setHeaderData(1, Qt::Horizontal, u8"县级行政区数目");

    // 将 Model 应用于 QTableView，显示
    QTableView* pView = new QTableView(this);
    pView->setModel(pModel);
    pView->setWindowModality(Qt::WindowModality::WindowModal);
    pView->setWindowFlag(Qt::Window);
    pView->setWindowTitle(u8"测试统计结果");
    pView->show();
}

void PostgisDemo::onDrawPolygonButtonClicked(bool isChecked)
{
    if (isChecked)
    {
        mCanvas.setMapTool(&mToolDrawRect);
    }
    else
    {
        mCanvas.unsetMapTool(&mToolDrawRect);
    }
}

void PostgisDemo::onRunClipButtonClicked()
{
    if (mToolDrawRect.extent().isEmpty())
    {
        QMessageBox::warning(this, u8"提示", QString(u8"请先绘制裁切矩形。"));
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        QMessageBox::critical(this, u8"错误", QString(u8"无法连接到数据库：\n%1").arg(db.lastError().text()));
        return;
    }

    QSqlQuery query(db);
    db.transaction();
    
    QString resultTableName = "clip_result";

    // 如果结果表存在，删除结果表
    QString sql = QString("DROP TABLE IF EXISTS \"%1\"").arg(resultTableName);
    if (!query.exec(sql))
    {
        QMessageBox::critical(this, u8"错误", QString(u8"SQL 错误：\n%1\n\n完整 SQL：\n%2").arg(query.lastError().text(), sql));
        db.rollback();
        return;
    }

    // 创建结果表
    sql = QString("CREATE TABLE \"%1\" (\"id\" SERIAL PRIMARY KEY)").arg(resultTableName);
    if (!query.exec(sql))
    {
        QMessageBox::critical(this, u8"错误", QString(u8"SQL 错误：\n%1\n\n完整 SQL：\n%2").arg(query.lastError().text(), sql));
        db.rollback();
        return;
    }

    // 获取源图层的坐标系 ID 和空间数据字段名
    sql = QString("SELECT \"srid\", \"f_geometry_column\", \"type\" FROM \"geometry_columns\" WHERE \"f_table_name\" = 'gadm36_chn_3'");
    if (!query.exec(sql))
    {
        QMessageBox::critical(this, u8"错误", QString(u8"SQL 错误：\n%1\n\n完整 SQL：\n%2").arg(query.lastError().text(), sql));
        db.rollback();
        return;
    }
    query.first();
    QString srid = query.value(0).toString();
    QString geomColumnName = query.value(1).toString();
    QString geomType = query.value(2).toString();

    // 为结果表添加空间数据字段 geom
    // 第五个参数 2 表示二维
    sql = QString("SELECT AddGeometryColumn('%1', 'geom', %2, '%3', 2)").arg(resultTableName, srid, geomType);
    if (!query.exec(sql))
    {
        QMessageBox::critical(this, u8"错误", QString(u8"SQL 错误：\n%1\n\n完整 SQL：\n%2").arg(query.lastError().text(), sql));
        db.rollback();
        return;
    }

    // 裁切
    sql = QString(
        "INSERT INTO \"%1\" (\"geom\") "
        "WITH \"cte\" AS ( "
            "SELECT ST_GeomFromText('%2', %3) AS \"clipper\" "
        ") "
        "SELECT "
            "CASE "
                "WHEN ST_Covers(\"cte\".\"clipper\", \"t\".\"geom\") THEN ST_Multi(\"t\".\"geom\") "
                "ELSE ST_Multi(ST_Intersection(\"cte\".\"clipper\", \"t\".\"geom\")) "
            "END AS \"geom\" "
        "FROM "
            "\"gadm36_chn_3\" AS \"t\" INNER JOIN \"cte\" ON ST_Intersects(\"cte\".\"clipper\", \"t\".\"geom\") "
    ).arg(resultTableName, mToolDrawRect.extent().asWktPolygon(), srid);
    if (!query.exec(sql))
    {
        QMessageBox::critical(this, u8"错误", QString(u8"SQL 错误：\n%1\n\n完整 SQL：\n%2").arg(query.lastError().text(), sql));
        db.rollback();
        return;
    }

    db.commit();
    QMessageBox::information(this, u8"消息", u8"裁切执行成功。清用 QGIS 打开数据查看结果。");
    
}