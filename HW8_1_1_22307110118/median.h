#ifndef GUARD_median_h
#define GUARD_median_h
// 'median.h'
#include <vector>
#include <algorithm>
#include <stdexcept>


// compute the median of a 'vector<double>'
// note that calling this function copies the entire argument 'vector'
double median(std::vector<double> vec)
{
	typedef std::vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	std::sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

template <typename FIter>
typename FIter::value_type median(FIter b, FIter e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    std::vector<typename FIter::value_type> v(b, e);
    std::sort(v.begin(), v.end());
    typename std::vector<typename FIter::value_type>::size_type
        size = v.size(),
        mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template <typename T>
T median(T *b, T *e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    std::vector<T> v(b, e);
    std::sort(v.begin(), v.end());
    size_t size = v.size(), mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
template <typename T>
T median(const T *b, const T *e)
{
    if (b == e)
        throw std::domain_error("median of an empty range");

    std::vector<T> v(b, e);
    std::sort(v.begin(), v.end());
    size_t size = v.size(), mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
#endif
