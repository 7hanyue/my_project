/********************************************************************************
** Form generated from reading UI file 'MarkParamDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKPARAMDIALOG_H
#define UI_MARKPARAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MarkParamDialog
{
public:
    QLabel *label;
    QDoubleSpinBox *doubleSpxMarkSpeed;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpxCenterPower;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpxPointMarkTime;
    QPushButton *btnSavePenParam;
    QLabel *label_4;
    QComboBox *comboContinued;

    void setupUi(QDialog *MarkParamDialog)
    {
        if (MarkParamDialog->objectName().isEmpty())
            MarkParamDialog->setObjectName(QString::fromUtf8("MarkParamDialog"));
        MarkParamDialog->resize(574, 600);
        label = new QLabel(MarkParamDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 111, 16));
        doubleSpxMarkSpeed = new QDoubleSpinBox(MarkParamDialog);
        doubleSpxMarkSpeed->setObjectName(QString::fromUtf8("doubleSpxMarkSpeed"));
        doubleSpxMarkSpeed->setGeometry(QRect(170, 40, 76, 24));
        doubleSpxMarkSpeed->setMaximum(10000.000000000000000);
        doubleSpxMarkSpeed->setValue(120.000000000000000);
        label_2 = new QLabel(MarkParamDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 91, 16));
        doubleSpxCenterPower = new QDoubleSpinBox(MarkParamDialog);
        doubleSpxCenterPower->setObjectName(QString::fromUtf8("doubleSpxCenterPower"));
        doubleSpxCenterPower->setGeometry(QRect(170, 80, 76, 24));
        doubleSpxCenterPower->setMaximum(100.000000000000000);
        doubleSpxCenterPower->setValue(10.000000000000000);
        label_3 = new QLabel(MarkParamDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 111, 16));
        doubleSpxPointMarkTime = new QDoubleSpinBox(MarkParamDialog);
        doubleSpxPointMarkTime->setObjectName(QString::fromUtf8("doubleSpxPointMarkTime"));
        doubleSpxPointMarkTime->setGeometry(QRect(170, 120, 76, 24));
        doubleSpxPointMarkTime->setMaximum(100000.000000000000000);
        doubleSpxPointMarkTime->setValue(10.000000000000000);
        btnSavePenParam = new QPushButton(MarkParamDialog);
        btnSavePenParam->setObjectName(QString::fromUtf8("btnSavePenParam"));
        btnSavePenParam->setGeometry(QRect(210, 510, 89, 24));
        label_4 = new QLabel(MarkParamDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 180, 131, 16));
        comboContinued = new QComboBox(MarkParamDialog);
        comboContinued->addItem(QString());
        comboContinued->addItem(QString());
        comboContinued->setObjectName(QString::fromUtf8("comboContinued"));
        comboContinued->setGeometry(QRect(170, 180, 76, 23));

        retranslateUi(MarkParamDialog);

        QMetaObject::connectSlotsByName(MarkParamDialog);
    } // setupUi

    void retranslateUi(QDialog *MarkParamDialog)
    {
        MarkParamDialog->setWindowTitle(QCoreApplication::translate("MarkParamDialog", "MarkParamDialog", nullptr));
        label->setText(QCoreApplication::translate("MarkParamDialog", "\346\240\207\345\210\273\351\200\237\345\272\246(mm/s)", nullptr));
        label_2->setText(QCoreApplication::translate("MarkParamDialog", "\346\277\200\345\205\211\345\212\237\347\216\207(%)", nullptr));
        label_3->setText(QCoreApplication::translate("MarkParamDialog", "\346\211\223\347\202\271\346\227\266\351\227\264(ms\357\274\211", nullptr));
        btnSavePenParam->setText(QCoreApplication::translate("MarkParamDialog", "\344\277\235\345\255\230", nullptr));
        label_4->setText(QCoreApplication::translate("MarkParamDialog", "\350\277\236\347\273\255\346\250\241\345\274\217(cw/qcw)", nullptr));
        comboContinued->setItemText(0, QCoreApplication::translate("MarkParamDialog", "\346\230\257", nullptr));
        comboContinued->setItemText(1, QCoreApplication::translate("MarkParamDialog", "\345\220\246", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MarkParamDialog: public Ui_MarkParamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKPARAMDIALOG_H
