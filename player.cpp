#include "player.h"
#include "config.h"
Player::Player()
{
    //初始化加载玩家潜艇的资源
    m_submarine.load(PLAYER_PATH);
    //初始化坐标
    //m_x=m_submarine.width();
    m_X=0;
    m_Y=(GAME_HEIGHT-m_submarine.height())*0.5;
    //初始化矩形边框
    //矩形框四个属性:长宽 ,横纵坐标
    m_Rect.setWidth(m_submarine.width());
    m_Rect.setHeight(m_submarine.height());
    m_Rect.moveTo(m_X,m_Y);
}
void Player::setPosition(int x, int y)
{
   //根据传进来的参数
   m_X = x;
   m_Y = y;
   m_Rect.moveTo(m_X,m_Y);
}

void Player::shoot()
{

}

