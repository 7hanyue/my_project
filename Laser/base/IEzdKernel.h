#pragma once

#include "EzcadKernel.h"
class IEzdKernel
{
public:
	IEzdKernel() {};
	virtual ~IEzdKernel() = default;
	virtual bool GetConnectStatus()
	{
		return m_bFindCard;
	}
	virtual int Open() = 0;
	virtual void Close() = 0;

	virtual E3_ID GetMarkerFirstValidId() = 0;
	virtual E3_ID CreateEntMgr() = 0;
	virtual int AddLayer() = 0;
	//�õ��������е�ǰ��ID�Ͳ����
	virtual E3_ID GetCurLayerId(E3_ID& curIdLayer, int& layerIndex) = 0;
	//�õ�ָ���������еĲ������͵�ǰ����������
	virtual int GetLayerCount(int& layerCount, int& layerIndex) = 0;
	//���ݲ���ŵõ�ָ����ID
	virtual int GetLayerId(int layerIndex, E3_ID& idLayer) = 0;
	
	//virtual int OpenFileToEntMgr() = 0;
	virtual int SaveEntMgrToFile() = 0;

	virtual int CreatePoints_2(Pt2d* p2d, E3_ID& curEntId) = 0;
	virtual int SetEntityZ(E3_ID m_idCurEnt, double z) = 0;
	//��ȡ���������Ϣ���������ͣ�����ʺţ��������ƣ�����ߴ磬zֵ���꣨Ŀǰֻ��ȡz��ֵ����Aֵ
	virtual int GetEntBaseInfo(E3_ID m_idCurEnt, double& z) = 0;
	 //��ȡ������ͼ�����������
	virtual int GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount) = 0;
	
	//ɾ��ָ������
	virtual int DeleteEnt(E3_ID m_idCurEnt) = 0;
	
	virtual int MarkerDlgSetCfg() = 0;
	//virtual int MarkerGetCfgParamInt() = 0;
	virtual int MarkerSetCfgParamInt(int index, int param) = 0;
	virtual int MarkerUpdateParam(bool isSaveCfg) = 0;

	virtual int SetPenParam(double markSpeed, double powerRatio, double freq, double qPulseWidth, double dPointTime) = 0;
	virtual int GetPenParam(double& dPointTime) = 0;

	virtual int SetPenParamWeldWave2(bool laserContMode) = 0;
	virtual int GetPenParamWeldWave2(BOOL& laserContMode) = 0;
	
	virtual int MarkerMarkEnt2() = 0;
	virtual int MarkerStop() = 0;

	//virtual int CloseMarke() = 0;
	
protected:
	bool m_bFindCard = false;
	E3_ID m_idCard = 0;//�忨ID
	E3_ID m_idEntMgr = 0;//������ID
	E3_ID m_idCurLayer = 0;//��ǰ�������ID
	//E3_ID m_idCurEnt = 0;//����ID
	int nLayerSn;  //ͼ�����
	
	E3_ID* m_idMarkerList;//

	BOOL isModify;  //�Ƿ��޸��豸����(�����ȷ�Ϸ���true); 


};