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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MarkParamDialog
{
public:

    void setupUi(QDialog *MarkParamDialog)
    {
        if (MarkParamDialog->objectName().isEmpty())
            MarkParamDialog->setObjectName(QString::fromUtf8("MarkParamDialog"));
        MarkParamDialog->resize(800, 600);

        retranslateUi(MarkParamDialog);

        QMetaObject::connectSlotsByName(MarkParamDialog);
    } // setupUi

    void retranslateUi(QDialog *MarkParamDialog)
    {
        MarkParamDialog->setWindowTitle(QCoreApplication::translate("MarkParamDialog", "MarkParamDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MarkParamDialog: public Ui_MarkParamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKPARAMDIALOG_H
