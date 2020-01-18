#ifndef ARRAY_H
#define ARRAY_H
#include "Tetromino.h"
#include "tetrominoponstinfo.h"
#include <QDebug>
#define START_Y    -3
#define START_X     4
class Array
{
private:
    Tetromino tetromino;
        bool blockCheck(int x, int y);
        int shape,turn;
        void Fabricate(Blocks &blocks, int x);
public:
    Array(int shape,int trun);
    void Start(Blocks &blocks);       //블럭 생성할 때
    void Turn(Blocks &blocks);        //회전할 때
};

#endif // ARRAY_H
