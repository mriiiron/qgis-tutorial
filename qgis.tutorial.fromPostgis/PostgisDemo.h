#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgsmaptoolextent.h>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMessageBox>

#include "PostgisDemoUI.h"


class PostgisDemo : public QWidget
{

public:

    PostgisDemo(QWidget * parent = 0);

private:

    Ui::PostgisDemo ui;

    QgsMapCanvas mCanvas;
    QgsMapToolExtent mToolDrawRect;
    QgsRubberBand* mpRubberBand = nullptr;

    void onTestStatisticsQueryButtonClicked();
    void onDrawPolygonButtonClicked(bool isChecked);
    void onRunClipButtonClicked();

};

