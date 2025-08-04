#include <string>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "MarkParamDialog.h"
#include "ui_MarkParamDialog.h"
#include "Control.h"

MarkParamDialog::MarkParamDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MarkParamDialog)
{
    ui->setupUi(this);
    UiInit();
}

MarkParamDialog::~MarkParamDialog()
{
    delete ui;
}


void MarkParamDialog::UiInit()
{
    
    //Control::get_instance()->GetPenGraftParam();
    connect(ui->btnSavePenParam, &QPushButton::clicked, this, &MarkParamDialog::onSaveMarkParamSet);
    
}

void MarkParamDialog::onSaveMarkParamSet()
{
    //int laserType;
    //Control::get_instance()->SetF3ParamInt(6, laserType);
    //Control::get_instance()->UpdateF3Param(true);
    double speed = ui->doubleSpxMarkSpeed->value();
    double centerPower = ui->doubleSpxCenterPower->value();
    double pointTime = ui->doubleSpxPointMarkTime->value();
    Control::get_instance()->SetPenGraftParam(speed, centerPower, 2000, 0.2, pointTime);
    int indexNumber = ui->comboContinued->currentIndex();
    if (indexNumber == 0)
        laserContMode = true;
    if (indexNumber == 1)
        laserContMode = false;
    Control::get_instance()->SetPenGraftParamWeldWave2(laserContMode);
    //Control::get_instance()->GetPenGraftParamWeldWave2();
   this->setVisible(false);
    
    //qDebug() << "speed" << speed;


}
