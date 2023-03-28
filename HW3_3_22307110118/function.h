#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <cstdlib>
#include <algorithm>
namespace fqt // 参照 SGI-STL
{
    template <class InputIterator, class T>
    T accumulate(InputIterator first, InputIterator last, T init)
    {
        for (; first != last; ++first)
            init += *first;
        return init;
    }

    template <class ForwardIterator>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
    {
        if (first == last)
            return first;
        ForwardIterator result = first;
        while (++first != last)
            if (*result < *first)
                result = first;
        return result;
    }

    template <class ForwardIterator>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
    {
        if (first == last)
            return first;
        ForwardIterator result = first;
        while (++first != last)
            if (*first < *result)
                result = first;
        return result;
    }

} // namespace fqt

template <class container>
void print(container con)
{
    typename container::iterator it = con.begin();
    std::cout << *it++;
    for (; it != con.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

// 失败的尝试，要进一步学习如何把正确地把函数类型写进模板参数里（我看SGI-STL也没使用<functional>来做这个事啊……）
/* template<class T,class rand_func>
vector<T> random_vector(T x,rand_func r)
{
    vector<T> v;
    for (int i = 0; i != 10; ++i)
        v.push_back(r());
    return v;
} */
#endif
