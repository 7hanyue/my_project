
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>
#include "DynamicEzcad3.h"

#ifndef UNICODE
#define QStringToTCHAR(x)     (wchar_t*) x.utf16()
#define PQStringToTCHAR(x)    (wchar_t*) x->utf16()
#define TCHARToQString(x)     QString::fromUtf16((x))
#define TCHARToQStringN(x,y)  QString::fromUtf16((x),(y))
#else
#define QStringToTCHAR(x)     x.local8Bit().constData()
#define PQStringToTCHAR(x)    x->local8Bit().constData()
#define TCHARToQString(x)     QString::fromLocal8Bit((x))
#define TCHARToQStringN(x,y)  QString::fromLocal8Bit((x),(y))
#endif
DynamicEzcad3::DynamicEzcad3()
{
	LoadLibary7();
}
DynamicEzcad3::~DynamicEzcad3()
{
    if (m_hEzdDLL != NULL)
    {
        m_hEzdDLL->unload();//�ͷ�DLL���
        m_hEzdDLL = NULL;
    }
}
int DynamicEzcad3::Open()
{
    TCHAR path[_MAX_PATH];
    TCHAR drive[_MAX_DRIVE];
    TCHAR dir[_MAX_DIR];
    TCHAR fname[_MAX_FNAME];
    TCHAR ext[_MAX_EXT];
    //��ȡ��ǰģ�飨��ִ���ļ���������·�����洢�� path��
    GetModuleFileNameW(nullptr, path, _MAX_PATH);

    //�� path �ֽ�Ϊ���������˴���E:)��Ŀ¼(�˴���\ceshi\modbus\bin)���ļ���(�˴���modbustcp)����չ��(�˴���.exe)���ֱ�����Ӧ����
    _wsplitpath_s(path, drive, dir, fname, ext);

    TCHAR strEzCadPath[512];
    //�����������ݸ��Ƶ� strEzCadPath
    wcscpy_s(strEzCadPath, drive);
    //��Ŀ¼����׷�ӵ� strEzCadPath ��
    wcscat_s(strEzCadPath, dir);

    int bTestMode = 0;
    int nErr = ERR_SUCCESS;    //const int ERRID_SUCCESS = 0;  //�ɹ�
    if (ez3_Initial != NULL)
    {
        nErr = ez3_Initial(strEzCadPath, bTestMode);
        if (nErr != ERR_SUCCESS)
        {
            QString strErr = "Initial failed! ErrCode = " + QString::number(nErr);
            QMessageBox::information(nullptr, "Information", strErr);
        }
        else
        {
            m_bFindCard = true;
        }
    }
    return nErr;
}
void DynamicEzcad3::Close()
{
    ez3_Close();
}

E3_ID DynamicEzcad3::GetMarkerFirstValidId()
{
    m_idCard = ez3_MarkerGetFirstValidId();
    return m_idCard;
}

E3_ID DynamicEzcad3::CreateEntMgr()
{
    int nUnitType = 0;
    m_idEntMgr = ez3_CreateEntMgr(nUnitType);
    return m_idEntMgr;
}
int DynamicEzcad3::AddLayer()
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_AddLayer(m_idEntMgr, false, NULL);
    return nErr;
}
E3_ID DynamicEzcad3::GetCurLayerId(E3_ID& curIdLayer, int& layerIndex)
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_GetCurLayerId(m_idEntMgr, m_idCurLayer, nLayerSn);
    return nErr;
}
int DynamicEzcad3::GetLayerCount(int& layerCount, int& layerIndex)
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_GetLayerCount(m_idEntMgr, layerCount, layerIndex);
    return nErr;
}
int DynamicEzcad3::GetLayerId(int layerIndex, E3_ID& idLayer)
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_GetLayerId(m_idEntMgr, layerIndex, idLayer);
    return nErr;
}


int DynamicEzcad3::CreatePoints_2(Pt2d* p2d, E3_ID& curEntId)
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_CreatePoints_2(m_idEntMgr, 0, p2d, 1, true, curEntId);
    return nErr;
}
int DynamicEzcad3::SetEntityZ(E3_ID m_idCurEnt, double z)
{
    int nErr = 0;
    nErr = ez3_SetEntityZ(m_idCurEnt, z, false);
    return nErr;
}
int DynamicEzcad3::GetEntBaseInfo(E3_ID m_idCurEnt, double& z)
{
    int type = 0;
    int pen = 0;
    std::string str;
    Box2d box;
    double a = 0;
    int nErr = 0;

    nErr = ez3_GetEntBaseInfo(m_idCurEnt, type, pen, str, box, z, a);
    return nErr;
}

int DynamicEzcad3::GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount)
{
    int nErr = 0;

    nErr = ez3_GetEntCountInLayer(m_idCurLayer, entCount);
    return nErr;
}

int DynamicEzcad3::DeleteEnt(E3_ID m_idCurEnt)
{
    int nErr = 0;

    nErr = ez3_DeleteEnt(m_idCurEnt);
    return nErr;
}

int DynamicEzcad3::MarkerMarkEnt2()
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_MarkerMarkEnt2(m_idCard, m_idEntMgr, m_idCurLayer, MarkEntMode::StaticMark, 0, 1);
    return nErr;
}
int DynamicEzcad3::MarkerStop()
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_MarkerStop(m_idCard);
    return nErr;
}
int DynamicEzcad3::SaveEntMgrToFile()
{
    int nErr = ERR_SUCCESS;
    std::string st = "";
    QString st2 = QString::fromStdString(st);
    //int rtn = ez3_CreatePoints_2(m_idEntMgr, 0, ptBase, 108, true, m_idCurEnt);
    QString filepath = QCoreApplication::applicationDirPath() + "/test.ez3";

    nErr = ez3_SaveEntMgrToFile(QStringToTCHAR(filepath), m_idEntMgr, false, false, QStringToTCHAR(st2), QStringToTCHAR(st2), QStringToTCHAR(st2));
    return nErr;

}
int DynamicEzcad3::MarkerDlgSetCfg()
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_MarkerDlgSetCfg(m_idCard, isModify);
    return nErr;
}

int DynamicEzcad3::MarkerSetCfgParamInt(int index, int param) 
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_MarkerSetCfgParamInt(m_idCard, index, param);
    return nErr;
}
int DynamicEzcad3::MarkerUpdateParam(bool isSaveCfg)
{
    int nErr = ERR_SUCCESS;
    nErr = ez3_MarkerUpdateParam(m_idCard, isSaveCfg);
    return nErr;
}

int DynamicEzcad3::SetPenParam(double markSpeed, double powerRatio, double freq, double qPulseWidth, double dPointTime)
{
    int penNo = 0; //Ҫ���õıʺ�;  
    QString st = QString::fromStdString("Default");
    TCHAR* strName = QStringToTCHAR(st); //ָ���ʺ�����   
    int clor = 2; //����ɫ;    
    BOOL disableMark = false; //�Ƿ�ʹ�ܱʺ�; True:�رղ����; Ҫ����Ϊfalse,�������ӹ���ʱ��û��Ӧ
    //�Ƿ�ʹ��Ĭ��ֵ.���ʹ����Ĭ�ϱʺţ���ô���õ�ֵȫ���������Ǳ����棬���Ǽӹ�ʱ���Զ���ת��Ĭ�ϲ���;
    BOOL useDefParam = false;
    int markLoop = 1; //�ӹ�����
    //double markSpeed = 100; //�ӹ��ٶ�
    //double powerRatio = 0; //���Ĺ���
    //double powerRatioRing = 0; //���ι���
    double current = 0;  //����A
    //double freq = 2000;  //Ƶ��HZ
    //double qPulseWidth = 0.1; //Q������;YAGģʽ��λ=us������ģʽ��λ=ns
    int startTC = 100;
    int laserOffTC = 100; 
    int endTC = 100;
    int polyTC = 20;
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

    
    //auto rtn = funcs._getPenParam(0, markLoop, markSpeed, powerRatio, powerRatioRing, current, freq, qPulseWidth, startTC, laserOffTC, endTC, polyTC, jumpSpeed, jumpMaxDelay, jumpMinDelay, jumpLengthLimit, dPointTime, nPulseNum);
    //emit SignalUpadtaGraftParam(markLoop, markSpeed, powerRatio);
    int nErr = ERR_SUCCESS;
    nErr = ez3_SetPenParam(m_idEntMgr, penNo, strName, clor, disableMark, useDefParam, markLoop, markSpeed, powerRatio, current, freq, qPulseWidth, startTC, laserOffTC, endTC, polyTC, jumpSpeed, jumpMinDelay, jumpMaxDelay, jumpLengthLimit, dPointTime, spiSpiContinueMode, spiWave, yagMarkMode, pulsePointMode, nPulseNum, enableACCMode, endComp, accDist, breakAngle, wobbleMode, wobbleDiameter, wobbleDist);
    return nErr;
}
int DynamicEzcad3::GetPenParam(/*Pen& pen*/double& dPointTime)
{
    int penNo = 0; //Ҫ���õıʺ�;  
    QString st = QString::fromStdString("Default");
    TCHAR* strName = QStringToTCHAR(st); //ָ���ʺ�����   
    int clor = 2; //����ɫ;    
    BOOL disableMark = false; //�Ƿ�ʹ�ܱʺ�; True:�رղ����;
    //�Ƿ�ʹ��Ĭ��ֵ.���ʹ����Ĭ�ϱʺţ���ô���õ�ֵȫ���������Ǳ����棬���Ǽӹ�ʱ���Զ���ת��Ĭ�ϲ���;
    BOOL useDefParam = false;
    int markLoop = 1; //�ӹ�����
    double markSpeed = 100; //�ӹ��ٶ�
    double powerRatio = 0; //���Ĺ���
    //double powerRatioRing = 0; //���ι���
    double current = 0;  //����A
    double freq = 2000;  //Ƶ��HZ
    double qPulseWidth ; //Q������;YAGģʽ��λ=us������ģʽ��λ=ns
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

    int nErr = ERR_SUCCESS;
    nErr = ez3_GetPenParam(m_idEntMgr, penNo, strName, clor, disableMark, useDefParam, markLoop, markSpeed, powerRatio, current, freq, qPulseWidth, startTC, laserOffTC, endTC, polyTC, jumpSpeed, jumpMinDelay, jumpMaxDelay, jumpLengthLimit, dPointTime, spiSpiContinueMode, spiWave, yagMarkMode, pulsePointMode, nPulseNum, enableACCMode, endComp, accDist, breakAngle, wobbleMode, wobbleDiameter, wobbleDist);
    //qDebug() << "penNo" << penNo;
    return nErr;


}

int DynamicEzcad3::SetPenParamWeldWave2(bool laserContMode)
{
    int penNo = 0; //Ҫ���õıʺ�;  
    //BOOL laserContMode = 0; //�Ƿ�ʹ������ģʽ��trueΪʹ�ܣ�
    BOOL enableWeldWave = true; //�Ƿ�ʹ�ܲ������(trueΪʹ��)
    int maxCount = 64; //��������������; [0, 63] 
    double weldWavePower[64]; //���ʣ�ÿ������[0, 100]��
    double weldWaveWidthMs[64]; //����ms��(64������ֵ�ĺͲ��ɳ����ʲ��������õ�������); [0, 63] ;
    for (int i = 0; i < 64; ++i) {
        weldWavePower[i] = 0;
        weldWaveWidthMs[i] = 0;
    }
    if (ez3_SetPenParamWeldWave2)
    {
        int nErr = ERR_SUCCESS;
        nErr = ez3_SetPenParamWeldWave2(m_idEntMgr, penNo, laserContMode, enableWeldWave, maxCount, weldWavePower, weldWaveWidthMs);
        return nErr;
    }    
}
int DynamicEzcad3::GetPenParamWeldWave2(BOOL& laserContMode)
{
    int penNo = 0; //Ҫ���õıʺ�;  
    //BOOL laserContMode = true; //�Ƿ�ʹ������ģʽ��trueΪʹ�ܣ�
    BOOL enableWeldWave = false; //�Ƿ�ʹ�ܲ������(trueΪʹ��)
    int maxCount = 64; //��������������; [0, 63] 
    double weldWavePower[64]; //���ʣ�ÿ������[0, 100]��
    double weldWaveWidthMs[64]; //����ms��(64������ֵ�ĺͲ��ɳ����ʲ��������õ�������); [0, 63] ;
    for (int i = 0; i < 64; ++i) {
        weldWavePower[i] = 0;
        weldWaveWidthMs[i] = 0;
    }
    if (ez3_GetPenParamWeldWave2)
    {
        int nErr = ERR_SUCCESS;
        nErr = ez3_GetPenParamWeldWave2(m_idEntMgr, penNo, laserContMode, enableWeldWave, maxCount, weldWavePower, weldWaveWidthMs);
        return nErr;
    }
}

void DynamicEzcad3::LoadLibary7()
{
    m_hEzdDLL = new QLibrary("Ezcad3Kernel.dll");//���ض�̬���ӿ�
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
        ez3_Close = (e3_Close)m_hEzdDLL->resolve("E3_Close");
        if (ez3_Close == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_Close in Ezcad3Kernel.dll!"));
        }

        ez3_CreateEntMgr = (e3_CreateEntMgr)m_hEzdDLL->resolve("E3_CreateEntMgr");
        if (ez3_CreateEntMgr == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_CreateEntMgr in Ezcad3Kernel.dll!"));
        }
        ez3_FreeEntMgr = (e3_FreeEntMgr)m_hEzdDLL->resolve("E3_FreeEntMgr");
        if (ez3_FreeEntMgr == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_FreeEntMgr in Ezcad3Kernel.dll!"));
        }

        ez3_MarkerGetFirstValidId = (e3_MarkerGetFirstValidId)m_hEzdDLL->resolve("E3_MarkerGetFirstValidId");
        if (ez3_MarkerGetFirstValidId == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerGetFirstValidId in Ezcad3Kernel.dll!"));
        }

        ez3_AddLayer = (e3_AddLayer)m_hEzdDLL->resolve("E3_AddLayer");
        if (ez3_AddLayer == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_AddLayer in Ezcad3Kernel.dll!"));
        }
        ez3_GetCurLayerId = (e3_GetCurLayerId)m_hEzdDLL->resolve("E3_GetCurLayerId");
        if (ez3_GetCurLayerId == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetCurLayerId in Ezcad3Kernel.dll!"));
        }
        ez3_GetLayerCount = (e3_GetLayerCount)m_hEzdDLL->resolve("E3_GetLayerCount");
        if (ez3_GetLayerCount == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetLayerCount in Ezcad3Kernel.dll!"));
        }
        ez3_GetLayerId = (e3_GetLayerId)m_hEzdDLL->resolve("E3_GetLayerId");
        if (ez3_GetLayerId == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetLayerId in Ezcad3Kernel.dll!"));
        }
        

        ez3_OpenFileToEntMgr = (e3_OpenFileToEntMgr)m_hEzdDLL->resolve("E3_OpenFileToEntMgr");
        if (ez3_OpenFileToEntMgr == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_OpenFileToEntMgr in Ezcad3Kernel.dll!"));
        }
        ez3_SaveEntMgrToFile = (e3_SaveEntMgrToFile)m_hEzdDLL->resolve("E3_SaveEntMgrToFile");
        if (ez3_SaveEntMgrToFile == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_SaveEntMgrToFile in Ezcad3Kernel.dll!"));
        }

        ez3_CreatePoints_2 = (e3_CreatePoints_2)m_hEzdDLL->resolve("E3_CreatePoints_2");
        if (ez3_CreatePoints_2 == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_CreatePoints_2 in Ezcad3Kernel.dll!"));
        }
        ez3_SetEntityZ = (e3_SetEntityZ)m_hEzdDLL->resolve("E3_SetEntityZ");
        if (ez3_SetEntityZ == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_SetEntityZ in Ezcad3Kernel.dll!"));
        }
        ez3_GetEntBaseInfo = (e3_GetEntBaseInfo)m_hEzdDLL->resolve("E3_GetEntBaseInfo");
        if (ez3_GetEntBaseInfo == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetEntBaseInfo in Ezcad3Kernel.dll!"));
        }
        
        ez3_GetEntCountInLayer = (e3_GetEntCountInLayer)m_hEzdDLL->resolve("E3_GetEntCountInLayer");
        if (ez3_GetEntCountInLayer == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetEntCountInLayer in Ezcad3Kernel.dll!"));
        }
        
        ez3_DeleteEnt = (e3_DeleteEnt)m_hEzdDLL->resolve("E3_DeleteEnt");
        if (ez3_DeleteEnt == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_DeleteEnt in Ezcad3Kernel.dll!"));
        }
        
        ez3_MarkerDlgSetCfg = (e3_MarkerDlgSetCfg)m_hEzdDLL->resolve("E3_MarkerDlgSetCfg");
        if (ez3_MarkerDlgSetCfg == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerDlgSetCfg in Ezcad3Kernel.dll!"));
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

        ez3_SetPenParam = (e3_SetPenParam)m_hEzdDLL->resolve("E3_SetPenParam");
        if (ez3_SetPenParam == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_SetPenParam in Ezcad3Kernel.dll!"));
        }
        ez3_GetPenParam = (e3_GetPenParam)m_hEzdDLL->resolve("E3_GetPenParam");
        if (ez3_GetPenParam == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetPenParam in Ezcad3Kernel.dll!"));
        }
        ez3_SetPenParamWeldWave2 = (e3_SetPenParamWeldWave2)m_hEzdDLL->resolve("E3_SetPenParamWeldWave2");
        if (ez3_SetPenParamWeldWave2 == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_SetPenParamWeldWave2 in Ezcad3Kernel.dll!"));
        }
        ez3_GetPenParamWeldWave2 = (e3_GetPenParamWeldWave2)m_hEzdDLL->resolve("E3_GetPenParamWeldWave2");
        if (ez3_GetPenParamWeldWave2 == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_GetPenParamWeldWave2 in Ezcad3Kernel.dll!"));
        }
        

        ez3_MarkerMarkEnt2 = (e3_MarkerMarkEnt2)m_hEzdDLL->resolve("E3_MarkerMarkEnt2");
        if (ez3_MarkerMarkEnt2 == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerMarkEnt2 in Ezcad3Kernel.dll!"));
        }
        ez3_MarkerStop = (e3_MarkerStop)m_hEzdDLL->resolve("E3_MarkerStop");
        if (ez3_MarkerStop == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_MarkerStop in Ezcad3Kernel.dll!"));
        }

        ez3_CloseMarker = (e3_CloseMarker)m_hEzdDLL->resolve("E3_CloseMarker");
        if (ez3_CloseMarker == NULL)
        {
            QMessageBox::information(nullptr, "Information", ("Can not find funtion E3_CloseMarker in Ezcad3Kernel.dll!"));
        }  
    }

}