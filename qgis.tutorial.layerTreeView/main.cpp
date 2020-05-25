#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgslayertree.h>
#include <qgslayertreemodel.h>
#include <qgslayertreeview.h>

#include <QHBoxLayout>


class LayerTreeDemo : public QWidget
{

public:

    LayerTreeDemo(QWidget * parent = 0);

private:

    // 画布
    QgsMapCanvas mMapCanvas;

    // 图层树 View
    QgsLayerTreeView mLayerTreeView;

    // 更新画布图层的“事件回调”
    void updateCanvasLayerSet();

};

LayerTreeDemo::LayerTreeDemo(QWidget * parent) :
    QWidget(parent),
    mMapCanvas(this),
    mLayerTreeView(this)
{

    // 创建图层树 Model 并与图层树 View 关联
    QgsLayerTree* pLayerTreeRoot = QgsProject::instance()->layerTreeRoot();
    QObject::connect(pLayerTreeRoot, &QgsLayerTreeNode::visibilityChanged, this, &LayerTreeDemo::updateCanvasLayerSet);
    QgsLayerTreeModel* pLayerTreeModel = new QgsLayerTreeModel(pLayerTreeRoot);
    pLayerTreeModel->setFlag(QgsLayerTreeModel::AllowNodeChangeVisibility);

    // 创建图层树 View
    mLayerTreeView.setModel(pLayerTreeModel);
    mLayerTreeView.setMaximumWidth(200);

    // 将图层树和画布添加到水平布局
    QHBoxLayout* pLayout = new QHBoxLayout();
    pLayout->addWidget(&mLayerTreeView);
    pLayout->addWidget(&mMapCanvas);

    // 应用布局到自身并设置窗体标题
    this->setLayout(pLayout);
    this->resize(1000, 600);
    this->setWindowTitle(u8"QGIS 二次开发：图层树");

    // 从磁盘 .shp 文件创建并添加若干矢量图层
    QgsVectorLayer* pVectorLayer_1 = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_1.shp", u8"省级行政区");
    QgsVectorLayer* pVectorLayer_2 = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_2.shp", u8"市级行政区");
    QgsVectorLayer* pVectorLayer_3 = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_3.shp", u8"县级行政区");
    QgsProject::instance()->addMapLayer(pVectorLayer_1);
    QgsProject::instance()->addMapLayer(pVectorLayer_2);
    QgsProject::instance()->addMapLayer(pVectorLayer_3);
    updateCanvasLayerSet();
    mMapCanvas.zoomToFullExtent();

}

void LayerTreeDemo::updateCanvasLayerSet()
{
    mMapCanvas.setLayers(QgsProject::instance()->layerTreeRoot()->checkedLayers());
    mMapCanvas.refresh();
}


int main(int argc, char *argv[])
{
    QgsApplication app(argc, argv, true);
    QgsProviderRegistry::instance("C:/OSGeo4W64/apps/qgis-ltr/plugins");
    qputenv("GDAL_DATA", "C:/OSGeo4W64/share/gdal");

    // 创建主窗体
    LayerTreeDemo w;
    w.show();

    return app.exec();
}

