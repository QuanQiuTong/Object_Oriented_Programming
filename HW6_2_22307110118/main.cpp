#include "Queue.h"
#include <iostream>
int main()
{
	using std::cout;
	using std::endl;
	Queue<unsigned> q;
	unsigned in = 1, out = 0;

	cout << "\t\t"
		 << "食堂某个窗口高峰期的排队状况模拟：\n"
		 << "0s：第1人进队." << endl;
	q.push(0);
	for (size_t i = 1; q.size() < 50; i++)
	{
		if (i % 8 == 0)
			q.push(i),
				cout << i << "s：第" << ++in << "人进队." << endl;
		if (i % 25 == 0)
			q.pop(),
				cout << "\t\t" << i << "s：第" << ++out << "人出队." << endl;
	}

	cout << "\t\t"
		 << "该窗口排队人数已达到50人！请分流！" << '\n'
		 << '\t'
		 << "队首人员于" << q.front() << "s入队." << '\n'
		 << '\t'
		 << "队尾人员于" << q.back() << "s入队." << endl;

	Queue<unsigned> q1(q), q2; // 假设q是原队列
	q1.print();
	q2 = q1;
	q2.print();
	return 0;
}
