#ifndef _item_square_h
#define _item_square_h

/*
* project:	puzzle
* file:		item_square.h
* author:	en2
* date:		15-02-2020
*/

#include "item_generic.h"

static constexpr auto size_square = 60;

class Item_square : public Item_generic
{
public:
    Item_square(int number = 0);
    ~Item_square();

    void draw();
    void clear();

    void number(int value);
    int number();

private:
    int _number;

}; /* class: Item_square */


#endif /*define: item_square_h*/