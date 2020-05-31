#include "FeatureFilterDemo.h"


FeatureFilterDemo::FeatureFilterDemo(QWidget * parent) :
	QWidget(parent),
	mCanvas(this)
{
	ui.setupUi(this);
	ui.lytMain->addWidget(&mCanvas);

	// 创建图层
	mpVectorLayer = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_2.shp", u8"市级行政区");
	
	// 创建图层缓存
	mpVectorLayerCache = new QgsVectorLayerCache(mpVectorLayer, mpVectorLayer->featureCount());
	
	// 创建属性表 Model
	mpAttrTableModel = new QgsAttributeTableModel(mpVectorLayerCache);
	mpAttrTableModel->loadLayer();

	// 创建属性表筛选器 Model
	mpAttrTableFilterModel = new QgsAttributeTableFilterModel(&mCanvas, mpAttrTableModel);
	
	// 添加图层到画布并显示
	mCanvas.setLayers(QList<QgsMapLayer*>() << mpVectorLayer);
	mCanvas.zoomToFullExtent();
	
	// 按钮事件
	QObject::connect(ui.btnOpenAttributeTable, &QPushButton::clicked, this, &FeatureFilterDemo::onOpenAttributeTableButtonClicked);
	QObject::connect(ui.btnApplyWhereClause, &QPushButton::clicked, this, &FeatureFilterDemo::onApplyWhereClauseButtonClicked);
}

void FeatureFilterDemo::onOpenAttributeTableButtonClicked()
{
	QgsAttributeTableView* pView = new QgsAttributeTableView(this);
	pView->setWindowModality(Qt::WindowModality::WindowModal);
	pView->setWindowFlag(Qt::Window);
	pView->setWindowTitle(u8"图层属性表");
	pView->setModel(mpAttrTableFilterModel);
	pView->resize(1000, 450);
	pView->show();
}

void FeatureFilterDemo::onApplyWhereClauseButtonClicked()
{

	// 获取用户输入的筛选子句
	QString whereClause = ui.leWhereClause->text();

	// 设置图层筛选子句
	if (!mpVectorLayer->setSubsetString(whereClause))
	{
		if (mpVectorLayer->dataProvider()->hasErrors())
		{
			QMessageBox::warning(this, u8"错误", QString(u8"查询执行错误。返回信息：\n\n%1").arg(mpVectorLayer->dataProvider()->errors().join("\n")));
			mpVectorLayer->dataProvider()->clearErrors();
		}
		else
		{
			QMessageBox::warning(this, u8"错误", u8"设置过滤表达式失败。");
		}
	}

}
