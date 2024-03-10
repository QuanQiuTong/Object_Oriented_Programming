#pragma once

#include <cstring>

class Board
{
private:
    unsigned grid[4][4], _score;
    void _left(unsigned g[]);

public:
    Board() { memset(this, 0, sizeof(*this)); }
    unsigned score() const { return _score; }
    void print() const;
    bool full() const;
    int randomInsert();
    bool move(Dir d);
    bool end() const;
};
