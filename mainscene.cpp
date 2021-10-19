#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));
}

