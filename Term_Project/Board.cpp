#include "lib.h"
#include "Board.h"
#include <cstring>
#include <cstdio>

Board::Board() : _score(0u) { memset(grid, 0, sizeof grid), randomInsert(), randomInsert(); }
void Board::print() const
{
    puts("|-----|-----|-----|-----|");
    printf("|%4u |%4u |%4u |%4u |\n", grid[0][0], grid[0][1], grid[0][2], grid[0][3]);
    puts("|-----|-----|-----|-----|");
    printf("|%4u |%4u |%4u |%4u |\n", grid[1][0], grid[1][1], grid[1][2], grid[1][3]);
    puts("|-----|-----|-----|-----|");
    printf("|%4u |%4u |%4u |%4u |\n", grid[2][0], grid[2][1], grid[2][2], grid[2][3]);
    puts("|-----|-----|-----|-----|");
    printf("|%4u |%4u |%4u |%4u |\n", grid[3][0], grid[3][1], grid[3][2], grid[3][3]);
    puts("|-----|-----|-----|-----|");
}
bool Board::full() const
{
    for (int i = 0; i < 16; ++i)
        if (!grid[0][i])
            return false;
    return true;
}
bool Board::end() const
{
    Board t(*this);
    t.move(left), t.move(right), t.move(up), t.move(down);
    return t.full();
}
int Board::randomInsert()
{
    int empty[16], cnt = 0;
    for (int i = 0; i < 16; ++i)
        if (!grid[0][i])
            empty[cnt++] = i;
    if (cnt)
        grid[0][empty[random() % cnt]] = random() % 5 ? 2u : 4u;
    return cnt;
}
void Board::_left(unsigned g[])
{
    for (int i = 0, cnt = 0; i < 4; ++i)
        if (g[i])
            swap(g[cnt++], g[i]);
    // puts("*");print();
    if (!g[0])
        return;
    for (int i = 1; i < 4 && g[i]; ++i)
        if (g[i] == g[i - 1])
            _score += g[i - 1] += g[i], g[i] = 0;
    // puts("#");print();
    for (int i = 0, cnt = 0; i < 4; ++i)
        if (g[i])
            swap(g[cnt++], g[i]);
}
void Board::move(Dir d)
{
    switch (d)
    {
    case left:
        for (int i = 0; i < 4; ++i)
            _left(grid[i]);
        break;
    case right:
        for (int i = 0; i < 4; ++i)
        {
            swap(grid[i][0], grid[i][3]), swap(grid[i][1], grid[i][2]);
            _left(grid[i]);
            swap(grid[i][0], grid[i][3]), swap(grid[i][1], grid[i][2]);
        }
        break;
    case up:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
                swap(grid[i][j], grid[j][i]);
            _left(grid[i]);
            for (int j = 0; j < 4; ++j)
                swap(grid[i][j], grid[j][i]);
        }
        break;
    case down:
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3 - i; ++j)
                swap(grid[i][j], grid[3 - j][3 - i]);
        for (int i = 0; i < 4; ++i)
            _left(grid[i]);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3 - i; ++j)
                swap(grid[i][j], grid[3 - j][3 - i]);
        break;
    default:
        perror("Wrong direction");
    }
}

#if 0
#include <windows.h>
#define read() ({int x,c,f=1;while((c=getchar())<48||57<c)if(c=='-')f=-1;for(x=c^48;47<(c=getchar())&&c<58;x=x*10+(c^48));x*f; })

int main()
{
    Board b;
    // b.grid[0][0]=b.grid[0][1]=b.grid[0][2]=2;b.print();b.move(Board::left);
    for (char buf[1024];;)
    {
        system("cls");
        b.print();
        scanf("%s", buf);
        if (buf[0] == 'e')
        {
            int x = read(), y = read(), v = read();
            b.debug(x, y, v);
        }
        else if (buf[0] == 'i')
            b.randomInsert();
        else if (buf[0] == 'a')
            b.move(left);
        else if (buf[0] == 's')
            b.move(down);
        else if (buf[0] == 'd')
            b.move(right);
        else if (buf[0] == 'w')
            b.move(up);
    }
    return 0;
}
#endif