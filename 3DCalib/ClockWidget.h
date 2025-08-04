#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

//#include "Ezcad3Dll2.h"
//#include "Ezcad3Dll3.h"
//#include "EzcadKernel.h"

//#include <QLibrary>
#include <QWidget>
#include <QPainter>
#include <QCheckBox>
#include <vector>
#include "PositionDatumsDialog.h"
#include "MarkParamDialog.h"
#include "Control.h"
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

//class EzcadKernel;
class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();

public:
    void LoadLibary();


    //E3_ID m_idCurEnt = 0;//对象ID
    //int nLayerSn;  //图层序号
    //E3_ID m_idCurLayer = 0;//当前操作层的ID
    //E3_ID m_idEntMgr = 0;//管理器ID
    //E3_ID m_idCard = 0;//板卡ID
    //E3_ID* m_idMarkerList;//
    //bool m_bFindCard = false;
    //BOOL isModify;  //是否修改设备参数(若点击确认返回true); 
    //bool Open();

signals:
    void signalUpdataAllPointsData();
    void signalUpdatataSelectedPointData(int number, int clockNumber);

public slots:
    void onUpdataAllPointsData();
    void onStartMark();
    void onStopMark();
    void onTaskFinished(int result);
    void onApplyParam();
    void onOpenDlgSetCfg();
    void onUpdataSelectedPointData(int data, int data2);
    void onAddDataToTableWidget();
    void onSaveCalibData();
    void onOpenMarkParamSet();
    void onOpenPositionDatumsDialog();
    void onSetZBase();
private:
    std::shared_ptr<CalibParam> _calibParam;
    /*double _clockRadius; //时钟半径(12个点围成的圆的半径）
    double _arrayX;  //阵列长 间距
    double _arrayY;  //阵列宽 间距
    double _zStep;   //振镜z值*/
    QString emptyQstr = QString::fromStdString("");
    MarkParamDialog* markParamDialog = nullptr;
    //PositionDatumsDialog* _positionDatumsDialog;
    bool _isClickedApply = false;

    QWidget* _parent;
    //std::unique_ptr<MarkParamDialog> m_handle;
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event);
private:
    std::vector<QCheckBox*> checkboxes; 
    std::vector<QCheckBox*> checkboxes2; //选择加工的选项
    std::vector<QCheckBox*> checkboxes3; //点基准z值，设置当前加工的z值上下调整
    std::vector<E3_ID> entIDVector;
    std::vector<QButtonGroup*> buttonGroups;
    QButtonGroup* group;
    int checkedBoxesNumber = 0;
    Pt2d* ptBase;
    Pt3d* pt3;
    std::vector< Pt3d*> pointsData; //存储未进行3D校正之前的数据
    int lastdata = -1;
    int rowNumber = 0;
    double lastZBase[9] /*= {0,0,0, 0,0,0, 0,0,0}*/;  //z值基准
    double nowZBase[9] = {0,0,0, 0,0,0, 0,0,0};  //当前的z值基准
    bool ismodify = false;
private:
    void UiInit();
    void clearZData();
    void InitAllPointsData();
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
