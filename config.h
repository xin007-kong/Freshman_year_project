#ifndef CONFIG_H
#define CONFIG_H



/***** 游戏配置数据 *****/
#define GAME_WIDTH 1440   //宽度
#define GAME_HEIGHT 1024    //高度
#define GAME_TITLE "Music submarine" //标题
#define GAME_RES_PATH "./submarine.rcc" //rcc文件路径

//#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/favicon.ico"
//#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/sub1.png"
#define GAME_ICON "F:/Freshman_year_project/Music_submarine/resources_for_project/background1.jpg"
#define GAME_RATE 10  //定时器刷新时间间隔 单位:毫秒
                      //配上地图滚动速度就可理解为 每10毫秒地图滚动2像素


/***** 地图配置数据 *****/
#define MAP_PATH "F:/Freshman_year_project/Music_submarine/resources_for_project/background1.jpg" //地图路径
//#define MAP_PATH ":/resources_for_project/background1.jpg" //地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

/********** 玩家配置数据 **********/
#define PLAYER_PATH "F:/Freshman_year_project/Music_submarine/resources_for_project/player 1.png"





#endif // CONFIG_H
