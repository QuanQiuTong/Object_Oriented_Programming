#include "lib.h"
#include "Board.h"
#include "Board.cpp"
#include "Game2048.h"
int main()
{
    random.setSeed(time(NULL));
    Dir dir;
    Game2048 g;
    g.randomInsert();
    do
    {
        g.randomInsert();
        g.printBoard();
        dir = g.queryDirection();
    } while (g.move(dir));
    return 0;
}