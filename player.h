#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <QRect>

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

};

#endif // PLAYER_H
