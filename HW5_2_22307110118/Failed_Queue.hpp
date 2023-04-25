#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue
{
private:
	// 不变式：[head, tail]内是链表的数据
	struct node
	{
		int data;
		node *next;
		node(const int &_d = int(), node *_n = nullptr) : data(_d), next(_n) {}
	};
	node *head, *tail;
	size_t count;

public:
	Queue() : count(0) { tail = new node(); head = tail->next; }
	~Queue() { clear(), delete tail; }
	bool empty() const { return !count; }
	bool full() const { return count >= 50; }
	int size() const { return count; }
	void clear();
	void pop();
	void push(const int &val)
	{
		tail = tail->next = new node(val);
		++count;
	}
	void print();
	int &front() { return head->data; }
	int front() const { return head->data; }
};

void Queue::pop()
{
	if (empty())
		throw;
	node *p = head->next;
	delete head;
	head = p;
	--count;
}

void Queue::clear()
{
	for (node *p = head, *t; p; p = t)
		t = p->next, delete p;
	head = nullptr;
	tail = head;
	count = 0;
}

void Queue::print()
{
	for (node *p = head; p; p = p->next)
		std::cout << p->data << ' ';
	std::cout << std::endl;
}
#endif
