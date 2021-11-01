#ifndef MAP_H
#define MAP_H
#include <QPixmap>
//QPixmap类用于图像显示
class Map
{
public:
    //构造函数
    Map();

    //地图滚动坐标计算
    void mapPosition();

public:

    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;
    //两张一样的地图无缝衔接

    //地图X轴坐标
    int m_map1_posX;
    int m_map2_posX;

    //地图滚动幅度
    //防止地图变得太快或太慢
    int m_scroll_speed;

};

#endif // MAP_H
