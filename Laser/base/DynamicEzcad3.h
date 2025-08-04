#pragma once
#include <QLibrary>
#include "IEzdKernel.h"
struct Pen
{
    int penNo = 0; //Ҫ���õıʺ�;  
    //QString st = QString::fromStdString("Default");
    TCHAR* strName ; //ָ���ʺ�����   
    int clor = 2; //����ɫ;    
    BOOL disableMark = true; //�Ƿ�ʹ�ܱʺ�; True:�رղ����;
    //�Ƿ�ʹ��Ĭ��ֵ.���ʹ����Ĭ�ϱʺţ���ô���õ�ֵȫ���������Ǳ����棬���Ǽӹ�ʱ���Զ���ת��Ĭ�ϲ���;
    BOOL useDefParam = true;
    int markLoop = 1; //�ӹ�����
    //double markSpeed = 100; //�ӹ��ٶ�
    //double powerRatio = 0; //���Ĺ���
    //double powerRatioRing = 0; //���ι���
    double current = 0;  //����A
    int freq = 2000;  //Ƶ��HZ
    double qPulseWidth = 10; //Q������;YAGģʽ��λ=us������ģʽ��λ=ns
    int startTC = 0;
    int laserOffTC = 0;
    int endTC = 0;
    int polyTC = 0;
    double jumpSpeed = 2000;
    int jumpMinDelay = 100;
    int jumpMaxDelay = 200;
    double jumpLengthLimit = 10;
    //double dPointTime = 0;
    BOOL spiSpiContinueMode = false; //SPI����ģʽ   
    int spiWave = 0; //SPI����ѡ��
    int yagMarkMode = 48; //YAG�Ż����ģʽ
    BOOL pulsePointMode = false;//�����ģʽ

    //�������.��������������ʱ�����������ģʽ,һ�������ô�һ������Ҫ��ʱ��,�����������������Ӳ���Զ�����,һ���Ǵ�һ����ָ��������ٸ�����,��Ϊָ��.
    //��������lmc����Ĳ���, ��dlc����Ϊ�˽ӿ�һ���Խ�������, ��ʱ��Ӧĳ���ͻ���Ҫ�������չ��, Ŀǰ�ձ�Ӧ�õ��Ǵ��ʱ��ģʽ, ͬʱ�����߶���YAG�������Ĺ�������;
    int nPulseNum = 1; //�������.
    BOOL enableACCMode = false; //ʹ�ܼ���ģʽ
    double endComp = 0; //ĩ�㲹��
    double accDist = 0; //���پ���
    double breakAngle = 89;  //�жϽǶ�(89)������ֵ��; �Ѿ�����̭����ʱ����
    BOOL wobbleMode = false; //����ģʽ(false); �Ѿ�������Ŀǰ�汾����ʹ���������
    double wobbleDiameter = 1; //����ֱ��(1)mm; �Ѿ�������Ŀǰ�汾����ʹ���������
    double wobbleDist = 0.5; //��������(0.5)mm; �Ѿ�������Ŀǰ�汾����ʹ���������
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