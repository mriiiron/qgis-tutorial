#include "FeatureFilterDemo.h"


int main(int argc, char *argv[])
{
	QgsApplication app(argc, argv, true);
	QgsProviderRegistry::instance("C:/OSGeo4W64/apps/qgis-ltr/plugins");
	qputenv("GDAL_DATA", "C:/OSGeo4W64/share/gdal");

	// 创建主窗体
	FeatureFilterDemo w;
	w.show();

	return app.exec();
}

