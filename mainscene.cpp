#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //调用初始化场景
    initScene();

    //启动游戏
    startGame();


}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器初始化
    m_Timer.setInterval(GAME_RATE);
}

void MainScene::startGame()
{
    //启动定时器
    m_Timer.start();



    //C++11的lambda表达式新特性
    //用lambda替代signal/slot函数
    //定时器每隔十毫米会发送信号,要监听定时器发生的信号

    //timeout()功能：定时器超时后(每隔10毫秒), 这个信号被发射,并用函数去接收这个信号
    connect(&m_Timer, &QTimer::timeout,[=](){
        //更新游戏中元素的坐标
        updatePositon();
        //绘制到屏幕中
        update(); //自带系统函数重绘窗口
    });

}

void MainScene::updatePositon()
{
    //更新地图坐标
    m_map.mapPosition();
}

void MainScene::paintEvent(QPaintEvent *)
{
    //画家对象
    //this指针:要在当前屏幕中绘画
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(m_map.m_map1_posX,0,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,0,m_map.m_map2);
    //绘制玩家潜艇
    painter.drawPixmap(m_sub.m_X,m_sub.m_Y,m_sub.m_submarine);//第三个参数是要显示的图片

}

void MainScene::mouseMoveEvent(QMouseEvent * event)
{
    int x=event->x()-m_sub.m_Rect.width()*0.5;
    int y =event->y()-m_sub.m_Rect.height()*0.5;
    m_sub.setPosition(x,y);
    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_sub.m_Rect.width())
    {
        x = GAME_WIDTH - m_sub.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_sub.m_Rect.height())
    {
        y = GAME_HEIGHT - m_sub.m_Rect.height();
    }
    m_sub.setPosition(x,y);
}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){

         case Qt::Key_Left:
             m_sub.m_X=m_sub.m_X-10;
             break;
         case Qt::Key_Up:
             m_sub.m_Y=m_sub.m_Y-10;
             break;
         case Qt::Key_Right:
             m_sub.m_X=m_sub.m_X+10;
             break;
         case Qt::Key_Down:
             m_sub.m_Y=m_sub.m_Y+10;
             break;
    }

        if(m_sub.m_X <= 0 )
            {
                m_sub.m_X = 0;
            }
            if(m_sub.m_X >= GAME_WIDTH - m_sub.m_Rect.width())
            {
                m_sub.m_X = GAME_WIDTH - m_sub.m_Rect.width();
            }
            if(m_sub.m_Y <= 0)
            {
                m_sub.m_Y = 0;
            }
            if(m_sub.m_Y >= GAME_HEIGHT - m_sub.m_Rect.height())
            {
                m_sub.m_Y = GAME_HEIGHT - m_sub.m_Rect.height();
            }
            m_sub.setPosition(m_sub.m_X,m_sub.m_Y);
}

