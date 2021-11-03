#include "enemy.h"
#include "config.h"
Enemy::Enemy()
{
    //敌方资源加载
    m_enemy.load(ENEMYSUB_PATH);

    //敌方位置
    m_X=0;
    m_Y=0;

    //敌方状态
    m_Free = true;
    //敌方速度
    m_Speed = ENEMY_SPEED;
    //敌方矩形
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Enemy::updatePosition()
{
    //空闲状态，不计算坐标
    if(m_Free)
    {
        return;
    }
    m_X -= m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_X <= 0)
    {
        m_Free = true;//重置为空闲
    }
}
