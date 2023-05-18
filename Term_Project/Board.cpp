#include "lib.h"
#include "Board.h"
#include <cstdio>

void Board::print() const
{
    puts("|-----|-----|-----|-----|");
    for (int i = 0; i < 4; ++i)
    {
        putchar('|');
        for (int j = 0; j < 4; ++j)
            printf(grid[i][j] ? "%4u |" : "     |", grid[i][j]);
        puts("\n|-----|-----|-----|-----|");
    }
}
bool Board::full() const
{
    for (int i = 0; i < 16; ++i)
        if (!grid[0][i])
            return false;
    return true;
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
    for (int i = 1; i < 4 && g[i]; ++i)
        if (g[i] == g[i - 1])
            _score += g[i - 1] += g[i], g[i] = 0;
    for (int i = 0, cnt = 0; i < 4; ++i)
        if (g[i])
            swap(g[cnt++], g[i]);
}
bool Board::move(Dir d)
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
        return false;
    }
    return !full();
}
bool Board::end() const
{
    {
        Board t(*this);
        t.move(down);
        if (!t.full())
            return false;
    }
    {
        Board t(*this);
        t.move(up);
        if (!t.full())
            return false;
    }
    {
        Board t(*this);
        t.move(right);
        if (!t.full())
            return false;
    }
    {
        Board t(*this);
        t.move(left);
        if (!t.full())
            return false;
    }
    return true;
}