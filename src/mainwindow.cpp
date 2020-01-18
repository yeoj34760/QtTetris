#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QDebug>
#include "automove.h"
#include <QKeyEvent>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), shape(0), turn(0), score(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    for (auto i : *fixedTetromino)
    {
        delete  i->getWidget();
        delete  i;
    }
    for (auto i : *selectTetromino) {
        delete i->getWidget();
        delete i;
    }
    delete ui;

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A){
        if (TetrominoPonstInfo(*selectTetromino).getLeft() <= 0)
            return;
        for (auto e : *fixedTetromino) {
            for (auto i : *selectTetromino){
                if (i->getPosX() - 1 == e->getPosX())
                    if (i->getPosY() == e->getPosY()) //바닥
                        return;
            }
        }
    }
    else if (event->key() == Qt::Key_D) {
        if (TetrominoPonstInfo(*selectTetromino).getRight() >= 9)
            return;
        for (auto e : *fixedTetromino) {
            for (auto i : *selectTetromino){
                if (i->getPosX() + 1 == e->getPosX())
                    if (i->getPosY() == e->getPosY())
                        return;
            }
        }
    }


    if(event->key() == Qt::Key_W) {
        turn = ++turn == 4 ? 0 : turn;
        Array array(shape, turn);
        array.Turn(*selectTetromino);

    }
    for (auto block : *selectTetromino) {
        int x = block->getPosX(), y = block->getPosY();
        if (event->key() == Qt::Key_A)
            block->setPos(--x, y);

        if (event->key() == Qt::Key_D)
            block->setPos(++x, y);
    }

}
void MainWindow::RestartSlots() {
    turn = 0;
    int count = 0;
    *fixedTetromino += *selectTetromino;
    selectTetromino->clear();
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            for (auto z : *fixedTetromino) {
                if (z->getPosX() == x && z->getPosY() == y)
                    count++;
            }
        }
        if (count == 10)
        {
            Blocks temp;
            for (auto z : *fixedTetromino) {
                if (z->getPosY() == y) {
                    temp << z;
                }
                else if (z->getPosY() < y) {
                    z->setPos(z->getPosX(), z->getPosY() + 1);
                }
            }

            for (auto t  : temp) {
                delete t->getWidget();
                delete t;
                fixedTetromino->removeAt(fixedTetromino->indexOf(t));
            }

            ui->label->setText("점수: " + QString::number(++score));
        }

        count = 0;
    }
    GameStart();
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    if (fixedTetromino->size() != 0) {
        for (auto i : *fixedTetromino)
        {
            delete  i->getWidget();
            delete  i;
        }
        for (auto i : *selectTetromino) {
            delete i->getWidget();
            delete i;
        }
        fixedTetromino->clear();
        selectTetromino->clear();
    }
    ui->label->setText("점수: " + QString::number(score));
    GameStart();
}

void MainWindow::GameStart() {

    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    shape = qrand() % 7 + 0;
    Create create(shape);
    Array array(shape, 0);
    Blocks temp = create.getBlock(*ui->frame);
    array.Start(temp);
    *selectTetromino = temp;
    automove = new AutoMove(*selectTetromino,*fixedTetromino, this); //포인터 3개 넣을게
    connect(automove, SIGNAL(RestartSignals()), this, SLOT(RestartSlots()));
    connect(automove, &AutoMove::finished, automove, &QObject::deleteLater); //run 함수가 종료되면 자동으로 해체합니다.
    automove->start();
}
