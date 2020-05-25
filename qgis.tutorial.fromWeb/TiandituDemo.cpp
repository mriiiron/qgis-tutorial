#include "TiandituDemo.h"


TiandituDemo::TiandituDemo(QWidget * parent) :
    QWidget(parent),
    mCanvas(this),
    mTdtUrlImg(),
    mTdtUrlImgAnno(),
    mTdtUrlVec(),
    mTdtUrlVecAnno()
{
    ui.setupUi(this);

    // 在主窗体的竖直布局最后添加画布组件
    ui.lytMain->addWidget(&mCanvas);

    mCanvas.setDestinationCrs(QgsCoordinateReferenceSystem("EPSG:3857"));

    // 天地图图层单选框的选择信号
    QObject::connect(ui.radImg, &QRadioButton::toggled, this, &TiandituDemo::onDataSelected);
    QObject::connect(ui.radVec, &QRadioButton::toggled, this, &TiandituDemo::onDataSelected);

    // 构造天地图 URL
    quint32 r = QRandomGenerator::global()->generate() % 8;
    QString tdtUrlBase = "http://t%1.tianditu.com/DataServer?T=%2&x={x}&y={y}&l={z}&tk=%3";
    QString token = "5dc38484e3f0715c91ae90ea06d19e3d";
    QString tdtImgUrl = tdtUrlBase.arg(QString::number(r), "img_w", token);
    QString tdtImgAnnoUrl = tdtUrlBase.arg(QString::number(r), "cia_w", token);
    QString tdtVecUrl = tdtUrlBase.arg(QString::number(r), "vec_w", token);
    QString tdtVecAnnoUrl = tdtUrlBase.arg(QString::number(r), "cva_w", token);
    QString tdtImgFull = QString("type=xyz&url=%1&zmax=18&zmin=0").arg(QUrl::toPercentEncoding(tdtImgUrl, ":/?=").constData());
    QString tdtImgAnnoFull = QString("type=xyz&url=%1&zmax=18&zmin=0").arg(QUrl::toPercentEncoding(tdtImgAnnoUrl, ":/?=").constData());
    QString tdtVecFull = QString("type=xyz&url=%1&zmax=18&zmin=0").arg(QUrl::toPercentEncoding(tdtVecUrl, ":/?=").constData());
    QString tdtVecAnnoFull = QString("type=xyz&url=%1&zmax=18&zmin=0").arg(QUrl::toPercentEncoding(tdtVecAnnoUrl, ":/?=").constData());

    // 创建天地图图层
    mpBaseMapLayerImg = new QgsRasterLayer(tdtImgFull, "Tianditu Image", "wms");
    if (!mpBaseMapLayerImg->isValid())
    {
        QMessageBox::critical(this, u8"错误", QString(u8"图层载入失败。\n\n返回消息：\n%1").arg(mpBaseMapLayerImg->error().message()));
        return;
    }
    mpBaseMapAnnotationLayerImg = new QgsRasterLayer(tdtImgAnnoFull, "Tianditu Image Annotation", "wms");
    if (!mpBaseMapAnnotationLayerImg->isValid())
    {
        QMessageBox::critical(this, u8"错误", QString(u8"图层载入失败。\n\n返回消息：\n%1").arg(mpBaseMapAnnotationLayerImg->error().message()));
        return;
    }
    mpBaseMapLayerVec = new QgsRasterLayer(tdtVecFull, "Tianditu Vector", "wms");
    if (!mpBaseMapLayerVec->isValid())
    {
        QMessageBox::critical(this, u8"错误", QString(u8"图层载入失败。\n\n返回消息：\n%1").arg(mpBaseMapLayerVec->error().message()));
        return;
    }
    mpBaseMapAnnotationLayerVec = new QgsRasterLayer(tdtVecAnnoFull, "Tianditu Vector Annotation", "wms");
    if (!mpBaseMapAnnotationLayerVec->isValid())
    {
        QMessageBox::critical(this, u8"错误", QString(u8"图层载入失败。\n\n返回消息：\n%1").arg(mpBaseMapAnnotationLayerVec->error().message()));
        return;
    }

}

void TiandituDemo::onDataSelected(bool isChecked)
{
    if (!isChecked)
    {
        return;
    }

    if (ui.radImg->isChecked())
    {
        mCanvas.setLayers(QList<QgsMapLayer*>() << mpBaseMapAnnotationLayerImg << mpBaseMapLayerImg);
    }
    else if (ui.radVec->isChecked())
    {
        mCanvas.setLayers(QList<QgsMapLayer*>()<< mpBaseMapAnnotationLayerVec << mpBaseMapLayerVec);
    }

    mCanvas.zoomToFullExtent();
}
