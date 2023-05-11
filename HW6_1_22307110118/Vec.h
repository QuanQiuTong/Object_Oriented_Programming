#pragma once
#include <memory>
#include <algorithm>
template <typename T>
class Vec
{
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T &reference;
    typedef const T &const_reference;

    Vec() : data(0), avail(0), limit(0) {}
    explicit Vec(size_type n, const T &t = T()) { create(n, t); }
    explicit Vec(const_iterator i, const_iterator j) { create(i, j); };
    Vec(const Vec &v) { create(v.begin(), v.end()); }
    Vec &operator=(const Vec &v)
    {
        create(v.begin(), v.end());
        return *this;
    }
    ~Vec() { clear(); }
    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }
    void push_back(const T &t)
    {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }
    void clear() { uncreate(); }
    size_type size() const { return avail - data; }
    bool empty() const { return size() == 0; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    iterator data, avail, limit;
    std::allocator<T> alloc;
    void create(size_type n, const T &val)
    {
        data = alloc.allocate(n);
        limit = avail = data + n;
        std::uninitialized_fill(data, limit, val);
    }
    void create(const_iterator i, const_iterator j)
    {
        data = alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, data);
    }
    void uncreate()
    {
        if (data)
        {
            for (iterator it = avail; it != data; --it)
                alloc.destroy(it);
            alloc.deallocate(data, limit - data);
        }
        data = avail = limit = 0;
    }
    void grow()
    {
        size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);
        clear();
        data = new_data;
        avail = new_avail;
        limit = data + new_size;
    }
    void unchecked_append(const T &val)
    {
        alloc.construct(avail++, val);
    }
};
#if 0
#include <stdio.h>
int main(int argc, char *argv[])
{
    Vec<int> v;
    for (size_t i = 0; i < 1000; i++)
    {
        v.push_back(i);
    }
    Vec<int> t(v);
    for (size_t i = 0; i < 1000; i++)
    {
        printf("%d ", t[i]);
    }
}
#endif
