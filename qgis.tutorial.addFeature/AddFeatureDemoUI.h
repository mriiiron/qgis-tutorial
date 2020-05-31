/********************************************************************************
** Form generated from reading UI file 'AddFeatureDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADDFEATUREDEMOUI_H
#define ADDFEATUREDEMOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFeatureDemo
{
public:
    QVBoxLayout *lytMain;
    QHBoxLayout *lytTop;
    QPushButton *btnStartEditing;
    QPushButton *btnDrawPolygon;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AddFeatureDemo)
    {
        if (AddFeatureDemo->objectName().isEmpty())
            AddFeatureDemo->setObjectName(QStringLiteral("AddFeatureDemo"));
        AddFeatureDemo->resize(800, 600);
        lytMain = new QVBoxLayout(AddFeatureDemo);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytTop = new QHBoxLayout();
        lytTop->setObjectName(QStringLiteral("lytTop"));
        btnStartEditing = new QPushButton(AddFeatureDemo);
        btnStartEditing->setObjectName(QStringLiteral("btnStartEditing"));
        btnStartEditing->setCheckable(true);

        lytTop->addWidget(btnStartEditing);

        btnDrawPolygon = new QPushButton(AddFeatureDemo);
        btnDrawPolygon->setObjectName(QStringLiteral("btnDrawPolygon"));
        btnDrawPolygon->setEnabled(false);
        btnDrawPolygon->setCheckable(true);

        lytTop->addWidget(btnDrawPolygon);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytTop->addItem(horizontalSpacer);


        lytMain->addLayout(lytTop);


        retranslateUi(AddFeatureDemo);

        QMetaObject::connectSlotsByName(AddFeatureDemo);
    } // setupUi

    void retranslateUi(QWidget *AddFeatureDemo)
    {
        AddFeatureDemo->setWindowTitle(QApplication::translate("AddFeatureDemo", "QGIS \344\272\214\346\254\241\345\274\200\345\217\221\357\274\232\347\273\230\345\210\266\350\246\201\347\264\240", nullptr));
        btnStartEditing->setText(QApplication::translate("AddFeatureDemo", "\345\274\200\345\247\213\347\274\226\350\276\221", nullptr));
        btnDrawPolygon->setText(QApplication::translate("AddFeatureDemo", "\347\273\230\345\210\266\345\244\232\350\276\271\345\275\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFeatureDemo: public Ui_AddFeatureDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADDFEATUREDEMOUI_H
