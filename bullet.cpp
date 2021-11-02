#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH1);

    //子弹坐标
    m_X =0;
    m_Y=GAME_HEIGHT*0.5;

    //子弹状态 默认空闲
    m_Free = true;

    //子弹速度
    m_Speed=BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}
void Bullet::updatePosition()
{
    //空闲状态下的子弹，不需要计算坐标
    if(m_Free)
    {
        return;
    }
    //子弹向右移动
    m_X+=m_Speed;
    //子弹动了,子弹的边框也要跟着动
    m_Rect.moveTo(m_X,m_Y);
    //子弹位置超出屏幕，重新变为空闲状态
    if(m_X>=m_Rect.width()+GAME_WIDTH)//画图想想
    {
        m_Free = true;
    }
}
