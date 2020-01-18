#include "create.h"
#include "tetrominoponstinfo.h"
#include <QDebug>
Create::Create(int color)
{
this->color = getColor(color);
}


QString Create::getColor(int color) {
    switch (color) {
    case TETROMINO_I:
        return COLOR_I;
    case TETROMINO_J:
        return COLOR_J;
    case TETROMINO_L:
        return COLOR_L;
    case TETROMINO_O:
        return COLOR_O;
    case TETROMINO_S:
        return COLOR_S;
    case TETROMINO_T:
        return COLOR_T;
    case TETROMINO_Z:
        return COLOR_Z;
    }
    return NULL;
}
Blocks Create::getBlock(QFrame &frame) {
    Blocks temp;
    for (int i = 0; i < BLOCK_COUNT; i++) {
        QWidget *tempWidget = new QWidget(&frame);
        Block *tempBlock;
        tempWidget->setStyleSheet("background-color: rgb("+ color + ");");
        tempWidget->resize(30, 30);
        tempWidget->show();
        tempBlock = new Block(*tempWidget);
        temp << tempBlock;
    }
    return temp;
}
