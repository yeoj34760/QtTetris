#ifndef AUTOMOVE_H
#define AUTOMOVE_H
#include <QThread>
#include <QFrame>
#include <QDebug>
#include "Block.h"
#include "tetrominoponstinfo.h"
#include "Tetromino.h"
#include "create.h"

#define SPEED 200
class AutoMove : public QThread
{
     Q_OBJECT
private:
    Blocks *blocks;
    Blocks *fixedTetromino;
    virtual ~AutoMove() {qDebug() << "도착";}
public:
    AutoMove(Blocks &blocks, Blocks &fixedTetromino, QObject *parent = 0);
    void run() override;

signals:
    void RestartSignals();
};

#endif // AUTOMOVE_H
