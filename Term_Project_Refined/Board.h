#pragma once

class Board
{
private:
    unsigned grid[4][4], _score;
    void _left(unsigned g[]);

public:
    Board();
    void debug(int x, int y, int val) { grid[x][y] = val; }
    unsigned score() const { return _score; }
    void print() const;
    bool full() const;
    long end() const;
    int randomInsert();
    void move(Dir d);
};
