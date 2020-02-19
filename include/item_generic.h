#ifndef _item_generic_h
#define _item_generic_h

/*
* project:	puzzle
* file:		item_generic.h
* author:	en2
* date:		15-02-2020
*/

struct Color
{
public:
    int r;
    int g;
    int b;
};

struct Position
{
    int x;
    int y;
};

struct Size
{
    int x;
    int y;
};

class Item_generic
{
public:
    Item_generic();
    ~Item_generic();

    virtual void draw() = 0;
    virtual void clear() = 0;

    void move(int diff_x, int diff_y);

    void pos(int x, int y);
    Position pos();

    void size(int x, int y);
    Size size();

    void color(int r, int g, int b);
    Color color();

protected:
    Position _position;
    Size _size;
    Color _color;

private:


}; /* class: Item_generic */

#endif /*define: item_generic_h*/