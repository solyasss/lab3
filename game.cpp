#include "game.h"
#include <iostream>
#include <ctime>

using namespace std;

Game::~Game()
{
    for (int i = 0; i < 6; i++)
    {
        delete[] reels[i];
    }
    delete[] reels;
    delete[] lengths;
    delete[] first_element;
    delete[] last_element;
}

Game::Game(int g)
{
    max_length = g;
    reels = new int *[3];
    lengths = new int[3];
    first_element = new int[3];
    last_element = new int[3];
    for (int i = 0; i < 3; i++)
    {
        reels[i] = new int[max_length];
        clear(i);
    }
}

void Game::clear(int index)
{
    lengths[index] = 0;
    first_element[index] = 0;
    last_element[index] = -1;
}

bool Game::empty(int index)
{
    return lengths[index] == 0;
}

bool Game::full(int index)
{
    return lengths[index] == max_length;
}

int Game::get_count(int index)
{
    return lengths[index];
}

void Game::push(int index, int value)
{
    if (!full(index))
    {
        last_element[index] = (last_element[index] + 1) % max_length;
        reels[index][last_element[index]] = value;
        lengths[index]++;
    }
}

int Game::swap(int index)
{
    if (!swap(index))
    {
        int combination = reels[index][first_element[index]];
        bool victory = true;
        for (int i = 1; i < max_length; i++)
        {
            int current = (first_element[index] + i) % max_length;
            if (reels[index][current] != combination)
            {
                victory = false;
                break;
            }
        }

        clear(index);

        return victory ? 1 : 0;
    }
    else
    {
        return -1;
    }
}

int Game::get_value(int index, int element)
{
    if (element >= 0 && element < lengths[index])
    {
        int current = (first_element[index] + element) % max_length;
        return reels[index][current];
    }
    return -1;
}
