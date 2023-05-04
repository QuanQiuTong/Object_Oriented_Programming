#include "Queue.h"
#include <iostream>
int main()
{
	using std::cout;
	using std::endl;
	Queue<unsigned> q;
	unsigned in = 1, out = 0;

	cout << "\t\t"
		 << "ʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺\n"
		 << "0s����1�˽���." << endl;
	q.push(0);
	for (size_t i = 1; q.size() < 50; i++)
	{
		if (i % 8 == 0)
			q.push(i),
				cout << i << "s����" << ++in << "�˽���." << endl;
		if (i % 25 == 0)
			q.pop(),
				cout << "\t\t" << i << "s����" << ++out << "�˳���." << endl;
	}

	cout << "\t\t"
		 << "�ô����Ŷ������Ѵﵽ50�ˣ��������" << '\n'
		 << '\t'
		 << "������Ա��" << q.front() << "s���." << '\n'
		 << '\t'
		 << "��β��Ա��" << q.back() << "s���." << endl;

	Queue<unsigned> q1(q), q2; // ����q��ԭ����
	q1.print();
	q2 = q1;
	q2.print();
	return 0;
}
