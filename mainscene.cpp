#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
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

    //随机数种子
    srand((unsigned int)time(NULL));

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
        //敌方出场
        enemyToScene();

        //更新游戏中元素的坐标
        updatePositon();
        //绘制到屏幕中
        update(); //自带系统函数重绘窗口

        collisionDetection();
    });

}

void MainScene::updatePositon()
{
    //更新地图坐标
    m_map.mapPosition();

    //发射子弹
    m_sub.shoot();

    //计算所有非空闲子弹的当前坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_sub.m_bullets[i].m_Free==false)
        {
            m_sub.m_bullets[i].updatePosition();
        }
    }
    //敌机坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机 更新坐标
        if(m_enemys[i].m_Free == false)
        {
             m_enemys[i].updatePosition();
        }
    }

    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
        m_bombs[i].updateInfo();
        }
    }

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

    //绘制武器
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
    //如果武器状态为非空闲，计算发射位置
     if(!m_sub.m_bullets[i].m_Free)
     {
         painter.drawPixmap(m_sub.m_bullets[i].m_X,m_sub.m_bullets[i].m_Y,m_sub.m_bullets[i].m_Bullet);
     }
    }

    //绘制敌人
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
         painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }

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
//         case 1:
//             m_Bullet.PATH=BULLET_PATH1;
//                for(int i = 0 ;i < BULLET_NUM;i++)
//                {
//                //如果武器状态空闲,就切换武器(切换图片路径),发出去的不能中途变换武器
//                 if(m_sub.m_bullets[i].m_Free==true)
//                 {
//                    m_sub.m_bullets[i].PATH = BULLET_PATH1;
//                 }
//                }
//             break;
//         case 2:
//                for(int i = 0 ;i < BULLET_NUM;i++)
//                {
//                //如果武器状态空闲,就切换武器(切换图片路径),发出去的不能中途变换武器
//                 if(m_sub.m_bullets[i].m_Free==true)
//                 {
//                    m_sub.m_bullets[i].PATH = BULLET_PATH2;
//                 }
//                }
//             break;
//         case 3:
//                for(int i = 0 ;i < BULLET_NUM;i++)
//                {
//                //如果武器状态空闲,就切换武器(切换图片路径),发出去的不能中途变换武器
//                 if(m_sub.m_bullets[i].m_Free==true)
//                 {
//                    m_sub.m_bullets[i].PATH = BULLET_PATH3;
//                 }
//                }
//             break;
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

void MainScene::enemyToScene()
{
    m_recorder++;
    //未到达出场时间，就return
    if(m_recorder<ENEMY_INTERVAL)
    {
        return ;
    }
    m_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果是空闲状态,出场
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;

            //坐标
            m_enemys[i].m_X=1440;
            //随机数
            m_enemys[i].m_Y = rand() % (GAME_HEIGHT- m_enemys[i].m_Rect.height());
            break;//不能忘，不然所有敌人一起出场了！！！！

        }


    }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
    if(m_enemys[i].m_Free)
    {
    //如果是空闲的敌人，执行下一次循环
    continue;
    }
    //遍历所有 非空闲的子弹
    for(int j = 0 ; j < BULLET_NUM;j++)
    {
    if(m_sub.m_bullets[j].m_Free)
    {
    //空闲子弹 跳转下一次循环
    continue;
    }
    //如果子弹矩形框和敌人矩形框相交，发生碰撞，同时变为空闲状态即可（因为空闲状态不绘制，所以逻辑上就是消失了）
        if(m_enemys[i].m_Rect.intersects(m_sub.m_bullets[j].m_Rect))
        {
           //失败的得分显示代码 score_update.increase();
//            nscore++;
            m_enemys[i].m_Free = true;
            m_sub.m_bullets[j].m_Free = true;
            //播放爆炸效果

                //播放爆炸效果
                for(int k = 0 ; k < BOMB_NUM;k++)
                {
                if(m_bombs[k].m_Free)
                {
                    //播放音效
//                    QSound::play(SOUND_BOMB);
                //爆炸状态设置为非空闲
                m_bombs[k].m_Free = false;

                //更新坐标
                m_bombs[k].m_X = m_enemys[i].m_X;
                m_bombs[k].m_Y = m_enemys[i].m_Y;
                break;
                }
            }
        }
    }
    }
}


