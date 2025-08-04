#ifndef POSITIONDATUMSDIALOG_H
#define POSITIONDATUMSDIALOG_H
#include "PositionDatumsParam.h"
#include <QDialog>
#include <QButtonGroup>
namespace Ui {
class PositionDatumsDialog;
}

class __declspec(dllexport) PositionDatumsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositionDatumsDialog(QWidget *parent = nullptr);
    ~PositionDatumsDialog();

public:
    void Init();
    void Ok();
    void Cancel();

private:
    std::shared_ptr<PositionDatumsParam> _positionDatumsParam;
    QButtonGroup* btnGroup;
private:
    Ui::PositionDatumsDialog *ui;
};

#endif // POSITIONDATUMSDIALOG_H
