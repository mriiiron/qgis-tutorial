/********************************************************************************
** Form generated from reading UI file 'FeatureFilterDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FEATUREFILTERDEMOUI_H
#define FEATUREFILTERDEMOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeatureFilterDemo
{
public:
    QVBoxLayout *lytMain;
    QHBoxLayout *lytTop;
    QPushButton *btnOpenAttributeTable;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *leWhereClause;
    QPushButton *btnApplyWhereClause;

    void setupUi(QWidget *FeatureFilterDemo)
    {
        if (FeatureFilterDemo->objectName().isEmpty())
            FeatureFilterDemo->setObjectName(QStringLiteral("FeatureFilterDemo"));
        FeatureFilterDemo->resize(800, 600);
        lytMain = new QVBoxLayout(FeatureFilterDemo);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytTop = new QHBoxLayout();
        lytTop->setObjectName(QStringLiteral("lytTop"));
        btnOpenAttributeTable = new QPushButton(FeatureFilterDemo);
        btnOpenAttributeTable->setObjectName(QStringLiteral("btnOpenAttributeTable"));

        lytTop->addWidget(btnOpenAttributeTable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytTop->addItem(horizontalSpacer);

        label = new QLabel(FeatureFilterDemo);
        label->setObjectName(QStringLiteral("label"));

        lytTop->addWidget(label);

        leWhereClause = new QLineEdit(FeatureFilterDemo);
        leWhereClause->setObjectName(QStringLiteral("leWhereClause"));

        lytTop->addWidget(leWhereClause);

        btnApplyWhereClause = new QPushButton(FeatureFilterDemo);
        btnApplyWhereClause->setObjectName(QStringLiteral("btnApplyWhereClause"));

        lytTop->addWidget(btnApplyWhereClause);


        lytMain->addLayout(lytTop);


        retranslateUi(FeatureFilterDemo);

        QMetaObject::connectSlotsByName(FeatureFilterDemo);
    } // setupUi

    void retranslateUi(QWidget *FeatureFilterDemo)
    {
        FeatureFilterDemo->setWindowTitle(QApplication::translate("FeatureFilterDemo", "QGIS \344\272\214\346\254\241\345\274\200\345\217\221\357\274\232\350\246\201\347\264\240\347\255\233\351\200\211", nullptr));
        btnOpenAttributeTable->setText(QApplication::translate("FeatureFilterDemo", "\346\211\223\345\274\200\345\261\236\346\200\247\350\241\250", nullptr));
        label->setText(QApplication::translate("FeatureFilterDemo", "WHERE \345\255\220\345\217\245\357\274\232", nullptr));
        btnApplyWhereClause->setText(QApplication::translate("FeatureFilterDemo", "\345\272\224\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeatureFilterDemo: public Ui_FeatureFilterDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FEATUREFILTERDEMOUI_H
