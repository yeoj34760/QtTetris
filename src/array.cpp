#include "array.h"

Array::Array(int shape,int turn): shape(shape), turn(turn)
{

}

bool Array::blockCheck(int x, int y) {

    switch (shape) {
    case TETROMINO_I:
        if (turn % 2 == 0)
            return tetromino.TetrominoI[0][y][x];
        else
            return tetromino.TetrominoI[1][y][x];
        break;
    case TETROMINO_J:
        return tetromino.TetrominoJ[turn][y][x];
        break;
    case TETROMINO_L:
        return tetromino.TetrominoL[turn][y][x];
        break;
    case TETROMINO_O:
        return tetromino.TetrominoO[y][x];
        break;
    case TETROMINO_S:
        return tetromino.TetrominoS[turn][y][x];
        break;
    case TETROMINO_T:
        return tetromino.TetrominoT[turn][y][x];
        break;
    case TETROMINO_Z:
        return tetromino.TetrominoZ[turn][y][x];
        break;
    }
    return false;
}

void Array::Fabricate(Blocks &blocks, int x_count) {
    int count = 0;
    for (int y = 0; y < BLOCK_COUNT; y++) {
        for (int x = 0; x < BLOCK_COUNT; x++) {
            if (blockCheck(x,y)) {
                blocks[count++]->setPos(x + x_count, y);
            }
        }
    }
}
void Array::Turn(Blocks &blocks) {
    int bottom = TetrominoPonstInfo(blocks).getbottom();
    int left = TetrominoPonstInfo(blocks).getLeft();
    Fabricate(blocks, left);
    for (auto t : blocks)
        t->setPos(t->getPosX(), START_Y +  t->getPosY() + bottom);

    qDebug() << TetrominoPonstInfo(blocks).getLeft() << left;
}
void Array::Start(Blocks &blocks) {
    Fabricate(blocks, START_X);
    int top = TetrominoPonstInfo(blocks).getTop();
    for (auto t : blocks)
        t->setPos(t->getPosX(), START_Y +  t->getPosY() - top);
}
