#ifndef FIND_H
#define FIND_H
#include <iostream>
#include <cstdlib>
#include <algorithm>

template <class container>
container find_same(container input_0,container input_1)
{
	container v;
	for (typename container::iterator it = input_0.begin(); it != input_0.end(); ++it)
		if (std::find(input_1.begin(), input_1.end(), *it) != input_1.end())
			v.push_back(*it);
	return v;
}
template <class container>
void print(container con)
{
	typename container::iterator it = con.begin();
	for (std::cout << *it++; it != con.end(); ++it)
		std::cout << "  " << *it;
	std::cout << std::endl;
}
#endif
