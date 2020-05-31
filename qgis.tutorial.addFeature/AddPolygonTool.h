#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsmaptooledit.h>
#include <qgsmapmouseevent.h>
#include <qgsrubberband.h>
#include <qgsvectorlayer.h>
#include <qgsmapcanvas.h>

#include <QDebug>


class AddPolygonTool : public QgsMapToolEdit
{

public:

	AddPolygonTool(QgsMapCanvas* pMapCanvas);

	// 清除当前的 RubberBand
	void clearRubberBand();

protected:

	// 重写 QgsMapTool 的鼠标移动事件
	void canvasMoveEvent(QgsMapMouseEvent * e) override;

	// 重写 QgsMapTool 的鼠标点击事件
	void canvasPressEvent(QgsMapMouseEvent * e) override;

private:

	// 当前正在工作的 RubberBand
	QgsRubberBand* mpRubberBand = nullptr;

	// 记录是否正在绘制中
	bool mIsDrawing;

};