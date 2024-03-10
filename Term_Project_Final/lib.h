#ifndef GAME_LIB_H
#define GAME_LIB_H

enum Dir
{
    quit,
    left,
    right,
    up,
    down
};

class Random
{
private:
    unsigned hold;

public:
    Random(long _Seed = 1l) : hold(_Seed) {}
    void setSeed(long _Seed) { hold = _Seed; }
    long operator()() { return (hold = hold * 214013u + 2531011u) & 0x7fffffffl; }
};
extern Random random;

template <typename T>
inline void swap(T &a, T &b)
{
    T t(a);
    a = b, b = t;
}

#endif
