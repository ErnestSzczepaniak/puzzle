#include "item_generic.h"

Item_generic::Item_generic()
{

}

Item_generic::~Item_generic()
{

}

void Item_generic::move(int diff_x, int diff_y)
{
    clear();
    auto [x, y] = pos(); 
    pos(x + diff_x, y + diff_y);
    draw();
}

void Item_generic::pos(int x, int y)
{
    _position.x = x;
    _position.y = y;
}

Position Item_generic::pos()
{
    return _position;
}

void Item_generic::size(int x, int y)
{
    _size.x = x;
    _size.y = y;
}

Size Item_generic::size()
{
    return _size;
}

void Item_generic::color(int r, int g, int b)
{
    _color = {r, g, b};
}

Color Item_generic::color()
{
    return _color;
}
