#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
