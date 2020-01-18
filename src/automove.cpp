#include "automove.h"
#include <QDebug>
AutoMove::AutoMove(Blocks &blocks,Blocks &fixedTetromino, QObject *parent) : blocks(&blocks),fixedTetromino(&fixedTetromino), QThread(parent)
{
}

void AutoMove::run() {

        while(1) {
            QThread::msleep(SPEED);
            if (TetrominoPonstInfo(*blocks).getbottom() == 19)
                break;
            for (auto e : *fixedTetromino) {
                for (auto i : *blocks){
                    int x = i->getPosX();
                    if (i->getPosY() + 1 == e->getPosY() && x == e->getPosX()) //바닥
                        goto EXIT;
                }
            }
            for (auto i : *blocks){
                int x = i->getPosX(), y = i->getPosY();
                i->setPos(x, ++y);
            }
        }
        EXIT:
        QThread::msleep(SPEED);
    emit RestartSignals(); //다시 돌리도록 지시합니다.
}
