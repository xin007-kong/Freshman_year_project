#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

/**********---------- 游戏配置数据 ----------**********/
#define GAME_WIDTH 1440   //宽度
#define GAME_HEIGHT 1024   //高度
#define GAME_TITLE "Music submarine" //标题
#define GAME_RES_PATH "./submarine.rcc" //rcc文件路径

//#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/favicon.ico"
//#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/sub1.png"
#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/background2.jpg"
#define GAME_RATE 10  //定时器刷新时间间隔 单位:毫秒
                      //配上地图滚动速度就可理解为 每10毫秒地图滚动2像素


/**********---------- 地图配置数据 ----------**********/
#define MAP_PATH "F:/Freshman_year_project/Music_submarine/resources_for_project/background1.jpg" //地图路径
//#define MAP_PATH ":/resources_for_project/background1.jpg" //地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

/**********---------- 玩家配置数据 ----------**********/
#define PLAYER_PATH "F:/Freshman_year_project/Music_submarine/resources_for_project/player 1.png"

/**********---------- 子弹配置数据 ----------**********/
/*
#define BULLET_PATH1 "F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_13.png" //子弹图片路径
#define BULLET_PATH2 "F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_12.png" //子弹图片路径
#define BULLET_PATH3 "F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_8.png" //子弹图片路径
*/
#define BULLET_SPEED 5 //子弹移动速度
#define BULLET_NUM 30 //弹匣中子弹总数
#define BULLET_INTERVAL 30 //发射子弹时间间隔

const QString BULLET_PATH1="F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_13.png";
const QString BULLET_PATH2="F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_12.png";
const QString BULLET_PATH3="F:/Freshman_year_project/Music_submarine/temp_resources/missle/bullet_8.png";



/********** 敌人配置数据 **********/
const QString ENEMYSUB_PATH = "F:/Freshman_year_project/Music_submarine/resources_for_project/sub2.png"; //敌人资源图片
#define ENEMY_SPEED 3 //敌人移动速度
#define ENEMY_NUM 4 //敌人总数量
#define ENEMY_INTERVAL 30 //敌人出场时间间隔


/**********---------- 爆炸配置数据 ----------**********/
#define BOMB_PATH ":F:/Freshman_year_project/Music_submarine/resources_for_project/bomb-%1.png" //爆炸资源图片 //%1是占位符
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔














#endif // CONFIG_H
