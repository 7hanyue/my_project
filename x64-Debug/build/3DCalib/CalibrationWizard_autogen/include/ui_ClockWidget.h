/********************************************************************************
** Form generated from reading UI file 'ClockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWIDGET_H
#define UI_CLOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockWidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpxRadius;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpxx;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpxy;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *doubleSpxZstep;
    QPushButton *btnApply;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnStartMark;
    QSpacerItem *verticalSpacer;
    QPushButton *btnStopMark;
    QPushButton *btnAddCalibData;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QSpinBox *spinZnumberOfLayers;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpxZphysicalValue;
    QGroupBox *groupBox_3;
    QTableWidget *tablew3DCalibData;
    QPushButton *btnSaveCalibData;
    QGroupBox *groupBox_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnF3Param;
    QPushButton *btnMarkParam;

    void setupUi(QWidget *ClockWidget)
    {
        if (ClockWidget->objectName().isEmpty())
            ClockWidget->setObjectName(QString::fromUtf8("ClockWidget"));
        ClockWidget->resize(973, 657);
        groupBox = new QGroupBox(ClockWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 460, 211, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 201, 139));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        doubleSpxRadius = new QDoubleSpinBox(layoutWidget);
        doubleSpxRadius->setObjectName(QString::fromUtf8("doubleSpxRadius"));
        doubleSpxRadius->setMinimum(1.000000000000000);
        doubleSpxRadius->setValue(10.000000000000000);

        horizontalLayout->addWidget(doubleSpxRadius);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        doubleSpxx = new QDoubleSpinBox(layoutWidget);
        doubleSpxx->setObjectName(QString::fromUtf8("doubleSpxx"));
        doubleSpxx->setMinimum(0.000000000000000);
        doubleSpxx->setMaximum(200.000000000000000);
        doubleSpxx->setValue(50.000000000000000);

        horizontalLayout_2->addWidget(doubleSpxx);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        doubleSpxy = new QDoubleSpinBox(layoutWidget);
        doubleSpxy->setObjectName(QString::fromUtf8("doubleSpxy"));
        doubleSpxy->setMinimum(0.000000000000000);
        doubleSpxy->setMaximum(200.000000000000000);
        doubleSpxy->setValue(50.000000000000000);

        horizontalLayout_3->addWidget(doubleSpxy);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        doubleSpxZstep = new QDoubleSpinBox(layoutWidget);
        doubleSpxZstep->setObjectName(QString::fromUtf8("doubleSpxZstep"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpxZstep->sizePolicy().hasHeightForWidth());
        doubleSpxZstep->setSizePolicy(sizePolicy);
        doubleSpxZstep->setMinimum(-100.000000000000000);
        doubleSpxZstep->setMaximum(100.000000000000000);
        doubleSpxZstep->setValue(0.500000000000000);

        horizontalLayout_4->addWidget(doubleSpxZstep);


        verticalLayout->addLayout(horizontalLayout_4);

        btnApply = new QPushButton(groupBox);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));
        btnApply->setGeometry(QRect(120, 170, 91, 21));
        layoutWidget1 = new QWidget(ClockWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 570, 101, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnStartMark = new QPushButton(layoutWidget1);
        btnStartMark->setObjectName(QString::fromUtf8("btnStartMark"));

        verticalLayout_2->addWidget(btnStartMark);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        btnStopMark = new QPushButton(layoutWidget1);
        btnStopMark->setObjectName(QString::fromUtf8("btnStopMark"));

        verticalLayout_2->addWidget(btnStopMark);

        btnAddCalibData = new QPushButton(ClockWidget);
        btnAddCalibData->setObjectName(QString::fromUtf8("btnAddCalibData"));
        btnAddCalibData->setGeometry(QRect(230, 430, 101, 24));
        groupBox_2 = new QGroupBox(ClockWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 460, 111, 91));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 101, 51));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        spinZnumberOfLayers = new QSpinBox(layoutWidget2);
        spinZnumberOfLayers->setObjectName(QString::fromUtf8("spinZnumberOfLayers"));
        spinZnumberOfLayers->setValue(3);

        verticalLayout_3->addWidget(spinZnumberOfLayers);

        label_6 = new QLabel(ClockWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 480, 151, 16));
        doubleSpxZphysicalValue = new QDoubleSpinBox(ClockWidget);
        doubleSpxZphysicalValue->setObjectName(QString::fromUtf8("doubleSpxZphysicalValue"));
        doubleSpxZphysicalValue->setGeometry(QRect(350, 500, 121, 24));
        doubleSpxZphysicalValue->setMinimum(-300.000000000000000);
        doubleSpxZphysicalValue->setMaximum(300.000000000000000);
        doubleSpxZphysicalValue->setSingleStep(0.500000000000000);
        groupBox_3 = new QGroupBox(ClockWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(440, 0, 531, 451));
        tablew3DCalibData = new QTableWidget(groupBox_3);
        tablew3DCalibData->setObjectName(QString::fromUtf8("tablew3DCalibData"));
        tablew3DCalibData->setGeometry(QRect(10, 20, 521, 401));
        btnSaveCalibData = new QPushButton(groupBox_3);
        btnSaveCalibData->setObjectName(QString::fromUtf8("btnSaveCalibData"));
        btnSaveCalibData->setGeometry(QRect(440, 420, 89, 24));
        groupBox_4 = new QGroupBox(ClockWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(220, 560, 111, 91));
        widget = new QWidget(groupBox_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 101, 57));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnF3Param = new QPushButton(widget);
        btnF3Param->setObjectName(QString::fromUtf8("btnF3Param"));

        verticalLayout_4->addWidget(btnF3Param);

        btnMarkParam = new QPushButton(widget);
        btnMarkParam->setObjectName(QString::fromUtf8("btnMarkParam"));

        verticalLayout_4->addWidget(btnMarkParam);


        retranslateUi(ClockWidget);

        QMetaObject::connectSlotsByName(ClockWidget);
    } // setupUi

    void retranslateUi(QWidget *ClockWidget)
    {
        ClockWidget->setWindowTitle(QCoreApplication::translate("ClockWidget", "ClockWidget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ClockWidget", "\345\261\236\346\200\247", nullptr));
        label_2->setText(QCoreApplication::translate("ClockWidget", "\346\227\266\351\222\237\345\215\212\345\276\204", nullptr));
        label_3->setText(QCoreApplication::translate("ClockWidget", "x\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("ClockWidget", "y\345\200\274", nullptr));
        label->setText(QCoreApplication::translate("ClockWidget", "Focal \346\255\245\351\225\277", nullptr));
        btnApply->setText(QCoreApplication::translate("ClockWidget", "\345\272\224\347\224\250", nullptr));
        btnStartMark->setText(QCoreApplication::translate("ClockWidget", "\346\240\207\345\210\273\346\265\213\350\257\225\345\233\276\345\275\242", nullptr));
        btnStopMark->setText(QCoreApplication::translate("ClockWidget", "\345\201\234\346\255\242\346\240\207\345\210\273", nullptr));
        btnAddCalibData->setText(QCoreApplication::translate("ClockWidget", "\346\267\273\345\212\240\346\240\241\346\255\243\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ClockWidget", "GroupBox", nullptr));
        label_5->setText(QCoreApplication::translate("ClockWidget", "z\350\275\264\345\210\206\345\261\202\346\225\260", nullptr));
        label_6->setText(QCoreApplication::translate("ClockWidget", "\346\265\213\350\257\225\347\204\246\350\267\235:\347\220\206\350\256\272\345\200\274(mm)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ClockWidget", "\346\225\260\346\215\256", nullptr));
        btnSaveCalibData->setText(QCoreApplication::translate("ClockWidget", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("ClockWidget", "\350\256\276\347\275\256\345\217\202\346\225\260", nullptr));
        btnF3Param->setText(QCoreApplication::translate("ClockWidget", "F3\345\217\202\346\225\260", nullptr));
        btnMarkParam->setText(QCoreApplication::translate("ClockWidget", "\346\240\207\345\210\273\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWidget: public Ui_ClockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWIDGET_H
