/********************************************************************************
** Form generated from reading UI file 'PostgisDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef POSTGISDEMOUI_H
#define POSTGISDEMOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostgisDemo
{
public:
    QVBoxLayout *lytMain;
    QHBoxLayout *lytTop;
    QPushButton *btnRunStatistics;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDrawRect;
    QPushButton *btnRunClip;

    void setupUi(QWidget *PostgisDemo)
    {
        if (PostgisDemo->objectName().isEmpty())
            PostgisDemo->setObjectName(QStringLiteral("PostgisDemo"));
        PostgisDemo->resize(800, 600);
        lytMain = new QVBoxLayout(PostgisDemo);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytTop = new QHBoxLayout();
        lytTop->setObjectName(QStringLiteral("lytTop"));
        btnRunStatistics = new QPushButton(PostgisDemo);
        btnRunStatistics->setObjectName(QStringLiteral("btnRunStatistics"));

        lytTop->addWidget(btnRunStatistics);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytTop->addItem(horizontalSpacer);

        btnDrawRect = new QPushButton(PostgisDemo);
        btnDrawRect->setObjectName(QStringLiteral("btnDrawRect"));
        btnDrawRect->setCheckable(true);

        lytTop->addWidget(btnDrawRect);

        btnRunClip = new QPushButton(PostgisDemo);
        btnRunClip->setObjectName(QStringLiteral("btnRunClip"));

        lytTop->addWidget(btnRunClip);


        lytMain->addLayout(lytTop);


        retranslateUi(PostgisDemo);

        QMetaObject::connectSlotsByName(PostgisDemo);
    } // setupUi

    void retranslateUi(QWidget *PostgisDemo)
    {
        PostgisDemo->setWindowTitle(QApplication::translate("PostgisDemo", "QGIS \344\272\214\346\254\241\345\274\200\345\217\221\357\274\232PostGIS", nullptr));
        btnRunStatistics->setText(QApplication::translate("PostgisDemo", "\347\273\237\350\256\241\345\220\204\347\234\201\345\216\277\347\272\247\350\241\214\346\224\277\345\214\272\346\225\260\347\233\256", nullptr));
        btnDrawRect->setText(QApplication::translate("PostgisDemo", "\347\273\230\345\210\266\350\243\201\345\210\207\347\237\251\345\275\242", nullptr));
        btnRunClip->setText(QApplication::translate("PostgisDemo", "\346\211\247\350\241\214\350\243\201\345\210\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostgisDemo: public Ui_PostgisDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // POSTGISDEMOUI_H
