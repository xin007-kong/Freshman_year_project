#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <map.h>
#include <player.h>
#include "bullet.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void startGame();

    //更新游戏中所有元素的坐标
    void updatePositon();

    //绘制到屏幕中,这个函数的名称是固定的不可以改
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    //重写键盘移动事件
    void keyPressEvent(QKeyEvent *event);
    //地图对象
    Map m_map;
    //玩家潜艇对象
    Player m_sub;

    //定时器
    QTimer m_Timer;




private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
