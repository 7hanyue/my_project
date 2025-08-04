
#include <QButtonGroup>
#include <QtConcurrent>
#include <QTableWidgetItem>
#include <QFileDialog>
#include "ClockWidget.h"
#include "ui_ClockWidget.h"

#include "CalibParam.h"
#include  <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QtMath>
//#ifndef UNICODE
//#define QStringToTCHAR(x)     (wchar_t*) x.utf16()
//#define PQStringToTCHAR(x)    (wchar_t*) x->utf16()
//#define TCHARToQString(x)     QString::fromUtf16((x))
//#define TCHARToQStringN(x,y)  QString::fromUtf16((x),(y))
//#else
//#define QStringToTCHAR(x)     x.local8Bit().constData()
//#define PQStringToTCHAR(x)    x->local8Bit().constData()
//#define TCHARToQString(x)     QString::fromLocal8Bit((x))
//#define TCHARToQStringN(x,y)  QString::fromLocal8Bit((x),(y))
//#endif
ClockWidget::ClockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClockWidget)
{
    _parent = parent;
    ui->setupUi(this);
    //LoadLibary1();
    Control::get_instance()->Init();
    tablewDataInit();
    initCheckboxes();
    UiInit();
   
    
}

ClockWidget::~ClockWidget()
{
    delete ui;
    /*if(ptBase != nullptr)
        delete[] ptBase;*/
}
void ClockWidget::UiInit()
{
    _calibParam = std::make_shared<CalibParam>("3DcalibParam", "");
    ui->doubleSpxRadius->setValue(_calibParam->_clockRadius);
    ui->doubleSpxx->setValue(_calibParam->_arrayX);
    ui->doubleSpxy->setValue(_calibParam->_arrayY);
    ui->doubleSpxZstep->setValue(_calibParam->_zStep);

    InitAllPointsData();
 /*   Control::get_instance()->SaveFile();*/
    connect(ui->btnStartMark, &QPushButton::clicked, this, &ClockWidget::onStartMark);
    connect(ui->btnApply, &QPushButton::clicked, this, &ClockWidget::onApplyParam);
    connect(this, &ClockWidget::signalUpdataAllPointsData, this, &ClockWidget::onUpdataAllPointsData);
    connect(ui->btnF3Param, &QPushButton::clicked, this, &ClockWidget::onOpenDlgSetCfg);
    connect(ui->btnMarkParam, &QPushButton::clicked, this, &ClockWidget::onOpenMarkParamSet);
    connect(ui->btnStopMark, &QPushButton::clicked, this, &ClockWidget::onStopMark);
    connect(ui->btnAddCalibData, &QPushButton::clicked, this, &ClockWidget::onAddDataToTableWidget);

    connect(ui->btnSet, &QPushButton::clicked, this, &ClockWidget::onSetZBase);

    connect(ui->btn_test, &QPushButton::clicked, this, &ClockWidget::onOpenPositionDatumsDialog);

    connect(ui->btnSaveCalibData, &QPushButton::clicked, this, &ClockWidget::onSaveCalibData);
    /*connect(ui->spinZnumberOfLayers, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [this](int value)
        {
            ui->tablew3DCalibData->insertRow(ui->spinZnumberOfLayers->value());
        }   );*/
    connect(this, &ClockWidget::signalUpdatataSelectedPointData, this, &ClockWidget::onUpdataSelectedPointData);
    connect(ui->btnStartMark, &QPushButton::clicked, this, [=]() {

        for (QButtonGroup* group : buttonGroups)
            group->setExclusive(false);

        // 遍历所有 CheckBox 并取消勾选
        for (QCheckBox* checkbox : checkboxes)
            checkbox->setChecked(false);

        /*for (QCheckBox* checkbox : checkboxes3)
            checkbox->setChecked(false);*/

        for (QButtonGroup* group : buttonGroups)
            group->setExclusive(true);
        
        });
}
void ClockWidget::onOpenMarkParamSet()
{
    if (markParamDialog != nullptr)
    {
        markParamDialog->exec();
        return;
    }
    markParamDialog = new MarkParamDialog(_parent);
    markParamDialog->exec();
}
void ClockWidget::onOpenPositionDatumsDialog()
{
    //_positionDatumsDialog = new PositionDatumsDialog(_parent);
    //_positionDatumsDialog->exec();
    std::shared_ptr<PositionDatumsDialog> positionDatumsDialog = std::make_shared<PositionDatumsDialog>();
    positionDatumsDialog->exec();
}
void ClockWidget::tablewDataInit()
{

    ui->tablew3DCalibData->setRowCount(11);  // 设置 5 行
    ui->tablew3DCalibData->setColumnCount(10); // 设置 11 列
    // 设置列标题
    QStringList headers;
    headers << "Z(理论值)" << "0." << "1." << "2." << "3." << "4." << "5." << "6." << "7." << "8.";  // 自定义列标题
    ui->tablew3DCalibData->setHorizontalHeaderLabels(headers);

    /*for (int i = 0; i < ui->tablew3DCalibData->rowCount(); ++i)
    {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(i));
        ui->tablew3DCalibData->setVerticalHeaderItem(i, item);
    }*/

    ui->tablew3DCalibData->setColumnWidth(0, 77); // 第1列宽度为60像素
    ui->tablew3DCalibData->setColumnWidth(1, 90); // 第1列宽度为65像素
    for (int i = 2; i < 11; ++i)
        ui->tablew3DCalibData->setColumnWidth(i, 90);


}

void ClockWidget::InitAllPointsData()
{
    // 1. 分配连续内存（9*12 个 Pt2d，按行优先存储）
    ptBase = new Pt2d[9 * 12];
    pt3 = new Pt3d[9];
    int k = 0;
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int i = 0; i < 12; ++i) {
                // 计算角度（弧度制），12个点均匀分布在圆周上
                double angle = i * 2 * M_PI / 12;
                Pt2d* ptBase2 = new Pt2d[1];
                // 极坐标转笛卡尔坐标my*dy
                ptBase[i + k].Y = -(-_calibParam->_arrayX + y * _calibParam->_arrayY) + _calibParam->_clockRadius * qCos(angle);
                ptBase[i + k].X = -_calibParam->_arrayY + x * _calibParam->_arrayX + _calibParam->_clockRadius * qSin(angle);

                ptBase2[0].Y = -(-_calibParam->_arrayX + y * _calibParam->_arrayY) + _calibParam->_clockRadius * qCos(angle);
                ptBase2[0].X = -_calibParam->_arrayY + x * _calibParam->_arrayX + _calibParam->_clockRadius * qSin(angle);
                E3_ID m_idCurEnt = 0;
                Control::get_instance()->CreatPoints(ptBase2, m_idCurEnt);
                qDebug() << "value " << (i + k);
                qDebug() << "valuex " << ptBase[i + k].X;
                qDebug() << "valuey " << ptBase[i + k].Y;
                entIDVector.push_back(m_idCurEnt);
                if (i <= 6)
                {
                    Control::get_instance()->SetEntZ(m_idCurEnt, 0 + _calibParam->_zStep * i);
                }
                else {
                    Control::get_instance()->SetEntZ(m_idCurEnt, 0 - _calibParam->_zStep * (12 - i));
                }
                delete[] ptBase2;
                double z;
                Control::get_instance()->GetEntInfo(m_idCurEnt, z);
                qDebug() << "z " << z;
            }
            k = k + 12;
            qDebug() << "k " << k;
        }
    }
}

void ClockWidget::onUpdataAllPointsData()
{
    if (_isClickedApply)
    {
        //1删除当前层中所有对象
        entIDVector.size();
        int layerCount;
        int entCount;
        int curLayerIndex;
        E3_ID curIdLayer;
        Control::get_instance()->GetLayerCountAndCurlaserIndex(layerCount, curLayerIndex);
        Control::get_instance()->GetLayerId(curLayerIndex, curIdLayer);
        Control::get_instance()->GetEntCountInLayer(curIdLayer, entCount);
        for(int i = 0; i < entCount; ++i)
            Control::get_instance()->DeleteEnt(entIDVector.at(i));
        entIDVector.clear();
        //2重新创建
        // 分配连续内存（9*12 个 Pt2d，按行优先存储）
        ptBase = new Pt2d[9 * 12];
        pt3 = new Pt3d[9];
        int k = 0;
        for (int y = 0; y < 3; ++y)
        {

            for (int x = 0; x < 3; ++x)
            {

                for (int i = 0; i < 12; ++i) {
                    // 计算角度（弧度制），12个点均匀分布在圆周上
                    double angle = i * 2 * M_PI / 12;
                    Pt2d* ptBase2 = new Pt2d[1];
                    // 极坐标转笛卡尔坐标my*dy
                    ptBase[i + k].Y = -(-_calibParam->_arrayX + y * _calibParam->_arrayY) + _calibParam->_clockRadius * qCos(angle);
                    ptBase[i + k].X = -_calibParam->_arrayY + x * _calibParam->_arrayX + _calibParam->_clockRadius * qSin(angle);

                    ptBase2[0].Y = -(-_calibParam->_arrayX + y * _calibParam->_arrayY) + _calibParam->_clockRadius * qCos(angle);
                    ptBase2[0].X = -_calibParam->_arrayY + x * _calibParam->_arrayX + _calibParam->_clockRadius * qSin(angle);
                    E3_ID m_idCurEnt = 0;
                    Control::get_instance()->CreatPoints(ptBase2, m_idCurEnt);
                    //ez3_CreatePoints_2(m_idEntMgr, 0, ptBase2, 1, true, m_idCurEnt);
                    qDebug() << "value " << (i + k);
                    qDebug() << "valuex " << ptBase[i + k].X;
                    qDebug() << "valuey " << ptBase[i + k].Y;
                    entIDVector.push_back(m_idCurEnt);

                    if (i <= 6)
                    {
                        if (checkboxes3[x + y * 3]->isChecked())
                            Control::get_instance()->SetEntZ(m_idCurEnt, nowZBase[x + y * 3] + _calibParam->_zStep * i);
                        else
                            Control::get_instance()->SetEntZ(m_idCurEnt, 0 + _calibParam->_zStep * i);

                    }
                    else {
                        if (checkboxes3[x + y * 3]->isChecked())
                            Control::get_instance()->SetEntZ(m_idCurEnt, nowZBase[x + y * 3] - _calibParam->_zStep * (12 - i));
                        else
                            Control::get_instance()->SetEntZ(m_idCurEnt, 0 - _calibParam->_zStep * (12 - i));
                    }
                    delete[] ptBase2;
                    double z;
                    Control::get_instance()->GetEntInfo(m_idCurEnt, z);
                    qDebug() << "z " << z;
                }
                k = k + 12;

                qDebug() << "k " << k;
            }
        }
    }
        

    
}

void ClockWidget::onSetZBase()
{   
    for (int i = 0; i < 9; ++i)
    {
        bool checked12 = false; //时钟12个点是否被勾选的标志位
        if (checkboxes3[i]->isChecked() && !ismodify)
        {
            for (int h = 0; h < 12; ++h)
            {
            
                if (checkboxes[h]->isChecked())
                {
                    int h2 = h;
                    if (h2 >= 10 && h2 < 12)
                        h2 = h2 - 12;
                    //h = h + 3;
                    if (h2 <= 3 && h2 >= -2)
                        nowZBase[i] = lastZBase[i] + _calibParam->_zStep * (h2 + 3);
                    if (h2 > 3 && h2 < 10)
                        nowZBase[i] = lastZBase[i] - _calibParam->_zStep * (12 - h2 - 3) ;
                    //ismodify = true;
                    checked12 = true;
                }
            }
            if (!checked12)
            {
                QMessageBox::information(nullptr, "Information", ("未选择z基准点"));
            }
            
        }
        //ismodify = false;
    }
    

}

void ClockWidget::onApplyParam()
{   
    _calibParam->_clockRadius = ui->doubleSpxRadius->value();
    _calibParam->_arrayX = ui->doubleSpxx->value();
    _calibParam->_arrayY = ui->doubleSpxy->value();
    _calibParam->_zStep = ui->doubleSpxZstep->value();
    _calibParam->Save();
    
    _isClickedApply = true;

    //emit signalUpdataAllPointsData();
}
void ClockWidget::onStartMark()
{
    emit signalUpdataAllPointsData();

    Control::get_instance()->SaveFile();
    double t;
    Control::get_instance()->GetPenGraftParam(t);
    qDebug() << "t " << t;
    BOOL m;
    Control::get_instance()->GetPenGraftParamWeldWave2(m);
    qDebug() << "m" << m;
    // 更新 UI 状态（例如禁用按钮、显示进度等）
    ui->btnStartMark->setEnabled(false);

    // 把阻塞操作丢到后台线程
    QtConcurrent::run([this]() {
        // 执行阻塞操作（不会卡 UI）
        int rtnmark = Control::get_instance()->StartMark();
 
        // 任务完成后，通知主线程更新 UI
        //Q_ARG(参数类型, 参数值)
        QMetaObject::invokeMethod(this, "onTaskFinished", Qt::QueuedConnection, Q_ARG(int, rtnmark));
        });

}

void ClockWidget::onStopMark()
{
    Control::get_instance()->StopMark();
    //qDebug() << "err" << err;
}

void ClockWidget::onTaskFinished(int result)
{
    qDebug() << "markResult" << result;
    // 更新 UI 状态（例如禁用按钮、显示进度等）
    ui->btnStartMark->setEnabled(true);
    if (result == 0)//加工成功才改变上一次得z值基准
    {
        for (int i = 0; i < 9; i++) 
        {
            lastZBase[i] = nowZBase[i];
            qDebug() << "lastZBase[i]" << lastZBase[i];
        }
        
    }
}

void ClockWidget::onOpenDlgSetCfg()
{
    Control::get_instance()->OpenF3();
    //qDebug() << "isModify " << isModify;
}

void ClockWidget::onUpdataSelectedPointData(int data, int data2)
{
    if (data2 == 12)
        data2 = 0;
    if (data2 <= 6)
        pt3[data].Z = nowZBase[data] + _calibParam->_zStep * data2;
    else 
        pt3[data].Z = nowZBase[data] - _calibParam->_zStep * (12 - data2);
    pt3[data].X = ptBase[data * 12 + data2].X;
    pt3[data].Y = ptBase[data * 12 + data2].Y;
    if (lastdata != data)
    {
        pointsData.push_back(&pt3[data]);
        lastdata = data;
    }
    sort(pointsData.begin(), pointsData.end());

    /*if (checkboxes3[data]->isChecked())
        lastZBase = pt3[data].Z;*/
    
    qDebug() << "X" << ptBase[data * 12 + data2].X;
    qDebug() << "Y" << ptBase[data * 12 + data2].Y;
    qDebug() << "表盘组[" << data << "] 选中："
        << data2 << "Z值" << pt3[data].Z
        << " | 状态：";//<< (state == Qt::Checked ? "选中" : "未选中");
}
void ClockWidget::onAddDataToTableWidget()
{
    for (QButtonGroup* group : buttonGroups) 
    {
        if (group->checkedButton()) // 如果组内有选中的按钮
            ++checkedBoxesNumber;
    }
    if (checkedBoxesNumber == 9)
    {
        
        for (int i = 0; i < 9; ++i)
        {
            QString str = QString::number(pt3[i].X) + "," + QString::number(pt3[i].Y) + "," + QString::number(pt3[i].Z);
            ui->tablew3DCalibData->setItem(rowNumber, i+1, new QTableWidgetItem(str));
            

        }
        ui->tablew3DCalibData->setItem(rowNumber, 0, new QTableWidgetItem(QString::number(ui->doubleSpxZphysicalValue->value())));
        ++rowNumber;
        clearZData();

    }
    else
    { 
        
        QMessageBox::information(nullptr, "Information", ("9个表盘的数据未全部勾选"));
    }
    checkedBoxesNumber = 0;
}

void ClockWidget::clearZData()
{
    /*for (QCheckBox* checkbox : checkboxes3)
            checkbox->setChecked(false);*/
    for (int i = 0; i < 9; ++i)
    {
        checkboxes3[i]->setChecked(false);
        lastZBase[i] = 0;
    }


}

void ClockWidget::onSaveCalibData()
{
    // 打开文件对话框，让用户选择保存位置和文件名
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "导出数据",
        QDir::homePath(),
        "CSV文件 (*.csv);;所有文件 (*)"
    );

    if (filePath.isEmpty())
        return; // 用户取消了操作

    // 尝试打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法打开文件: " + file.errorString());
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8"); // 设置编码，确保中文正常显示

    // 写入表头
    for (int col = 0; col < ui->tablew3DCalibData->columnCount(); ++col) {
        if (ui->tablew3DCalibData->horizontalHeaderItem(col)) {
            out << ui->tablew3DCalibData->horizontalHeaderItem(col)->text();
        }
        out << (col < ui->tablew3DCalibData->columnCount() - 1 ? "," : "\n");
    }

    // 写入数据
    for (int row = 0; row < ui->tablew3DCalibData->rowCount(); ++row) {
        for (int col = 0; col < ui->tablew3DCalibData->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tablew3DCalibData->item(row, col);
            if (item) {
                // 处理可能包含逗号的内容，用双引号包裹
                QString text = item->text();
                if (text.contains(','))
                    //在 C++ 和 Qt 的字符串中，\" 是一个转义字符，表示双引号 "
                    //text.replace("\"", "\"\"")将原字符串中的每个双引号 " 替换为两个双引号 ""
                    //例如：原始内容：Hello, "World"
                    //替换双引号："Hello, ""World"""
                    text = "\"" + text.replace("\"", "\"\"") + "\"";  
                out << text;
            }
            out << (col < ui->tablew3DCalibData->columnCount() - 1 ? "," : "\n");
        }
    }

    file.close();

    // 提示用户导出成功
    QMessageBox::information(this, "成功", "数据已成功导出到: " + filePath);
}

void ClockWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
    //int r =50; 
    for(int i = 0;i < 3; ++i)
    {
        for(int j = 0;j < 3; ++j)
        {
            drawDial(&painter,j* clockRadius *2* zoomFactor,i* clockRadius *2* zoomFactor, clockRadius);
            drawTicksAndNumbers(&painter,Startx+j* clockRadius *2* zoomFactor,Starty+i* clockRadius *2* zoomFactor, clockRadius);
            drawBlocks(&painter,-8+j* clockRadius *2*zoomFactor,-5+i* clockRadius *2*zoomFactor, clockRadius,i*3+j);
        }

    }
    //qDebug()<<"size" << checkboxes.size();
    //
}
void ClockWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    updateCheckboxPositions(); // 窗口大小变化时，重新计算CheckBox位置
}
void ClockWidget::initCheckboxes()
{
    for (int row = 0; row < 9; ++row)
    {
        QCheckBox* checkbox1 = new QCheckBox(this);
        checkboxes2.push_back(checkbox1);
        for (QCheckBox* checkbox : checkboxes2)
            checkbox->setChecked(true);

        connect(checkbox1, &QCheckBox::stateChanged, this, [=](int state) mutable { 
            if (state == Qt::Checked) { // 仅选中时输出（避免取消选中重复触发）
                qDebug() << "row" << row;
            }
            });

        QCheckBox* checkbox3 = new QCheckBox("选中点的z为基准", this);
        checkboxes3.push_back(checkbox3);
        for (QCheckBox* checkbox : checkboxes3)
        {
            checkbox->setChecked(false);
            //checkbox->setVisible(false);
        }
        connect(checkbox3, &QCheckBox::stateChanged, this, [=](int state) mutable {
            if (state == Qt::Checked) { // 仅选中时输出（避免取消选中重复触发）
                //lastZBase = pt3[row].Z;
                qDebug() << "选中点的z为基row" << row;
            }
            });



        group = new QButtonGroup(this);
        group->setExclusive(true); // 同一组内互斥（仅一个可选中）
        buttonGroups.push_back(group);
        for (int i = 0; i < 12; ++i)
        {
            QCheckBox* checkbox = new QCheckBox(this);
            checkbox->setStyleSheet("QCheckBox { background-color: transparent; }");

            group->addButton(checkbox);

            connect(checkbox, &QCheckBox::stateChanged, this, [=](int state) mutable {
                if (state == Qt::Checked) { // 仅选中时输出（避免取消选中重复触发）
                    if (i >= 10 && i < 12)
                        i = i - 12;
                    emit signalUpdatataSelectedPointData(row, i + 3);
                }
                    });
            checkboxes.push_back(checkbox);
        }

    }
}
void ClockWidget::updateCheckboxPositions()
{
    int r =40; //表盘半径
    for(int j = 0;j < 9; ++j)
    {
        

        int centerX = Startx+j*2*r*zoomFactor;
        int centerY = Starty;
        if(j == 3 || j==4 ||j==5)
            {
            centerX = Startx+(j-3)*2*r* zoomFactor;
            centerY = Starty+1*2*r* zoomFactor;
            }
         if(j == 6 || j==7 ||j==8)
            {
            centerX = Startx+(j-6)*2*r* zoomFactor;
            centerY = Starty+2*2*r* zoomFactor;
            }
        int radius = r *2 * 0.6;
        // 计算每个Checkbox的位置
        for (int i = 0; i < 12; ++i) {
            // 计算角度（弧度制），12个点均匀分布在圆周上
            double angle = i * 2 * M_PI / 12;
            // 极坐标转笛卡尔坐标
            int x = centerX + radius * qCos(angle);
            int y = centerY + radius * qSin(angle);

            // 获取Checkbox的大小并居中放置
            QSize size = checkboxes[i+j*12]->sizeHint();
            checkboxes[i+j*12]->setGeometry(x - size.width()/2, y - size.height()/2,
                                      size.width(), size.height());
        }
    }
}
void ClockWidget::drawBlocks(QPainter *painter, int offsetx, int offsety, int radius, int num)
{

    painter->save();

    painter->setPen(QPen(Qt::red, 30)); //
     // 2. 设置字体加粗
    QFont font = painter->font();      // 获取当前画家的字体
    font.setBold(true);                // 设置加粗（或 font.setWeight(QFont::Bold); ）
    painter->setFont(font);            // 将加粗字体应用到画家
    painter->drawText(QRectF(Startx -6 +offsetx, Starty+offsety, radius * 0.3, radius * 0.3),Qt::AlignCenter, QString::number(num));
    painter->restore();

    QSize size = checkboxes2[num]->sizeHint();
    checkboxes2[num]->setGeometry(Startx + 6 + offsetx, Starty + offsety,
        size.width(), size.height());
    //checkbox->setStyleSheet("QCheckBox { background-color: transparent; }");
    QSize size2 = checkboxes3[num]->sizeHint();
    checkboxes3[num]->setGeometry(Startx -55 + offsetx, Starty + 60 + offsety,
        size2.width(), size2.height());
    
}

void ClockWidget::drawDial(QPainter *painter, int offsetx, int offsety, int radius)
{
    painter->save();
    painter->setPen(QPen(Qt::black, 2)); // 表盘边框宽度
    // 绘制圆形表盘（半径50，比方块半径100小，留出外围空间）
    painter->drawEllipse(QPointF(Startx+offsetx, Starty+offsety), radius, radius);
    painter->restore();
}

void ClockWidget::drawTicksAndNumbers(QPainter *painter,int mx, int my, int mr)
{
   // 计算圆心和半径
    int cx = mx;
    int cy = my;
    int r = mr*2 * 0.45; // 表盘半径（占Widget的45%）
    QPen pen(Qt::black);
        // 绘制小时刻线（每小时位置）
    //pen.setColor(Qt::black);
    pen.setWidthF(1); // 小时刻线宽度
    painter->setPen(pen);
    for (int i = 0; i < 12; ++i) {
        qreal angle = i * 30.0;
        qreal rad = qDegreesToRadians(angle);

        // 刻线起点和终点（从半径的85%到95%）
        qreal x1 = cx + r * 0.85 * qSin(rad);
        qreal y1 = cy - r * 0.85 * qCos(rad);
        qreal x2 = cx + r * 1 * qSin(rad);
        qreal y2 = cy - r * 1 * qCos(rad);

        painter->drawLine(QPointF(x1, y1), QPointF(x2, y2));
    }

    // 绘制分钟刻线（每5分钟，非小时点）
    pen.setColor(Qt::black);
    pen.setWidthF(0.5); // 分钟刻线更细
    painter->setPen(pen);
    for (int i = 0; i < 60; ++i) {
        if (i % 5 == 0) continue; // 跳过小时刻线

        qreal angle = i * 6.0; // 每分钟6度
        qreal rad = qDegreesToRadians(angle);

        // 刻线起点和终点（从半径的90%到95%）
        qreal x1 = cx + r * 0.90 * qSin(rad);
        qreal y1 = cy - r * 0.90 * qCos(rad);
        qreal x2 = cx + r * 0.95 * qSin(rad);
        qreal y2 = cy - r * 0.95 * qCos(rad);

        painter->drawLine(QPointF(x1, y1), QPointF(x2, y2));
    }

    // 绘制12个数字
    for (int i = 0; i < 12; ++i) {
        int number = (i == 0) ? 12 : i;
        qreal angle = i * 30.0;
        qreal rad = qDegreesToRadians(angle);

        // 数字位置（从圆心向外偏移70%的半径）
        qreal x = cx + r * 0.7 * qSin(rad);
        qreal y = cy - r * 0.7 * qCos(rad);
  
        QFont font;
        font.setPointSize(6);  // 关键代码：设置字体大小，可根据需求调整数值
        painter->setFont(font);
        // 绘制文本（中心对齐）
        painter->drawText(QRectF(x - r * 0.15, y - r * 0.15, r * 0.3, r * 0.3),
                         Qt::AlignCenter, QString::number(number));
    }

}
void ClockWidget::LoadLibary()
{
    int a = 0;



}

