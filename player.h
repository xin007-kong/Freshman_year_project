#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
class Player
{
public:
    Player();
    //武器射击
    void shoot();
    //设置玩家潜艇位置
    void setPosition(int x, int y);
public:
    //潜艇资源 对象
    QPixmap m_submarine;
    //坐标
    int m_X;
    int m_Y;
    //玩家的矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_bullets[BULLET_NUM];
    //发射间隔记录
    int m_recorder;

    double skill; //技能值

};

#endif // PLAYER_H
