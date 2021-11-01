#include "map.h"
#include "config.h" //MAP_PATH在那里
Map::Map()
{
    //初始化加载地图对象
    //load()方法是加载文件图像作为QPixmap对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //初始化X轴坐标
    m_map1_posX = 0;
    m_map2_posX = -GAME_WIDTH;

    //地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;

}

void Map::mapPosition()
{
    /*初始状态的时候map1在前面,map2在后面
    初始坐标:    m_map1_posX = 0;
    m_map2_posX = -GAME_WIDTH;*/
    //处理第一张图片滚动位置;
    m_map1_posX += m_scroll_speed; //跑起来

    //当图片整个跑出屏幕的时候,要重置
    if(m_map1_posX >= GAME_WIDTH)
    {
        m_map1_posX = 0;
    }

    //处理第二张图片滚动位置
    m_map2_posX += m_scroll_speed;

    if(m_map2_posX >= 0)
    {
        m_map2_posX = -GAME_WIDTH;
    }




}
