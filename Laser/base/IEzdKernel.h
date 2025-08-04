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
	//得到管理器中当前层ID和层序号
	virtual E3_ID GetCurLayerId(E3_ID& curIdLayer, int& layerIndex) = 0;
	//得到指定管理器中的层总数和当前操作层的序号
	virtual int GetLayerCount(int& layerCount, int& layerIndex) = 0;
	//根据层序号得到指定层ID
	virtual int GetLayerId(int layerIndex, E3_ID& idLayer) = 0;
	
	//virtual int OpenFileToEntMgr() = 0;
	virtual int SaveEntMgrToFile() = 0;

	virtual int CreatePoints_2(Pt2d* p2d, E3_ID& curEntId) = 0;
	virtual int SetEntityZ(E3_ID m_idCurEnt, double z) = 0;
	//获取对象基本信息，对象类型，对象笔号，对象名称，对象尺寸，z值坐标（目前只获取z自值），A值
	virtual int GetEntBaseInfo(E3_ID m_idCurEnt, double& z) = 0;
	 //获取给定的图层对象总数量
	virtual int GetEntCountInLayer(E3_ID m_idCurLayer, int& entCount) = 0;
	
	//删除指定对象
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
	E3_ID m_idCard = 0;//板卡ID
	E3_ID m_idEntMgr = 0;//管理器ID
	E3_ID m_idCurLayer = 0;//当前操作层的ID
	//E3_ID m_idCurEnt = 0;//对象ID
	int nLayerSn;  //图层序号
	
	E3_ID* m_idMarkerList;//

	BOOL isModify;  //是否修改设备参数(若点击确认返回true); 


};