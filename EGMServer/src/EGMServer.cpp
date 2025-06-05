#include "EGMServer.h"
#include "./ui_EGMServer.h"
#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
//#include <QString>
#include <QSettings>

#include <QCoreApplication>
#include "ROTFCommonDefinitions.h"
//#include <QMessageBox>
#include "ABBTcpServer.h"

EGMServer::EGMServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EGMServer)
{
    ui->setupUi(this);
    ui->btnStratOrStopListen->setIcon(QIcon("C:/Users/an/Desktop/blue.png"));
    ui->btnStratOrStopListen->setText(tr("开始监听"));

    //获取当前exe的路径
    QString fileName = QCoreApplication::applicationDirPath() + "/Param/RobotCommunication.ini";
    //创建配置目标，输入文件路径，文件格式 ,Qt6 对 IniFormat 的默认编码是 UTF-8
    QSettings *setting = new QSettings(fileName, QSettings::IniFormat);
    //设置文件编码，配置文件中使用中文时，这是必须的，否则乱码
    //setting->setIniCodec("UTF-8"); QT6已经弃用setIniCodec

    if(!QFile::exists(fileName))
    {
        setting->setValue("RobotType", "ABB");
        setting->setValue("TransmitProtocol", "TCP");
        setting->setValue("Port", "3000");
    }
    _InitUIParams();
}

EGMServer::~EGMServer()
{
    _StopListening();
    //这个的用法要看懂
    _futureRes.waitForFinished();

    delete ui;
}

void EGMServer::_InitUIParams()
{   
    //将按钮设置为可勾选状态
    ui->btnStratOrStopListen->setCheckable(true);
    connect(ui->comboRobotType,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,&EGMServer::onChangeRobotType);
   connect(ui->comboTransmitProtocol,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,&EGMServer::onChangeProtocolType);
   ui->comboRobotType->setCurrentIndex(0);
   ui->comboTransmitProtocol->setCurrentIndex(0);
   onChangeRobotType(0);

}

void EGMServer::closeEvent(QCloseEvent *event)
{

}

void EGMServer::accept()
{
    close();
}

void EGMServer::onChangeRobotType(int type)
{
    switch (type)
    {
        case static_cast<int>(RobotType::ABB):

            ui->RobotPort->setText("3000");
            break;
        case static_cast<int>(RobotType::KUKA):
            ui->RobotPort->setText("6008");
            break;
        default:
            break;
    }
    _robotType = type;
    onChangeProtocolType(ui->comboTransmitProtocol->currentIndex());
}


void EGMServer::onChangeProtocolType(int type)
{
    if((static_cast<int>(RobotType::ABB)==_robotType) && (static_cast<int>(TransmitProtocol::TCP))==type)
    {
        //to do暂时先不写其它的


        _serverptr.reset();
        _serverptr = QSharedPointer<ABBTcpServer>(new ABBTcpServer());
        //connect(qobject_cast<ABBTcpServer*>(_serverptr.get()),&ABBTcpServer::sendRealtimeReceivedRobotData,this,&EGMServer::onDisplayRealtimeRobotData);
        //connect(qobject_cast<ABBTcpServer*>(_serverptr.get()),&ABBTcpServer::serverButtonIconStatusUpdate,this,&EGMServer::onUpdateStartOrStopListenBtnIconStatus);
        _transmitProtocolType = type;
    }
    if ((static_cast<int>(RobotType::ABB) == _robotType) && (static_cast<int>(TransmitProtocol::UDP)) == type)
    {
        _serverptr.reset();
        _serverptr = QSharedPointer<ABBTcpServer>(new ABBTcpServer());

        _transmitProtocolType = type;
    }

}


void EGMServer::onDisplayRealtimeRobotData(const QString &data)
{
    ui->RobotReceiveText->append(data); //文本编辑框中添加数据
    ui->RobotReceiveText->moveCursor(QTextCursor::End); //光标移动到文本末尾位置
}

void EGMServer::onUpdateStartOrStopListenBtnIconStatus(bool isEnable)
{
    if(!isEnable)
    {
        ui->btnStratOrStopListen->setIcon(QIcon("C:/Users/an/Desktop/blue.png"));
        ui->btnStratOrStopListen->setText(tr("开始监听"));
    }else {
        ui->btnStratOrStopListen->setIcon(QIcon("C:/Users/an/Desktop/red.png"));
        ui->btnStratOrStopListen->setText(tr("停止监听"));
    }
}


void EGMServer::on_btnStratOrStopListen_clicked()
{
    if (GlobalVar::ServerBtnStatus == false && _futureRes.isFinished())
    {
        GlobalVar::RobotPort = ui->RobotPort->text().toInt();
        if (_serverptr == nullptr)
            return;
        bool rtn = _serverptr->StartListening(GlobalVar::RobotPort);
        if (!rtn)
        {
            qDebug() << "Failed to start server:" ; //可以使用下log库，生成log文件，暂时不写 todo
            return;
        }
        GlobalVar::ServerBtnStatus = true;
        onUpdateStartOrStopListenBtnIconStatus(GlobalVar::ServerBtnStatus);
    }
    else
    {
        if (_serverptr == nullptr)
            return;
        _serverptr->StopListening();
        GlobalVar::ServerBtnStatus = false;
        onUpdateStartOrStopListenBtnIconStatus(GlobalVar::ServerBtnStatus);

    }
}


void EGMServer::on_btnSaveData_clicked()
{
    QFileDialog dlg(this);

    //获取内容的保存路径
    QString fileName = dlg.getSaveFileName(this,tr("Save As"),GetName_TimeData(),tr("Text File(*.txt)"));


}

void EGMServer::on_btnClearData_clicked()
{
    ui->RobotReceiveText->clear();

}

void EGMServer::_StopListening()
{

    ui->btnStratOrStopListen->setText(tr("停止监听"));
}
int EGMServer::GetRobotType() const
{
    return _robotType;
}
int EGMServer::GetProtocolType() const
{
    return _transmitProtocolType;
}

QString EGMServer::GetName_TimeData()
{
    // 获取系统当前时间
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // 输出当前时间
    QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString FileSavePath;
    FileSavePath = currentTime + ".txt";
    return "RobotRecord" + FileSavePath;

}




