#pragma once

#include <ctime>
#include <cstdio>
#include <cstring>
#include "lib.h"
#include "Board.h"

class Game2048
{
private:
    Board board;
    const time_t begin; // the game's ending time needn't be stored.

public:
    Game2048() : board(), begin(time(NULL)) { puts("Welcome to the game of 2048!"); }
    ~Game2048()
    {
        time_t last = time(NULL) - begin;
        puts("Game over.");
        if (FILE *fp = fopen("game2048.csv", "a"))
            fprintf(fp, "%s,%lld,%d\n", strtok(ctime(&begin), "\n"), (long long)last, score()), fclose(fp);
        else
            puts("Failed to open \"game2048.csv\".");
    }
    static Dir queryDirection()
    {
        static char buf[1024];
        for (;;)
            switch (printf("(↑:u) (↓:d) (←:l) (→:r) (quit:q):"),
                    scanf("%s", buf), buf[0])
            {
            case 'u':
                return up;
            case 'l':
                return left;
            case 'd':
                return down;
            case 'r':
                return right;
            case 'q':
                return quit;
            default:
                break;
            }
    }
    unsigned score() const { return board.score(); }
    void printBoard() const { board.print(), printf("Your score: %d\n", score()); }
    bool end() const { return board.end(); }
    bool move(Dir dir) { return board.move(dir); }
    bool randomInsert() { return board.randomInsert(); }
};
