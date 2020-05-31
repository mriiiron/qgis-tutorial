#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsattributetablemodel.h>
#include <qgsattributetablefiltermodel.h>
#include <qgsattributetableview.h>

#include <QMessageBox>

#include "FeatureFilterDemoUI.h"


class FeatureFilterDemo : public QWidget
{

public:

	FeatureFilterDemo(QWidget * parent = 0);

private:

	Ui::FeatureFilterDemo ui;

	QgsMapCanvas mCanvas;
	QgsVectorLayer* mpVectorLayer = nullptr;
	QgsVectorLayerCache* mpVectorLayerCache = nullptr;
	QgsAttributeTableModel* mpAttrTableModel = nullptr;
	QgsAttributeTableFilterModel* mpAttrTableFilterModel = nullptr;

	void onOpenAttributeTableButtonClicked();
	void onApplyWhereClauseButtonClicked();

};

