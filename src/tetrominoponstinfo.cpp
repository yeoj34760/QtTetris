#include "tetrominoponstinfo.h"
TetrominoPonstInfo::TetrominoPonstInfo(Blocks &tetromino) : tetromino(&tetromino), Left(0), bottom(0), right(0)
{

}


int TetrominoPonstInfo::getLeft() const {
   // return Left;

    int temp = -1;
    for (auto t : *tetromino) {
        if (temp <= -1)
            temp = t->getPosX();
//5 >= 2
        if (temp > t->getPosX())
            temp = t->getPosX();
    }

    return temp;
}


int TetrominoPonstInfo::getRight() const {
    int temp = -1;
    for (auto t : *tetromino) {
        if (temp <= -1)
            temp = t->getPosX();
//5 >= 2
        if (temp < t->getPosX())
            temp = t->getPosX();
    }
    return temp;
}

int TetrominoPonstInfo::getbottom() const {
    int temp = -100;
    for (auto t : *tetromino) {
        if (temp == -100)
            temp = t->getPosY();
//현재 저장된 위치 < 위치
        if (temp < t->getPosY())
            temp = t->getPosY();
    }
    return temp;
}

int TetrominoPonstInfo::getTop() const {
    int temp = -100;
    for (auto t : *tetromino) {
        if (temp == -100)
            temp = t->getPosY();

        if (temp > t->getPosY())
            temp = t->getPosY();
    }
    return temp;
}

Blocks TetrominoPonstInfo::StartPos() {
    for (auto t : *tetromino) {
        t->setPos(START_X + t->getPosX(), START_Y +  t->getPosY() - getTop());
    }

    return *tetromino;
}
