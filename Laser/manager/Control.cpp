#include "Control.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
//#include "Worker.h"
//#include "Logger.h"
//#include <spdlog/spdlog.h>
#define QStringToTCHAR(x)     (wchar_t*) x.utf16()

Control::Control(QObject* parent)  
    :QObject{ parent }                
{
#ifdef dynamicEzcad
    ezcad = std::shared_ptr<DynamicEzcad3>(new DynamicEzcad3());
#else
    ezcad;

#endif

}
Control::~Control()
{
}
void Control::Init()
{
    auto rtn = ezcad->Open();
    //Logger::GetInstance().GetLogger()->info("初始化结果：" + std::to_string(rtn));
    ezcad->GetMarkerFirstValidId();
    ezcad->CreateEntMgr();
    ezcad->AddLayer();
    ezcad->GetCurLayerId(_idCurLayer, _curLayerIndex);
    //return rtn;
}
void Control::AfterInit()
{
    int a = 0;
    //worker = QSharedPointer<Worker>(new Worker(funcs));
    ////worker = new Worker(funcs);
    //worker->moveToThread(&workerthread);
    //connect(this, &Control::SignalMark, worker.get(), &Worker::doMark);
    ////connect(this, &Control::SignalMark, worker, &Worker::doMark);
    //
    //workerthread.start();
    /*moveToThread 方法，是把我们需要的工作全部封装在一个类中(此代码中就是Worker类），
    将每个任务定义为一个槽函数，再建立触发这些槽函数的信号，然后连接信号和槽
    最后调用 moveToThread 方法将这个类交给一个 QThread 对象，
    再调用 QThread 的 start() 函数使其全权处理事件循环。
    任何时候我们需要让子线程执行某个任务，只需要发出对应的信号就可以*/

}
int Control::StartMark()
{
    // _mark(0);
    int err = ezcad->MarkerMarkEnt2();
    return err;
    int workType = 0;

    emit SignalMark(workType);
}
void Control::StartRedMark()
{
    int workType = 1;

    emit SignalMark(workType);
}
void Control::StopMark()
{
    ezcad->MarkerStop();
 
   
}
void Control::LoadFile(QString filename)
{
    int a = 0;
}
void Control::SaveFile()
{
    ezcad->SaveEntMgrToFile();
}
void Control::CreatPoints(Pt2d* p2d, E3_ID& CurEntId)
{
    ezcad->CreatePoints_2(p2d, CurEntId);
}
void Control::SetEntZ(E3_ID CurEntId, double z)
{
    ezcad->SetEntityZ(CurEntId, z);
}
void Control::GetEntInfo(E3_ID CurEntId, double& z)
{
    ezcad->GetEntBaseInfo(CurEntId, z);
}
void Control::GetCurLayerIdAndLayerIndex(E3_ID& curIdLayer, int& layerIndex)
{
    ezcad->GetCurLayerId(curIdLayer, layerIndex);
}
void Control::GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount)
{
    ezcad->GetEntCountInLayer(m_idCurLayer, entCount);
}

void Control::GetLayerCountAndCurlaserIndex(int& layerCount,
    int& nCurLayer)
{
    ezcad->GetLayerCount(layerCount, nCurLayer);
}
void Control::GetLayerId(int layerIndex, E3_ID& idLayer)
{
    ezcad->GetLayerId(layerIndex, idLayer);

}

void Control::DeleteEnt(E3_ID CurEntId)
{
    ezcad->DeleteEnt(CurEntId);
}

void Control::OpenF3()
{
    ezcad->MarkerDlgSetCfg();
}
void Control::SetF3ParamInt(int index, int param)
{
    ezcad->MarkerSetCfgParamInt(index, param);
}
void Control::UpdateF3Param(bool isSaveCfg)
{
    ezcad->MarkerUpdateParam(isSaveCfg);
}

void Control::SetPenGraftParam(double markSpeed, double powerRatio, double freq, double qPulseWidth, double dPointTime)
{
    ezcad->SetPenParam(markSpeed, powerRatio, freq, qPulseWidth, dPointTime);
}
void Control::GetPenGraftParam(double& dPointTime)
{
    ezcad->GetPenParam(dPointTime);
}

void Control::SetPenGraftParamWeldWave2(bool laserContMode)
{
    ezcad->SetPenParamWeldWave2(laserContMode);
    qDebug() << "laserContMode" << laserContMode;
}
void Control::GetPenGraftParamWeldWave2(BOOL& laserContMode)
{
    ezcad->GetPenParamWeldWave2(laserContMode);
}

void Control::GetEntPreviveImage()
{
    int a = 0;

}
void Control::WeldTimeUpdata() 
{
    float weldTime = 0;
    //库里面暂时没有获取焊接时间的接口，先不实现
    emit SignalUpdataWeldTime(weldTime);
}


void Control::LoadLibary1()
{
    int a = 0;

}