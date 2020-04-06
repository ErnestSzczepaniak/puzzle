#include "game.h"
#include "stdio.h"


int asd[] = 
{
    374, 375, 352, 300, 272, 354, 350, 375, 373, 275, 367, 276, 357, 271, 373, 366, 275, 300, 272, 271, 367, 350, 362, 375, 350, 362, 374
};



int main()
{
    constexpr auto size = sizeof(asd)/sizeof(int);

    for (int i = 0; i < size; i++)
    {
        asd[i] -= 259;

        printf("%d ", asd[i]);
    }
    
    char si[size + 1] = {0};
    
    for (int i = 0; i < size; i++)
    {
        si[i] = asd[i];
    }

    fflush(nullptr);

    while(1)
    {
        
    }
    


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

