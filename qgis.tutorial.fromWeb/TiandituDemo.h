#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsrasterlayer.h>
#include <qgsproject.h>

#include <qgslayertree.h>

#include <QMessageBox>

#include "TiandituDemoUI.h"


class TiandituDemo : public QWidget
{

public:

    TiandituDemo(QWidget * parent = 0);

private:

    Ui::TiandituDemo ui;

    QgsMapCanvas mCanvas;
    QString mTdtUrlImg, mTdtUrlImgAnno, mTdtUrlVec, mTdtUrlVecAnno;
    QgsRasterLayer* mpBaseMapLayerImg = nullptr;
    QgsRasterLayer* mpBaseMapAnnotationLayerImg = nullptr;
    QgsRasterLayer* mpBaseMapLayerVec = nullptr;
    QgsRasterLayer* mpBaseMapAnnotationLayerVec = nullptr;

    void onDataSelected(bool isChecked);

};

