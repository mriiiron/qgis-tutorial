#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgsmaptoolpan.h>
#include <qgsmaptoolemitpoint.h>
#include <qgsmaptoolidentifyfeature.h>
#include <qgshighlight.h>

#include <QMessageBox>

#include "MapToolDemoUI.h"


class MapToolDemo : public QWidget
{

public:
    
    MapToolDemo(QWidget * parent = 0);

private:

    Ui::MapToolsDemo ui;

    QgsMapCanvas mCanvas;
    QgsMapToolPan mToolPan;
    QgsMapToolEmitPoint mToolEmitPoint;
    QgsMapToolIdentifyFeature mToolIdentifyFeature;
    QgsHighlight* mpHighlight = nullptr;

    void onMapToolSelected(bool isChecked);
    void clearHighlight();

};