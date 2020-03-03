#include "game.h"
#include <algorithm>
#include <cstdlib>

#include "stdio.h"

Game::Game(int squares) : _squares(squares), _moves(0)
{
    d_open(squares * size_square, squares * size_square, "pu33zle!");

    grid = new Item_square * [squares];
    
    for (int i = 0; i < squares; i++)
    {
        grid[i] = new Item_square [squares];
    }

    auto * numbers = new int [squares * squares];

    for (int i = 0; i < squares * squares - 1; i++)
    {
        numbers[i] = i + 1;
    }

    srand(time(nullptr));

    std::random_shuffle(&numbers[0], &numbers[squares * squares - 2]);

    auto blank_x = rand() % squares;
    auto blank_y = rand() % squares;

    auto withdraw_index = 0;

    for (int i = 0; i < squares; i++)
    {
        for (int j = 0; j < squares; j++)
        {
            auto * current = &grid[i][j];

            if (i == blank_x && j == blank_y)
            {
                current->color(0, 0, 0);
            }
            else
            {
                auto number = numbers[withdraw_index++];
                
                current->color(20 + rand() % 155, 20 + rand() % 155, 20 + rand() % 155);
                current->number(number);
                current->size(size_square, size_square);
                current->pos(i * size_square, j * size_square);

                current->draw();
            }
        }
    }

    time(&_start);

    d_flush();
}

Game::~Game()
{
    for (int i = 0; i < _squares; i++)
    {
        delete [] grid[i];
    }

    delete grid;
}

void Game::react(Key key)
{
    auto [x, y] = _find_blank(); 

    if (key == Key::UP && y < (_squares - 1))
    {   
        _animate(&grid[x][y + 1], 0, -1);

        _swap(x, y, x, y + 1);
    }
    else if (key == Key::RIGHT && x > 0)
    {
        _animate(&grid[x - 1][y], 1, 0);

        _swap(x, y, x - 1, y);
    }
    else if (key == Key::DOWN && y > 0)
    {
        _animate(&grid[x][y - 1], 0, 1);

        _swap(x, y, x, y - 1);
    }
    else if (key == Key::LEFT && x < (_squares - 1))
    {
        _animate(&grid[x + 1][y], -1, 0);

        _swap(x, y, x + 1, y);
    }
}

bool Game::end()
{
    auto count = 0;

    for (int i = 0; i < _squares; i++)
    {
        for (int j = 0; j < _squares; j++)
        {
            if (grid[j][i].number() == i * _squares + j + 1)
            {
                count++;

                if (count == (_squares * _squares - 1)) return true;
            }
        }
    }

    return false;
}

void Game::info()
{
    time(&_end);
    auto diff = (int) difftime (_end, _start);

    d_clear(0, 0, _squares * size_square, _squares * size_square);

    char buffer[64];

    d_color(255, 255, 255);

    d_text(0, 20, "GG EZ!");

    snprintf(buffer, 64, "Moves = %d", _moves);
    d_text(0, 40, (const char *) buffer);

    snprintf(buffer, 64, "Time = %d [s]", diff);
    d_text(0, 60, (const char *) buffer);

    d_flush();
}

//---------------------------------------------| info |---------------------------------------------//

void Game::_animate(Item_square * square, int dx, int dy)
{
    for (int i = 0; i < size_square; i++)
    {
        square->move(dx, dy);
        d_sleep(5);
        d_flush();
    }
}

Position Game::_find_blank()
{
    for (int i = 0; i < _squares; i++)
    {
        for (int j = 0; j < _squares; j++)
        {
            auto * current = &grid[i][j];

            if (current->color().r == 0 &&
                current->color().g == 0 &&
                current->color().b == 0)
            {
                return {i, j};
            }
        }
    }
}

void Game::_swap(int x1, int y1, int x2, int y2)
{
    auto s1 = grid[x1][y1];
    auto s2 = grid[x2][y2];

    grid[x1][y1] = s2;
    grid[x2][y2] = s1;

    _moves++;
}