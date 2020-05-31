#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgsmaptooledit.h>

#include <QMessageBox>

#include "AddPolygonTool.h"

#include "AddFeatureDemoUI.h"


class AddFeatureDemo : public QWidget
{

public:

	AddFeatureDemo(QWidget * parent = 0);

private:

	Ui::AddFeatureDemo ui;

	QgsMapCanvas mCanvas;
	QgsVectorLayer* mpStratchLayer = nullptr;
	AddPolygonTool* mpToolAddPolygon = nullptr;

	void onStartEditingButtonToggled(bool isChecked);
	void onDrawPolygonButtonToggled(bool isChecked);

};