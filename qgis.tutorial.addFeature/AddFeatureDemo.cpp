#include "AddFeatureDemo.h"


AddFeatureDemo::AddFeatureDemo(QWidget * parent) :
	QWidget(parent),
	mCanvas(this)
{
	ui.setupUi(this);
	ui.lytMain->addWidget(&mCanvas);
	
	// 创建临时面 (Polygon) 图层，使用坐标系 EPSG:4326 (WGS 84)
	mpStratchLayer = new QgsVectorLayer("polygon?crs=epsg:4326", u8"临时面图层", "memory");
	mCanvas.setLayers(QList<QgsMapLayer*>() << mpStratchLayer);

	// 将临时图层添加到画布，并将画布缩放到 WGS 84 坐标系的边界范围
	mCanvas.setCurrentLayer(mpStratchLayer);
	mCanvas.setExtent(QgsCoordinateReferenceSystem("EPSG:4326").bounds());

	// 创建“绘制多边形”地图工具
	mpToolAddPolygon = new AddPolygonTool(&mCanvas);

	// “开始编辑”按钮
	QObject::connect(ui.btnStartEditing, &QPushButton::toggled, this, &AddFeatureDemo::onStartEditingButtonToggled);
	
	// “绘制多边形”按钮
	QObject::connect(ui.btnDrawPolygon, &QPushButton::toggled, this, &AddFeatureDemo::onDrawPolygonButtonToggled);

}

void AddFeatureDemo::onStartEditingButtonToggled(bool isChecked)
{
	if (isChecked)
	{
		mpStratchLayer->startEditing();
		ui.btnDrawPolygon->setEnabled(true);
	}
	else
	{
		mpStratchLayer->commitChanges();
		ui.btnDrawPolygon->setChecked(false);
		ui.btnDrawPolygon->setEnabled(false);
	}
}

void AddFeatureDemo::onDrawPolygonButtonToggled(bool isChecked)
{
	if (isChecked)
	{
		mCanvas.setMapTool(mpToolAddPolygon);
	}
	else
	{
		mpToolAddPolygon->clearRubberBand();
		mCanvas.unsetMapTool(mpToolAddPolygon);
	}
}
