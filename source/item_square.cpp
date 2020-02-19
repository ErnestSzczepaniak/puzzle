#include "item_square.h"
#include "display.h"

Item_square::Item_square(int number)
:
_number(number)
{

}

Item_square::~Item_square()
{

}

void Item_square::draw()
{
    d_color(_color.r, _color.g, _color.b);

    d_square(_position.x + 1, _position.y + 1, size_square - 1, size_square - 1);

    for (int i = 1; i < 10; i++)
    {
        d_color(_color.r - i, _color.g - i, _color.b - i);

        d_line(_position.x + i, _position.y + i, _position.x + size_square - i, _position.y + i);
        d_line(_position.x + i, _position.y + i, _position.x + i, _position.y + size_square - i);

        d_color(_color.r + i, _color.g + i, _color.b + i);
        d_line(_position.x + size_square - i, _position.y + i, _position.x + size_square - i, _position.y + size_square - i);
        d_line(_position.x + i, _position.y + size_square - i, _position.x + size_square - i, _position.y + size_square - i);
    }

    d_color(0, 0, 0);

    if (_number < 10)
    {
        char buffer[] = {48, 0};
        buffer[0] += _number;

        d_text(_position.x + 25, _position.y + 36, (const char *) buffer);
    }
    else if (_number < 100)
    {
        char buffer[] = {48, 48, 0};

        auto tenths = _number / 10;
        auto units = _number % 10;

        buffer[0] += tenths;
        buffer[1] += units;

        d_text(_position.x + 20, _position.y + 36, (const char *) buffer);
    }
}

void Item_square::clear()
{
    d_clear(_position.x, _position.y, _size.x, _size.y);
}

void Item_square::number(int value)
{
    _number = value;
}

int Item_square::number()
{
    return _number;
}

