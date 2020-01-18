#include <Block.h>
#include <QWidget>

Block::Block(QWidget &widget) : widget(&widget), x(0), y(0){}
Block::Block(QWidget &widget, int x, int y) : widget(&widget), x(x), y(y) {}
QWidget* Block::getWidget() const {
       return widget;
}

void Block::setPos(int x, int y) {
    this->x = x;
    this->y = y;
    widget->move(x*30, y*30);
}

int Block::getPosX() const {
    return x;
}

int Block::getPosY() const {
    return y;
}
