/********************************************************************************
** Form generated from reading UI file 'TiandituDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TIANDITUDEMOUI_H
#define TIANDITUDEMOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TiandituDemo
{
public:
    QVBoxLayout *lytMain;
    QHBoxLayout *lytTop;
    QRadioButton *radImg;
    QRadioButton *radVec;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TiandituDemo)
    {
        if (TiandituDemo->objectName().isEmpty())
            TiandituDemo->setObjectName(QStringLiteral("TiandituDemo"));
        TiandituDemo->resize(800, 600);
        lytMain = new QVBoxLayout(TiandituDemo);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytTop = new QHBoxLayout();
        lytTop->setObjectName(QStringLiteral("lytTop"));
        radImg = new QRadioButton(TiandituDemo);
        radImg->setObjectName(QStringLiteral("radImg"));

        lytTop->addWidget(radImg);

        radVec = new QRadioButton(TiandituDemo);
        radVec->setObjectName(QStringLiteral("radVec"));

        lytTop->addWidget(radVec);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytTop->addItem(horizontalSpacer);


        lytMain->addLayout(lytTop);


        retranslateUi(TiandituDemo);

        QMetaObject::connectSlotsByName(TiandituDemo);
    } // setupUi

    void retranslateUi(QWidget *TiandituDemo)
    {
        TiandituDemo->setWindowTitle(QApplication::translate("TiandituDemo", "QGIS \344\272\214\346\254\241\345\274\200\345\217\221\357\274\232\345\212\240\350\275\275\345\244\251\345\234\260\345\233\276\346\225\260\346\215\256", nullptr));
        radImg->setText(QApplication::translate("TiandituDemo", "\345\244\251\345\234\260\345\233\276\345\275\261\345\203\217+\346\263\250\350\256\260", nullptr));
        radVec->setText(QApplication::translate("TiandituDemo", "\345\244\251\345\234\260\345\233\276\350\241\227\351\201\223+\346\263\250\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TiandituDemo: public Ui_TiandituDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TIANDITUDEMOUI_H
