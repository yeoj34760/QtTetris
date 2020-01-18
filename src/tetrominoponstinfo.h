#ifndef TETROMINOPONSTINFO_H
#define TETROMINOPONSTINFO_H
#include "Block.h"
#include "Tetromino.h"

#define START_Y -3
#define START_X 4
class TetrominoPonstInfo
{
private:
    Blocks *tetromino;
    int Left, bottom, right;
public:
    TetrominoPonstInfo(Blocks &tetromino);
    int getLeft() const;
    int getbottom() const;
    int getRight() const;
    int getTop() const;

    Blocks StartPos();
};

#endif // TETROMINOPONSTINFO_H
