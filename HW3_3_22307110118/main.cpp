#include "function.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

string r_string()
{
	string s;
	for (string::size_type len = rand() % 5 + 2; len--;)
		s += char(rand() % 26 + 'a');
	return s;
}
int main()
{
	srand(time(NULL));
	vector<int> v1;
	vector<double> v2;
	vector<string> v3;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 100);
		v2.push_back(int(1e6 * rand() / RAND_MAX) / 1e5); // 保证.5f
		v3.push_back(r_string());
	}

	// int list
	cout << "the integer list :" << endl;
	print(v1);
	cout << "the sum of the integer list:" << fqt::accumulate(v1.begin(), v1.end(), int()) << endl;
	// 最后一个参数是调用默认无参构造函数产生缺省值，可以保证类型正确。内置类型的缺省值皆为0。
	cout << "the max element in the integer list:" << *fqt::max_element(v1.begin(), v1.end()) << endl;
	cout << "the min element in the integer list:" << *fqt::min_element(v1.begin(), v1.end()) << endl
		 << endl;

	// double list
	cout << "the double list :" << endl;
	print(v2);
	cout << "the sum of the double list:" << fqt::accumulate(v2.begin(), v2.end(), double()) << endl;
	cout << "the max element in the double list:" << *fqt::max_element(v2.begin(), v2.end()) << endl;
	cout << "the min element in the double list:" << *fqt::min_element(v2.begin(), v2.end()) << endl
		 << endl;

	// string list
	cout << "the string list :" << endl;
	print(v3);
	cout << "the concatenation of the string list:" << fqt::accumulate(v3.begin(), v3.end(), string()) << endl;
	cout << "the max element in the string list:" << *fqt::max_element(v3.begin(), v3.end()) << endl;
	cout << "the min element in the string list:" << *fqt::min_element(v3.begin(), v3.end()) << endl;

	return 0;
}
