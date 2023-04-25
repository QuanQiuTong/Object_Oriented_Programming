#include "Queue.h"
#include <iostream>
int main()
{
	using namespace std;
	Queue q,timing;
	/* int i,j;
	i=j=1; */

	cout << "\t\t"
		 << "食堂某个窗口高峰期的排队状况模拟：" << endl;
	cout << "0s：第1人进队." << endl;
	q.push(1);timing.push(0);
	for (size_t i = 1; !q.full(); i++)
	{
		if (i % 8 == 0)
		{
			q.push(i / 8 + 1);timing.push(i);
			cout << i << "s：第" << i / 8 + 1 << "人进队." << endl;
		}
		if (i % 25 == 0)
		{
			cout << "\t\t" << i << "s：第" << q.front() << "人出队." << endl;
			q.pop();timing.pop();
		}
		// cout<<"* ";q.print();
	}
	cout << "\t\t"
		 << "该窗口排队人数已达到50人！请分流！" << endl;
	{
		cout << "\t" << "队首人员于" << timing.front() << "s入队." << endl;
		int las;
		while (!timing.empty())
			las = timing.front(), timing.pop();
		cout << "\t" << "队尾人员于" << las << "s入队." << endl;
	}
	return 0;
}
