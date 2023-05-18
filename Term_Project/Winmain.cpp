#include <conio.h>
#include <cstdlib>

#include "lib.h"
#include "Board.h"
#include "Board.cpp"
#include "Game2048.h"

inline Dir queryDirection()
{
    for (;;)
        switch (getch())
        {
        case 'w':
            return up;
        case 'a':
            return left;
        case 's':
            return down;
        case 'd':
            return right;
        case 'e':
            return quit;
        default:
            break;
        }
}

int main()
{
    Game2048 g;
    Dir dir;
    g.randomInsert();
    do
    {
        system("cls");
        g.randomInsert();
        g.printBoard();
        dir = queryDirection();
    } while (g.move(dir));
    return 0;
}