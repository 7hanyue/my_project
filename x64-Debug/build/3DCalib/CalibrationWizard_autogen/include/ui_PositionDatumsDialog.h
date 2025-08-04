/********************************************************************************
** Form generated from reading UI file 'PositionDatumsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONDATUMSDIALOG_H
#define UI_POSITIONDATUMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PositionDatumsDialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QCheckBox *chk_top_left;
    QCheckBox *chk_top;
    QCheckBox *chk_top_right;
    QCheckBox *chk_left;
    QRadioButton *rbtn_center;
    QCheckBox *chk_right;
    QCheckBox *chk_bottom_left;
    QCheckBox *chk_bottom;
    QCheckBox *chk_bottom_right;

    void setupUi(QDialog *PositionDatumsDialog)
    {
        if (PositionDatumsDialog->objectName().isEmpty())
            PositionDatumsDialog->setObjectName(QString::fromUtf8("PositionDatumsDialog"));
        PositionDatumsDialog->resize(400, 300);
        widget = new QWidget(PositionDatumsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 220, 221, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(13);
        btn_ok->setFont(font);

        horizontalLayout->addWidget(btn_ok);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setWeight(50);
        btn_cancel->setFont(font1);
        btn_cancel->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_cancel);

        widget1 = new QWidget(PositionDatumsDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(70, 50, 141, 121));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        chk_top_left = new QCheckBox(widget1);
        chk_top_left->setObjectName(QString::fromUtf8("chk_top_left"));

        gridLayout->addWidget(chk_top_left, 0, 0, 1, 1);

        chk_top = new QCheckBox(widget1);
        chk_top->setObjectName(QString::fromUtf8("chk_top"));

        gridLayout->addWidget(chk_top, 0, 1, 1, 1);

        chk_top_right = new QCheckBox(widget1);
        chk_top_right->setObjectName(QString::fromUtf8("chk_top_right"));

        gridLayout->addWidget(chk_top_right, 0, 2, 1, 1);

        chk_left = new QCheckBox(widget1);
        chk_left->setObjectName(QString::fromUtf8("chk_left"));

        gridLayout->addWidget(chk_left, 1, 0, 1, 1);

        rbtn_center = new QRadioButton(widget1);
        rbtn_center->setObjectName(QString::fromUtf8("rbtn_center"));

        gridLayout->addWidget(rbtn_center, 1, 1, 1, 1);

        chk_right = new QCheckBox(widget1);
        chk_right->setObjectName(QString::fromUtf8("chk_right"));

        gridLayout->addWidget(chk_right, 1, 2, 1, 1);

        chk_bottom_left = new QCheckBox(widget1);
        chk_bottom_left->setObjectName(QString::fromUtf8("chk_bottom_left"));

        gridLayout->addWidget(chk_bottom_left, 2, 0, 1, 1);

        chk_bottom = new QCheckBox(widget1);
        chk_bottom->setObjectName(QString::fromUtf8("chk_bottom"));

        gridLayout->addWidget(chk_bottom, 2, 1, 1, 1);

        chk_bottom_right = new QCheckBox(widget1);
        chk_bottom_right->setObjectName(QString::fromUtf8("chk_bottom_right"));

        gridLayout->addWidget(chk_bottom_right, 2, 2, 1, 1);


        retranslateUi(PositionDatumsDialog);

        QMetaObject::connectSlotsByName(PositionDatumsDialog);
    } // setupUi

    void retranslateUi(QDialog *PositionDatumsDialog)
    {
        PositionDatumsDialog->setWindowTitle(QCoreApplication::translate("PositionDatumsDialog", "PositionDatumsDialog", nullptr));
        btn_ok->setText(QCoreApplication::translate("PositionDatumsDialog", "\347\241\256\345\256\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("PositionDatumsDialog", "\345\217\226\346\266\210", nullptr));
        chk_top_left->setText(QString());
        chk_top->setText(QString());
        chk_top_right->setText(QString());
        chk_left->setText(QString());
        rbtn_center->setText(QString());
        chk_right->setText(QString());
        chk_bottom_left->setText(QString());
        chk_bottom->setText(QString());
        chk_bottom_right->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PositionDatumsDialog: public Ui_PositionDatumsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONDATUMSDIALOG_H
