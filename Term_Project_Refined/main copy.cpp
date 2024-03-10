#include "lib.h"
#include "Board.h"
#include "Board.cpp"
#include "Game2048.h"
int main()
{
    random.setSeed(time(NULL));
    puts("Welcome to the game of 2048!");
    Game2048 g;
    g.printBoard();
    printf("Your score: %d\n", g.score());
    for (Dir dir; (dir = g.queryDirection()) && (1l << dir) & g.end(); g.move(dir), g.randomInsert())
    {
        g.printBoard();
        printf("Your score: %d\n", g.score());
    }
    return 0;
}