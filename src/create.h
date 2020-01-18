#ifndef RANDOM_H
#define RANDOM_H

#include "Block.h"
#include <Tetromino.h>
#include <QList>
#include <QFrame>
#define START_Y -3
#define START_X 4
class Create
{
private:
 //   int shape;
 //   int turn; // 0 ~ 3
    QString color;
    Tetromino tetromino;
    bool blockCheck(int x, int y);
    QString getColor(int color);
public:
    Create(int color);
   Blocks getBlock(QFrame &frame);
};

#endif // RANDOM_H
