#include "MapToolDemo.h"


MapToolDemo::MapToolDemo(QWidget * parent) :
    QWidget(parent),
    mCanvas(this),
    mToolPan(&mCanvas),
    mToolEmitPoint(&mCanvas),
    mToolIdentifyFeature(&mCanvas)
{
    ui.setupUi(this);

    // 在主窗体的竖直布局最后添加画布组件
    ui.lytMain->addWidget(&mCanvas);

    // 新建矢量图层添加到画布
    QgsVectorLayer* pVectorLayer = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_2.shp", u8"市级行政区");
    mCanvas.setLayers(QList<QgsMapLayer*>() << pVectorLayer);
    mCanvas.zoomToFullExtent();

    // 将标识工具的目标图层设定为刚建立的图层
    mToolIdentifyFeature.setLayer(pVectorLayer);

    // 工具单选框的选择信号
    QObject::connect(ui.radPan, &QRadioButton::toggled, this, &MapToolDemo::onMapToolSelected);
    QObject::connect(ui.radEmitPoint, &QRadioButton::toggled, this, &MapToolDemo::onMapToolSelected);
    QObject::connect(ui.radIdentifyFeature, &QRadioButton::toggled, this, &MapToolDemo::onMapToolSelected);

    // EmitPoint 工具的画布点击信号
    QObject::connect(&mToolEmitPoint, &QgsMapToolEmitPoint::canvasClicked, [=](const QgsPointXY & point, Qt::MouseButton button) {
        QMessageBox::information(this, "QgsMapToolEmitPoint", QString("X: %1\nY: %2").arg(QString::number(point.x()), QString::number(point.y())));
    });

    // IdentifyFeature 工具的画布点击信号
    QObject::connect(&mToolIdentifyFeature, static_cast<void (QgsMapToolIdentifyFeature:: *)(const QgsFeature &)>(&QgsMapToolIdentifyFeature::featureIdentified), [=](const QgsFeature & feature) {
        
        // 高亮被点击的要素
        clearHighlight();
        mpHighlight = new QgsHighlight(&mCanvas, feature.geometry(), pVectorLayer);
        QColor color = QColor(Qgis::DEFAULT_HIGHLIGHT_COLOR.name());
        color.setAlpha(Qgis::DEFAULT_HIGHLIGHT_COLOR.alpha());
        mpHighlight->setColor(color);
        mpHighlight->setFillColor(color);
        mpHighlight->setBuffer(Qgis::DEFAULT_HIGHLIGHT_BUFFER_MM);
        mpHighlight->setMinWidth(Qgis::DEFAULT_HIGHLIGHT_MIN_WIDTH_MM);
        
        // 遍历要素的属性值并显示
        QString msg;
        QgsFields fields = feature.fields();
        for (int i = 0; i < fields.count(); i++)
        {
            msg += QString("%1: %2\n").arg(fields.at(i).name(), feature.attribute(i).toString());
        }
        QMessageBox::information(this, "QgsMapToolIdentifyFeature", msg);
        
    });
}

void MapToolDemo::onMapToolSelected(bool isChecked)
{
    if (!isChecked)
    {
        return;
    }
    clearHighlight();
    if (ui.radPan->isChecked())
    {
        mCanvas.setMapTool(&mToolPan);
    }
    else if (ui.radEmitPoint->isChecked())
    {
        mCanvas.setMapTool(&mToolEmitPoint);
    }
    else if (ui.radIdentifyFeature->isChecked())
    {
        mCanvas.setMapTool(&mToolIdentifyFeature);
    }
}

void MapToolDemo::clearHighlight()
{
    if (mpHighlight)
    {
        delete mpHighlight;
    }
    mpHighlight = nullptr;
}
