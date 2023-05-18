#include "lib.h"
#include "Board.h"
#include "Board.cpp"
#include "Game2048.h"
#if 0
int main()
{
    random.setSeed(time(NULL));
    puts("Welcome to the game of 2048!");
    Game2048 g;
    Dir dir;
    g.randomInsert();
    do
    {
        g.randomInsert();
        g.printBoard();
        printf("Your score: %d\n", g.score());
        if ((dir = g.queryDirection()) == quit)
            break;
        g.move(dir);
    } while ((1l << dir) & g.end());
    return 0;
}
#endif

#define read() ({int x,c,f=1;while((c=getchar())<48||57<c)if(c=='-')f=-1;for(x=c^48;47<(c=getchar())&&c<58;x=x*10+(c^48));x*f; })
int main()
{
    Board b;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            b.debug(i, j, read());
    Dir dir;
    do
    {
        b.randomInsert();
        b.print();
        printf("Your score: %d\n", b.score());
        if ((dir = Game2048::queryDirection()) == quit)
            break;
        b.move(dir);
    } while ((1l << dir) & b.end());
}
