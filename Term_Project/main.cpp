#include "lib.h"
#include "Board.h"
#include "Board.cpp"
#include "Game2048.h"
int main()
{
    random.setSeed(time(NULL));
    puts("Welcome to the game of 2048!");
    for (Game2048 g; !g.end(); g.randomInsert())
    {
        g.printBoard();
        printf("Your score: %d\n", g.score());
        Dir dir = g.queryDirection();
        if (dir == quit)
            break;
        g.move(dir);
    }
    return 0;
}