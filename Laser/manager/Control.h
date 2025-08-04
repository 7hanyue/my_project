#ifndef CONTROL_H
#define CONTROL_H

//#include <QObject>

//#include <QLibrary>
#include <QThread>
#include <memory>
#include <QSharedPointer>
#include "DynamicEzcad3.h"
//class Worker;
#define dynamicEzcad

class __declspec(dllexport) Control : public QObject
{
    Q_OBJECT
public:
    explicit Control(QObject* parent = nullptr);
    ~Control();
public:
    static Control* get_instance()
    {
        static Control instance;
        return &instance;
    }
public:
    //void UiInit();
    void Init();
    void AfterInit();
    //void Close();
    void LoadFile(QString filename);
    void SaveFile();
    void OpenF3();
    void SetF3ParamInt(int index, int param);
    void UpdateF3Param(bool isSaveCfg);


    void SetPenGraftParam(double markSpeed, double powerRatio, double freq, double qPulseWidth, double dPointTime);
    void GetPenGraftParam(double& dPointTime);
    void SetPenGraftParamWeldWave2(bool laserContMode);
    void GetPenGraftParamWeldWave2(BOOL& laserContMode);
    
    void CreatPoints(Pt2d* p2d, E3_ID& CurEntId);
    void SetEntZ(E3_ID CurEntId, double z);
    void GetEntInfo(E3_ID CurEntId, double& z);
    void GetCurLayerIdAndLayerIndex(E3_ID& curIdLayer, int& layerIndex);
    void GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount);
    //指定管理器中的层总数和当前操作层的序号
    void GetLayerCountAndCurlaserIndex(int& layerCount,
        int& nCurLayer
    );
    void GetLayerId(int layerIndex, E3_ID& idLayer);
    void DeleteEnt(E3_ID CurEntId);

    void GetEntPreviveImage();
    int StartMark();
    void StartRedMark();
    void StopMark();
    void WeldTimeUpdata();
    
    void LoadLibary1();
private:
    int rtnLoad = -1;
    unsigned char* imagData = nullptr;
    int imagWidth = 0;
    int imagHeight = 0;
    int imagChannels = 0;
    int imagStep = 0;
private:


    std::shared_ptr<IEzdKernel> ezcad;

    E3_ID _idCurLayer = 0;//当前操作层的ID
    int _curLayerIndex = 0;//当前操作层的序号
    //QLibrary* m_hEzdDLL = nullptr;  
    //QSharedPointer<Worker> worker ;
    //Worker* worker = nullptr;
    //LibraryFunctions funcs; // 结构体保存函数指针
    QThread workerthread;

signals:
    void SignalMark(int workType);
    void SignalUpdataGraphicsView(unsigned char* imagData, int imagWidth, int imagHeight);
    void SignalUpdataWeldTime(float weldTime);
    void SignalUpadtaGraftParam(const int& markLoop, const double& markSpeed, const double& powerRatio);
    
};
#endif // CONTROL_H