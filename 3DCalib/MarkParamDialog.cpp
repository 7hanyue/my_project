#include <string>
#include <iostream>
#include <QMessageBox>
#include "MarkParamDialog.h"
#include "ui_MarkParamDialog.h"

MarkParamDialog::MarkParamDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MarkParamDialog)
{
    ui->setupUi(this);
    LoadLibary1();
}

MarkParamDialog::~MarkParamDialog()
{
    delete ui;
}
void MarkParamDialog::onOpenMarkParamSet()
{
    int a = 0;
    std::cout << a;
    /*if (this != nullptr)
    {
        this->show();
        return;
    }*/
    //this = new MarkParamDialog(_parent);
        

}

void MarkParamDialog::LoadLibary1()
{
    m_hEzdDLL = new QLibrary("Ezcad3Kernel.dll");//加载动态连接库
    m_hEzdDLL->load();
    if (m_hEzdDLL == NULL)
    {
        QMessageBox::information(nullptr, "Information", ("Can not find Ezcad3Kernel.dll!"));
    }
    else
    {
        ez3_Initial = (e3_Initial)m_hEzdDLL->resolve("E3_Initial");
        if (ez3_Initial == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_Initial in Ezcad3Kernel.dll!"));
        }
        ez3_MarkerGetCfgParamInt = (e3_MarkerGetCfgParamInt)m_hEzdDLL->resolve("E3_MarkerGetCfgParamInt");
        if (ez3_MarkerGetCfgParamInt == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerGetCfgParamInt in Ezcad3Kernel.dll!"));
        }
        
        ez3_MarkerSetCfgParamInt = (e3_MarkerSetCfgParamInt)m_hEzdDLL->resolve("E3_MarkerSetCfgParamInt");
        if (ez3_MarkerSetCfgParamInt == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerSetCfgParamInt in Ezcad3Kernel.dll!"));
        }
        ez3_MarkerUpdateParam = (e3_MarkerUpdateParam)m_hEzdDLL->resolve("E3_MarkerUpdateParam");
        if (ez3_MarkerUpdateParam == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerUpdateParam in Ezcad3Kernel.dll!"));
        }
    }
}
