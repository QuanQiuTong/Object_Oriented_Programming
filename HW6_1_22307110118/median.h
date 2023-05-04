#ifndef GUARD_median_h
#define GUARD_median_h
// 'median.h'
#include "Vec.h"

#include <algorithm>
#include <stdexcept>

template <typename FIter>
typename FIter::value_type median(FIter b, FIter e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    Vec<typename FIter::value_type> v(b, e);
    std::sort(v.begin(), v.end());
    typename Vec<typename FIter::value_type>::size_type
        size = v.size(),
        mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template <typename T>
T median(T *b, T *e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    Vec<T> v(b,e);
    std::sort(v.begin(), v.end());
    size_t size = v.size(), mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
template <typename T>
T median(const T *b,const T *e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    Vec<T> v(b,e);
    std::sort(v.begin(), v.end());
    size_t size = v.size(), mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
#endif
