#include "PositionDatumsDialog.h"
#include "ui_PositionDatumsDialog.h"
PositionDatumsDialog::PositionDatumsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionDatumsDialog)
{
    ui->setupUi(this);
    _positionDatumsParam = std::make_shared<PositionDatumsParam>("datumParam", "");
    Init();
}

PositionDatumsDialog::~PositionDatumsDialog()
{
    delete ui;
}


void PositionDatumsDialog::Init()
{
    setWindowTitle("选择位置坐标的基准");
    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->chk_top_left, 0);  // id=0
    btnGroup->addButton(ui->chk_top, 1);  // id=1
    btnGroup->addButton(ui->chk_top_right, 2);  // id=2
    btnGroup->addButton(ui->chk_left, 3);  // id=3
    btnGroup->addButton(ui->rbtn_center, 4);  // id=4（中间）
    btnGroup->addButton(ui->chk_right, 5);  // id=5
    btnGroup->addButton(ui->chk_bottom_left, 6);  // id=6
    btnGroup->addButton(ui->chk_bottom, 7);  // id=7
    btnGroup->addButton(ui->chk_bottom_right, 8);  // id=8
    connect(ui->btn_ok, &QPushButton::clicked, this, &PositionDatumsDialog::Ok);
    connect(ui->btn_cancel, &QPushButton::clicked, this, &PositionDatumsDialog::Cancel);
    int referenc = _positionDatumsParam->_location;
    switch (referenc)
    {
        case 0:
            ui->chk_top_left->setChecked(true);
            break;
        case 1:
            ui->chk_top->setChecked(true);
            break;
        case 2:
            ui->chk_top_right->setChecked(true);
            break;
        case 3:
            ui->chk_left->setChecked(true);
            break;
        case 4:
            ui->rbtn_center->setChecked(true);
            break;
        case 5:
            ui->chk_right->setChecked(true);
            break;
        case 6:
            ui->chk_bottom_left->setChecked(true);
            break;
        case 7:
            ui->chk_bottom->setChecked(true);
            break;
        case 8:
            ui->chk_bottom_right->setChecked(true);
            break;
        default:
            ui->rbtn_center->setChecked(true);
            break;
    }


}

void PositionDatumsDialog::Ok()
{
    if (btnGroup->checkedId() != -1) {
        _positionDatumsParam->_location = btnGroup->checkedId();
        _positionDatumsParam->Save();
        accept(); // 关闭对话框并返回Accepted状态
    }
    //_positionDatumsParam
}
void PositionDatumsDialog::Cancel()
{
    reject();  // 标记对话框被取消关闭,关闭对话框
}


