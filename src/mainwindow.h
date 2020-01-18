#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Tetromino.h"
#include "Block.h"
#include "tetrominoponstinfo.h"
#include "create.h"
#include "automove.h"
#include "array.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void RestartSlots();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
private:
    int shape, turn, score;
    void keyPressEvent(QKeyEvent *event);
    void GameStart();
    AutoMove *automove;
    Ui::MainWindow *ui;
    Blocks *selectTetromino = new Blocks();
    Blocks *fixedTetromino = new Blocks();
    bool Arrive = false;
};
#endif // MAINWINDOW_H
