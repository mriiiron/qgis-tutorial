#include "AddFeatureDemo.h"


int main(int argc, char *argv[])
{
	QgsApplication app(argc, argv, true);
	QgsProviderRegistry::instance("C:/OSGeo4W64/apps/qgis-ltr/plugins");
	qputenv("GDAL_DATA", "C:/OSGeo4W64/share/gdal");
	AddFeatureDemo w;
	w.show();
	return app.exec();
}
