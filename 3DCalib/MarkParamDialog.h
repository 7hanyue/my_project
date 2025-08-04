#ifndef MARKPARAMDIALOG_H
#define MARKPARAMDIALOG_H

//#include "EzcadKernel.h"
//#include <QLibrary>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MarkParamDialog;
}
QT_END_NAMESPACE

class Control;
class MarkParamDialog : public QDialog
{
    Q_OBJECT

public:
    MarkParamDialog(QWidget *parent = nullptr);
    ~MarkParamDialog();

public slots:
    void onSaveMarkParamSet();

public:
    void UiInit();
    //QLibrary* m_hEzdDLL;
    /*e3_Initial ez3_Initial;
    e3_Close ez3_Close;
    e3_MarkerGetCfgParamInt ez3_MarkerGetCfgParamInt;
    e3_MarkerSetCfgParamInt ez3_MarkerSetCfgParamInt;
    e3_MarkerUpdateParam ez3_MarkerUpdateParam;*/
private:
    bool laserContMode = true; // 0:qcw  1:cw
private:
    Ui::MarkParamDialog *ui;
};
#endif // MARKPARAMDIALOG_H
