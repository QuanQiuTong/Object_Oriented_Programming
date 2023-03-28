#include "find.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

vector<int> random_vector()
{
	vector<int> v;
	for (int i = 0; i != 13; ++i)
		v.push_back(rand() % 20);
	return v;
}
int main()
{
	srand(time(NULL));
	vector<int> vec_0 = random_vector(), vec_1 = random_vector();
	list<string> lis_0, lis_1;

	cout << "Random integer vector 1:" << endl; // 容器1中有重复元素怎么办？
	print(vec_0);
	cout << "Random integer vector 2:" << endl;
	print(vec_1);
	cout << "Vector in common:" << endl;
	print(find_same(vec_0, vec_1));

	cout << "Enter some words for string list 1:" << endl;
	for (string s; cin >> s;)
		lis_0.push_back(s);
	cin.clear();
	cout << "Enter some words for string list 2:" << endl;
	for (string s; cin >> s;)
		lis_1.push_back(s);
	cin.clear();
	cout << "List in commom:" << endl;
	print(find_same(lis_0, lis_1));
	return 0;
}
