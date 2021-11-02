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

    //累加时间间隔记录变量
    m_recorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(m_recorder < BULLET_INTERVAL)
    {
    return;
    }
    //到达发射时间处理
    //重置发射时间间隔记录
    m_recorder = 0;

    //发射子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //遍历数组,如果是空闲的子弹，进行发射
        if(m_bullets[i].m_Free==true)
        {
            //将空闲状态改为假
            m_bullets[i].m_Free=false;
            //设置子弹坐标   等于飞机的位置
            m_bullets[i].m_X=m_X+ m_Rect.width()*0.7+ 30;
            m_bullets[i].m_Y=m_Y+60;
            //发射了一发就退出循环
            break;


        }
    }



}

