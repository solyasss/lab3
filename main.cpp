#include "game.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    Game game(10);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int value = rand() % 3 + 1;
            game.push(i, value);
        }

        cout << " Your reel " << i + 1 << ": ";
        int count = game.get_count(i);
        for (int j = 0; j < count; j++)
        {
            cout << game.get_value(i, j) << " ";
        }

        int result = game.swap(i);
        if (result == 1)
        {
            cout << "Victory!" << endl;
        }
        else if (result == 0)
        {
            cout << " You lose!" << endl;
        }
        else
        {
            cout << "You didnt swap" << endl;
        }
    }

    return 0;
}
