#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <algorithm>

class Date
{
public:
    enum
    {
        valid = 0,
        invalid_month,
        invalid_day
    };
    Date() : y(0), m(0), d(0) {}
    Date(int y_, int m_, int d_) : y(y_), m(m_), d(d_) {}
    Date(std::istream &in) { in >> y >> m >> d; }
    inline int year() const { return y; }
    inline int month() const { return m; }
    inline int day() const { return d; }
    void print() const { std::cout << y << "年" << m << "月" << d << "日"; }
    void year_increase();
    void month_increase();
    void day_increase();

private:
    bool leap(int y) const { return y % 400 == 0 || (y % 4 == 0 && y % 100); }
    signed check() const; // enum is signed int.
    int y, m, d;
};

int inteval(const Date d1, const Date d2);

#endif
