#ifndef EGMSERVER_H
#define EGMSERVER_H

#include <QDialog>
#include <QCloseEvent>
#include <QtConcurrent/qtconcurrentrun.h>


#include "globalvar.h"
#include "EGMServerConfig.h"
#include "IRobotServer.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class EGMServer; }
//QT_END_NAMESPACE

class EGMServerExport EGMServer : public QDialog
{
    Q_OBJECT

public:
    EGMServer(QWidget *parent = nullptr);
    ~EGMServer();
    int GetRobotType() const;
    int GetProtocolType() const;

    void closeEvent(QCloseEvent *event) override;
    void accept() override;
    QString GetName_TimeData();

private:
    //初始化ui界面的，因为在qt creator中绘制控件的时候填写了对应值，故不再实现一部分功能
    void _InitUIParams();

    void _StopListening();

private slots:


    void onChangeRobotType(int type);
    void onChangeProtocolType(int type);

    void onDisplayRealtimeRobotData(const QString &data);
    void onUpdateStartOrStopListenBtnIconStatus(bool isEnable);

    void on_btnStratOrStopListen_clicked();

    void on_btnSaveData_clicked();

    void on_btnClearData_clicked();


private:
    QSharedPointer<IRobotServer> _serverptr{ nullptr };
    QFuture<void> _futureRes;

    Ui::EGMServer *ui;
    int _robotType{0};
    int _transmitProtocolType{0};

};
#endif // EGMSERVER_H
