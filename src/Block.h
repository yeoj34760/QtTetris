#ifndef BLOCK_H
#define BLOCK_H
#include <QWidget>
class Block {
private:
    QWidget *widget;
    int x, y;
    //x Max 10, y Max 20
public:
    Block(QWidget &widget);
    Block(QWidget &widget, int x, int y);
    QWidget* getWidget() const;
    void setPos(int x, int y);
   int getPosX() const;
    int getPosY() const;
};
#endif // BLOCK_H
