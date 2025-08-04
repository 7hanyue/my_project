#pragma once
#include <QLibrary>
#include "IEzdKernel.h"
struct Pen
{
    int penNo = 0; //要设置的笔号;  
    //QString st = QString::fromStdString("Default");
    TCHAR* strName ; //指定笔号名称   
    int clor = 2; //笔颜色;    
    BOOL disableMark = true; //是否使能笔号; True:关闭不标刻;
    //是否使用默认值.如果使用了默认笔号，那么设置的值全部都仅仅是被保存，但是加工时会自动跳转到默认参数;
    BOOL useDefParam = true;
    int markLoop = 1; //加工次数
    //double markSpeed = 100; //加工速度
    //double powerRatio = 0; //中心功率
    //double powerRatioRing = 0; //环形功率
    double current = 0;  //电流A
    int freq = 2000;  //频率HZ
    double qPulseWidth = 10; //Q脉冲宽度;YAG模式单位=us，光纤模式单位=ns
    int startTC = 0;
    int laserOffTC = 0;
    int endTC = 0;
    int polyTC = 0;
    double jumpSpeed = 2000;
    int jumpMinDelay = 100;
    int jumpMaxDelay = 200;
    double jumpLengthLimit = 10;
    //double dPointTime = 0;
    BOOL spiSpiContinueMode = false; //SPI连续模式   
    int spiWave = 0; //SPI波形选择
    int yagMarkMode = 48; //YAG优化填充模式
    BOOL pulsePointMode = false;//脉冲点模式

    //脉冲点数.这个脉冲点数与打点时间是两个打点模式,一个是设置打一个点需要的时间,打点的脉冲个数是由软硬件自动决定,一个是打一个点指定输出多少个脉冲,人为指定.
    //打点个数是lmc上面的参数, 再dlc上面为了接口一致性进行延续, 当时是应某个客户的要求进行扩展的, 目前普遍应用的是打点时间模式, 同时这两者都是YAG激光器的工作设置;
    int nPulseNum = 1; //脉冲点数.
    BOOL enableACCMode = false; //使能加速模式
    double endComp = 0; //末点补偿
    double accDist = 0; //加速距离
    double breakAngle = 89;  //中断角度(89)（弧度值）; 已经被淘汰，暂时保留
    BOOL wobbleMode = false; //抖动模式(false); 已经升级，目前版本不再使用这个参数
    double wobbleDiameter = 1; //抖动直径(1)mm; 已经升级，目前版本不再使用这个参数
    double wobbleDist = 0.5; //抖动距离(0.5)mm; 已经升级，目前版本不再使用这个参数
};
class DynamicEzcad3 : public IEzdKernel
{
public:
	DynamicEzcad3();
    ~DynamicEzcad3();
	int Open() override;
	void Close() override;

    E3_ID GetMarkerFirstValidId() override;
    E3_ID CreateEntMgr() override;
    int AddLayer() override;
    E3_ID GetCurLayerId(E3_ID& curIdLayer, int& layerIndex) override;
    int GetLayerCount(int& layerCount, int& layerIndex) override;
    int GetLayerId(int layerIndex, E3_ID& idLayer) override;

    //int OpenFileToEntMgr() override;
    int SaveEntMgrToFile() override;

    int CreatePoints_2(Pt2d* p2d, E3_ID& curEntId) override;
    int SetEntityZ(E3_ID m_idCurEnt, double z) override;
    int GetEntBaseInfo(E3_ID m_idCurEnt, double& z) override;

    int GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount) override;
    int DeleteEnt(E3_ID m_idCurEnt) override;

    int MarkerDlgSetCfg() override;
    //int MarkerGetCfgParamInt() override;
    int MarkerSetCfgParamInt(int index, int param) override;
    int MarkerUpdateParam(bool isSaveCfg) override;

    int SetPenParam(double markSpeed, double powerRatio, double freq, double qPulseWidth, double dPointTime) override;
    int GetPenParam(double& dPointTime) override;
    int SetPenParamWeldWave2(bool laserContMode) override;
    int GetPenParamWeldWave2(BOOL& laserContMode) override;

    int MarkerMarkEnt2() override;
    int MarkerStop() override;

    //int CloseMarke() override;

private:
    //Pt2d* p2d;
    //Pt3d* p3d;
private:
	void LoadLibary7();
	QLibrary* m_hEzdDLL;

    e3_Initial ez3_Initial;
    e3_Close ez3_Close;

    e3_CreateEntMgr ez3_CreateEntMgr;
    e3_FreeEntMgr ez3_FreeEntMgr;

    e3_MarkerGetFirstValidId ez3_MarkerGetFirstValidId;

    e3_AddLayer ez3_AddLayer;
    e3_GetCurLayerId ez3_GetCurLayerId;
    e3_GetLayerCount ez3_GetLayerCount;
    e3_GetLayerId ez3_GetLayerId;

    e3_OpenFileToEntMgr ez3_OpenFileToEntMgr;
    e3_SaveEntMgrToFile ez3_SaveEntMgrToFile;

    /*e3_SetEntPen ez3_SetEntPen;
    e3_SetEntPen2 ez3_SetEntPen2;
    e3_GetEntPen ez3_GetEntPen;
    e3_DrawEnt2 ez3_DrawEnt2;*/
    
    e3_CreatePoints_2   ez3_CreatePoints_2;
    e3_SetEntityZ ez3_SetEntityZ;
    e3_GetEntBaseInfo ez3_GetEntBaseInfo;

    e3_GetEntCountInLayer ez3_GetEntCountInLayer;

    e3_DeleteEnt ez3_DeleteEnt;

    e3_MarkerDlgSetCfg ez3_MarkerDlgSetCfg;
    e3_MarkerGetCfgParamInt ez3_MarkerGetCfgParamInt;
    e3_MarkerSetCfgParamInt ez3_MarkerSetCfgParamInt;
    e3_MarkerUpdateParam ez3_MarkerUpdateParam;

    e3_SetPenParam ez3_SetPenParam;
    e3_GetPenParam ez3_GetPenParam;
    e3_SetPenParamWeldWave2 ez3_SetPenParamWeldWave2;
    e3_GetPenParamWeldWave2 ez3_GetPenParamWeldWave2;

    e3_MarkerMarkEnt2 ez3_MarkerMarkEnt2;
    e3_MarkerStop ez3_MarkerStop;

    e3_CloseMarker ez3_CloseMarker;
};