#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>


int main(int argc, char *argv[])
{

    // 创建 QgsApplication 实例
    QgsApplication app(argc, argv, true);

    // 设置并检查数据插件目录
    QgsProviderRegistry::instance("C:/OSGeo4W64/apps/qgis-ltr/plugins");

    // 控制台打印已载入的插件目录
    qDebug() << "QGIS data providers loaded:" << QgsProviderRegistry::instance()->providerList() << endl;

    // 设置 GDAL 数据目录环境变量
    qputenv("GDAL_DATA", "C:/OSGeo4W64/share/gdal");

    // 创建 QgsCanvas 画布实例
    QgsMapCanvas c;

    // 从磁盘 .shp 文件创建矢量图层
    QgsVectorLayer* pVectorLayer = new QgsVectorLayer(u8"C:/Work/nobleprog/data/shp/全国县级边界shp低分辨率/gadm36_CHN_2.shp", u8"市级行政区");

    // 确认图层是否创建成功
    qDebug() << "Is layer valid:" << pVectorLayer->isValid();

    // 将图层添加到画布上
    c.setLayers(QList<QgsMapLayer*>() << pVectorLayer);

    // 设置画布窗体标题并显示画布
    // 画布本身是 QWidget 的子类，因此可以承担 QWidget 的所有操作
    c.setWindowTitle(u8"QGIS 二次开发：画布");
    c.show();

    // 缩放到图层的空间范围
    c.zoomToFullExtent();

    // 启动 QgsApplication 实例
    return app.exec();

}
