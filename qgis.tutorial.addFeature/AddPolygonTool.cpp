#include "AddPolygonTool.h"


AddPolygonTool::AddPolygonTool(QgsMapCanvas * pMapCanvas) :
	QgsMapToolEdit(pMapCanvas),
	mIsDrawing(false)
{}

void AddPolygonTool::canvasMoveEvent(QgsMapMouseEvent * e)
{
	if (!mpRubberBand || !mIsDrawing)
	{
		return;
	}
	mpRubberBand->movePoint(e->mapPoint());
}

void AddPolygonTool::canvasPressEvent(QgsMapMouseEvent * e)
{

	// 若当前 RubberBand 为空，则创建
	if (!mpRubberBand)
	{
		mpRubberBand = createRubberBand(QgsWkbTypes::GeometryType::PolygonGeometry);
	}

	// 左键按下
	if (e->button() == Qt::MouseButton::LeftButton)
	{
		mIsDrawing = true;
		mpRubberBand->addPoint(e->mapPoint());
	}

	// 右键按下
	else if (e->button() == Qt::MouseButton::RightButton)
	{

		// 停止绘制
		mIsDrawing = false;

		// 若顶点数不小于 3，则创建新的 QgsFeature，加入图层中
		if (mpRubberBand->numberOfVertices() >= 3)
		{
			QgsFeature f;
			f.setGeometry(mpRubberBand->asGeometry());
			currentVectorLayer()->addFeature(f);
			canvas()->refresh();
		}

		// 删除当前 RubberBand
		clearRubberBand();

	}

}

void AddPolygonTool::clearRubberBand()
{
	if (!mpRubberBand)
	{
		return;
	}
	delete mpRubberBand;
	mpRubberBand = nullptr;
}
