#pragma once

#include <cstring>
#include <iostream>
#include "Vec.h"

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);
    friend std::ostream &operator<<(std::ostream &, const Str &);
    friend Str operator+(const Str &s, const Str &t) { return Str(s) += t; }
    friend bool operator<(const Str &, const Str &);
    friend bool operator==(const Str &s, const Str &t) { return s.size() == t.size() && memcmp(s.data.begin(), t.data.begin(), s.size()) == 0; }

private:
    Vec<char> data;

public:
    typedef Vec<char>::size_type size_type;
    Str(){};
    Str(size_type n, char c) : data(n, c) {}
    Str(const char *cp) { std::copy(cp, cp + strlen(cp), std::back_inserter(data)); }
    template <class In>
    Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const { return data[i]; }
    size_type size() const { return data.size(); }
    Str &operator+=(const Str &s)
    {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }
};
std::istream &operator>>(std::istream &is, Str &s)
{
    s.data.clear();
    char c;
    while (is.get(c) && isspace(c))
        ;
    if (is)
    {
        do
            s.data.push_back(c);
        while (is.get(c) && !isspace(c));
        if (is)
            is.unget();
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}
bool operator<(const Str &s, const Str &t)
{
    int r = memcmp(s.data.begin(), t.data.begin(), std::min(s.size(), t.size()));
    return r ? r < 0 : s.size() < t.size();
}