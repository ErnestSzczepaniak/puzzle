#include "game.h"
#include "stdio.h"

int main()
{
    Game game(3);

    while(1)
    {
        auto key = d_input_wait();

        if (key == 82) game.react(Key::UP);
        else if (key == 84) game.react(Key::DOWN);
        else if (key == 81) game.react(Key::LEFT);
        else if (key == 83) game.react(Key::RIGHT);

        if (game.end()) break;
    }

    game.info();

    while(1);
}

// czwartek 8 


