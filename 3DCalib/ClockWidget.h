#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

//#include "Ezcad3Dll2.h"
//#include "Ezcad3Dll3.h"
#include "EzcadKernel.h"
#include "MarkParamDialog.h"
#include <QLibrary>
#include <QWidget>
#include <QPainter>
#include <QCheckBox>
#include <vector>
#define Startx 80 //x起始像素坐标
#define Starty 80 //y起始像素坐标
#define clockRadius 40 //表盘半径
#define zoomFactor 1.7//表盘距离缩放因子
QT_BEGIN_NAMESPACE
namespace Ui {
class ClockWidget;
}
QT_END_NAMESPACE

class CalibParam;

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();

public:
    void LoadLibary1();
    QLibrary* m_hEzdDLL;
    e3_Initial ez3_Initial;
    e3_Close ez3_Close;

    e3_CreateEntMgr ez3_CreateEntMgr;
    e3_FreeEntMgr ez3_FreeEntMgr;

    e3_MarkerGetFirstValidId ez3_MarkerGetFirstValidId;

    e3_AddLayer ez3_AddLayer;
    e3_GetCurLayerId ez3_GetCurLayerId;
    e3_OpenFileToEntMgr ez3_OpenFileToEntMgr;
    e3_SaveEntMgrToFile ez3_SaveEntMgrToFile;
    e3_SetEntPen ez3_SetEntPen;
    e3_SetEntPen2 ez3_SetEntPen2;
    e3_GetEntPen ez3_GetEntPen;
    e3_DrawEnt2 ez3_DrawEnt2;
    e3_CreatePoints_2   ez3_CreatePoints_2;
    e3_CloseMarker ez3_CloseMarker;
    e3_SetEntityZ ez3_SetEntityZ;
    e3_MarkerDlgSetCfg ez3_MarkerDlgSetCfg;

    e3_MarkerGetCfgParamInt ez3_MarkerGetCfgParamInt;
    e3_MarkerSetCfgParamInt ez3_MarkerSetCfgParamInt;
    e3_MarkerUpdateParam ez3_MarkerUpdateParam;
    /*E3_GetAllFontCount e3_GetAllFontCount;
    E3_GetAllFontRecord e3_GetAllFontRecord;
    E3_MarkerReadPort e3_MarkerReadPort;
    E3_MarkerWritePort e3_MarkerWritePort;
    E3_MarkerGetWritePort e3_MarkerGetWritePort;
    E3_GetEntCountInLayer e3_GetEntCountInLayer;
    E3_FindEntInLayerByIndex e3_FindEntInLayerByIndex;
    E3_GetLayerCount e3_GetLayerCount;
    E3_GetLayerId e3_GetLayerId;
    E3_SetCurLayer e3_SetCurLayer;

    E3_GetEntityRange e3_GetEntityRange;

    E3_CreateLines   e3_CreateLines;
    E3_CreateText e3_CreateText;

    E3_SetPenParam e3_SetPenParam;
    E3_GetPenParam e3_GetPenParam;

    E3_MoveRotateEnt e3_MoveRotateEnt;



    E3_GetMarkerSN e3_GetMarkerSN;
    E3_CloseMarker e3_CloseMarker;*/
    e3_MarkerMarkEnt2 ez3_MarkerMarkEnt2;
    e3_MarkerStop ez3_MarkerStop;

    //E3_ChangeTextById e3_ChangeTextById;
    //E3_ChangeTextByName e3_ChangeTextByName;*/

    E3_ID m_idCurEnt = 0;//对象ID
    int nLayerSn;  //图层序号
    E3_ID m_idCurLayer = 0;//当前操作层的ID
    E3_ID m_idEntMgr = 0;//管理器ID
    E3_ID m_idCard = 0;//板卡ID
    E3_ID* m_idMarkerList;//
    bool m_bFindCard = false;
    BOOL isModify;  //是否修改设备参数(若点击确认返回true); 
    bool Open();

signals:
    void signalUpdataPointsData();
    void signalUpdatataTablewData(int number, int clockNumber);

public slots:
    void onUpdataPointsData();
    void onStartMark();
    void onStopMark();
    void onTaskFinished(int result);
    void onApplyParam();
    void onOpenDlgSetCfg();
    void onUpdataTablewData(int data, int data2);
    void onAddDataToTableWidget();
    void onSaveCalibData();
    void onOpenMarkParamSet();
private:
    std::shared_ptr<CalibParam> _calibParam;
    /*double _clockRadius; //时钟半径(12个点围成的圆的半径）
    double _arrayX;  //阵列长 间距
    double _arrayY;  //阵列宽 间距
    double _zStep;   //振镜z值*/
    QString emptyQstr = QString::fromStdString("");
    MarkParamDialog* markParamDialog = nullptr;

    QWidget* _parent;
    //std::unique_ptr<MarkParamDialog> m_handle;
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event);
private:
    std::vector<QCheckBox*> checkboxes; 
    std::vector<QButtonGroup*> buttonGroups;
    QButtonGroup* group;
    int checkedBoxesNumber = 0;
    Pt2d* ptBase;
    Pt3d* pt3;
    std::vector< Pt3d*> pointsData; //存储未进行3D校正之前的数据
    int lastdata = -1;
    int rowNumber = 0;
private:
    void UiInit();
    void tablewDataInit();
    void initCheckboxes();// 创建并初始化所有Checkbox
    void updateCheckboxPositions();
    void showCheckboxPositions(int cx, int cy);
    void drawBlocks(QPainter *painter,int offsetx, int offsety, int radius,int num);   // 绘制外围方块
    void drawDial(QPainter *painter, int offsetx, int offsety, int radius);     // 绘制表盘
    void drawTicksAndNumbers(QPainter *painter,int mx, int my, int mr); // 绘制刻度和数字

private:
    Ui::ClockWidget *ui;
};
#endif // CLOCKWIDGET_H
