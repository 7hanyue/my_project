/********************************************************************************
** Form generated from reading UI file 'EGMServer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EGMSERVER_H
#define UI_EGMSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EGMServer
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboRobotType;
    QComboBox *comboTransmitProtocol;
    QTextBrowser *RobotReceiveText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSaveData;
    QPushButton *btnClearData;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *RobotPort;
    QPushButton *btnStratOrStopListen;

    void setupUi(QDialog *EGMServer)
    {
        if (EGMServer->objectName().isEmpty())
            EGMServer->setObjectName(QString::fromUtf8("EGMServer"));
        EGMServer->resize(800, 600);
        groupBox = new QGroupBox(EGMServer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 361, 121));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 35, 101, 24));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 75, 81, 24));
        comboRobotType = new QComboBox(groupBox);
        comboRobotType->addItem(QString());
        comboRobotType->addItem(QString());
        comboRobotType->setObjectName(QString::fromUtf8("comboRobotType"));
        comboRobotType->setGeometry(QRect(160, 35, 181, 27));
        comboRobotType->setFont(font);
        comboRobotType->setEditable(false);
        comboTransmitProtocol = new QComboBox(groupBox);
        comboTransmitProtocol->addItem(QString());
        comboTransmitProtocol->addItem(QString());
        comboTransmitProtocol->setObjectName(QString::fromUtf8("comboTransmitProtocol"));
        comboTransmitProtocol->setGeometry(QRect(160, 75, 181, 27));
        RobotReceiveText = new QTextBrowser(EGMServer);
        RobotReceiveText->setObjectName(QString::fromUtf8("RobotReceiveText"));
        RobotReceiveText->setGeometry(QRect(40, 171, 541, 211));
        layoutWidget = new QWidget(EGMServer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(41, 401, 541, 36));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnSaveData = new QPushButton(layoutWidget);
        btnSaveData->setObjectName(QString::fromUtf8("btnSaveData"));
        btnSaveData->setEnabled(true);
        btnSaveData->setFont(font);
        btnSaveData->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(btnSaveData);

        btnClearData = new QPushButton(layoutWidget);
        btnClearData->setObjectName(QString::fromUtf8("btnClearData"));
        btnClearData->setFont(font);
        btnClearData->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(btnClearData);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        RobotPort = new QLineEdit(layoutWidget);
        RobotPort->setObjectName(QString::fromUtf8("RobotPort"));

        horizontalLayout->addWidget(RobotPort);

        btnStratOrStopListen = new QPushButton(layoutWidget);
        btnStratOrStopListen->setObjectName(QString::fromUtf8("btnStratOrStopListen"));
        btnStratOrStopListen->setFont(font);
        btnStratOrStopListen->setIconSize(QSize(20, 20));
        btnStratOrStopListen->setCheckable(false);

        horizontalLayout->addWidget(btnStratOrStopListen);


        horizontalLayout_3->addLayout(horizontalLayout);

        QWidget::setTabOrder(comboRobotType, comboTransmitProtocol);
        QWidget::setTabOrder(comboTransmitProtocol, RobotReceiveText);
        QWidget::setTabOrder(RobotReceiveText, RobotPort);
        QWidget::setTabOrder(RobotPort, btnStratOrStopListen);

        retranslateUi(EGMServer);

        QMetaObject::connectSlotsByName(EGMServer);
    } // setupUi

    void retranslateUi(QDialog *EGMServer)
    {
        EGMServer->setWindowTitle(QCoreApplication::translate("EGMServer", "Robot record", nullptr));
        groupBox->setTitle(QCoreApplication::translate("EGMServer", "\346\234\272\345\231\250\344\272\272\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("EGMServer", "\346\234\272\345\231\250\344\272\272\347\261\273\345\236\213", nullptr));
        label_2->setText(QCoreApplication::translate("EGMServer", "\344\274\240\350\276\223\345\215\217\350\256\256", nullptr));
        comboRobotType->setItemText(0, QCoreApplication::translate("EGMServer", "ABB", nullptr));
        comboRobotType->setItemText(1, QCoreApplication::translate("EGMServer", "KUKA", nullptr));

        comboTransmitProtocol->setItemText(0, QCoreApplication::translate("EGMServer", "Tcp", nullptr));
        comboTransmitProtocol->setItemText(1, QCoreApplication::translate("EGMServer", "Udp", nullptr));

        btnSaveData->setText(QCoreApplication::translate("EGMServer", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        btnClearData->setText(QCoreApplication::translate("EGMServer", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        label_3->setText(QCoreApplication::translate("EGMServer", "\347\253\257\345\217\243\345\217\267", nullptr));
        btnStratOrStopListen->setText(QCoreApplication::translate("EGMServer", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EGMServer: public Ui_EGMServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EGMSERVER_H
