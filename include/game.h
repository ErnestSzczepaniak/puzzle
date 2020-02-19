#ifndef _game_h
#define _game_h

/*
* project:	puzzle
* file:		game.h
* author:	en2
* date:		15-02-2020
*/

#include "time.h"
#include "display.h"
#include "item_square.h"

enum class Key : unsigned char
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}; /* enum: Key */

class Game
{
public:
    Game(int squares);
    ~Game();

    void react(Key key);

    bool end();
    void info();

    Item_square ** grid;

protected:
    void _animate(Item_square * square, int dx, int dy);
    Position _find_blank();

    void _swap(int x1, int y1, int x2, int y2);

private:
    int _squares;
    int _moves;
    time_t _start;
    time_t _end;

}; /* class: Game */

#endif /*define: game_h*/