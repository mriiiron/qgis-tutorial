/********************************************************************************
** Form generated from reading UI file 'MapToolDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAPTOOLDEMOUI_H
#define MAPTOOLDEMOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapToolsDemo
{
public:
    QVBoxLayout *lytMain;
    QHBoxLayout *lytTop;
    QRadioButton *radPan;
    QRadioButton *radEmitPoint;
    QRadioButton *radIdentifyFeature;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MapToolsDemo)
    {
        if (MapToolsDemo->objectName().isEmpty())
            MapToolsDemo->setObjectName(QStringLiteral("MapToolsDemo"));
        MapToolsDemo->resize(800, 600);
        lytMain = new QVBoxLayout(MapToolsDemo);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytTop = new QHBoxLayout();
        lytTop->setObjectName(QStringLiteral("lytTop"));
        radPan = new QRadioButton(MapToolsDemo);
        radPan->setObjectName(QStringLiteral("radPan"));

        lytTop->addWidget(radPan);

        radEmitPoint = new QRadioButton(MapToolsDemo);
        radEmitPoint->setObjectName(QStringLiteral("radEmitPoint"));

        lytTop->addWidget(radEmitPoint);

        radIdentifyFeature = new QRadioButton(MapToolsDemo);
        radIdentifyFeature->setObjectName(QStringLiteral("radIdentifyFeature"));

        lytTop->addWidget(radIdentifyFeature);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytTop->addItem(horizontalSpacer);


        lytMain->addLayout(lytTop);


        retranslateUi(MapToolsDemo);

        QMetaObject::connectSlotsByName(MapToolsDemo);
    } // setupUi

    void retranslateUi(QWidget *MapToolsDemo)
    {
        MapToolsDemo->setWindowTitle(QApplication::translate("MapToolsDemo", "QGIS \344\272\214\346\254\241\345\274\200\345\217\221\357\274\232\345\234\260\345\233\276\345\267\245\345\205\267", nullptr));
        radPan->setText(QApplication::translate("MapToolsDemo", "QgsMapToolPan", nullptr));
        radEmitPoint->setText(QApplication::translate("MapToolsDemo", "QgsMapToolEmitPoint", nullptr));
        radIdentifyFeature->setText(QApplication::translate("MapToolsDemo", "QgsMapToolIdentifyFeature", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapToolsDemo: public Ui_MapToolsDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAPTOOLDEMOUI_H
