/**
 * @file Winmain.cpp
 * @author Quantong Fu (fqt1550887523@outlook.com)
 * @brief For Windows® operating system.
 * @version 1.0
 * @date 2023-06-08
 * 
 */
#include <conio.h>
#include <windows.h>
#include <cstdlib>

#include "lib.h"
#include "Board.h"
#include "Game2048.h"

inline Dir queryDirection()
{
    for (;;)
        switch (printf("(↑:u) (↓:d) (←:l) (→:r) (quit:q):"), getch())
        {
        case 'w':
            return up;
        case 'a':
            return left;
        case 's':
            return down;
        case 'd':
            return right;
        case 'q':
            return quit;
        default:
            break;
        }
}

int main()
{
    system("cls");
    Game2048 g;
    Dir dir;
    g.randomInsert();
    do
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 1});
        g.randomInsert();
        g.printBoard();
        dir = queryDirection();
    } while (g.move(dir));
    return 0;
}