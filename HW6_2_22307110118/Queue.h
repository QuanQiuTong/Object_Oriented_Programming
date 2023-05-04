#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
template <typename T>
class Queue
{
public:
	typedef size_t size_type;

private:
	// 不变式：[head, tail]内是链表的数据
	struct node
	{
		T value;
		node *next;
		explicit node(const T &_d, node *_n = 0) : value(_d), next(_n) {}
	};
	node *head, *tail;
	size_type count;

public:
	Queue() : head(0), tail(0), count(0) { std::cout << "default constructor called.\n"; }
	Queue(const Queue<T> &other) : head(0), tail(0), count(0)
	{
		std::cout << "copy constructor called.\n";
		for (node *p = other.head; p; p = p->next)
			push(p->value);
	}
	Queue &operator=(const Queue<T> &other)
	{
		std::cout << "operator=() called.\n";
		clear();
		for (node *p = other.head; p; p = p->next)
			push(p->value);
		return *this;
	}
	~Queue() { std::cout << "destructor called.\n", clear(); }
	bool empty() const { return !count; }
	size_type size() const { return count; }
	T &front() { return head->value; }
	T front() const { return head->value; }
	T back() const { return tail->value; }
	void clear()
	{
		for (node *p = head, *t; p;)
			t = p, p = p->next, delete t;
		tail = head = 0;
		count = 0;
	}
	void pop()
	{
		node *p = head;
		head = head->next, delete p, --count;
	};
	void push(const T &val) { tail = (tail ? tail->next : head) = new node(val), ++count; }
	void print() const
	{
		size_t cnt = 0;
		for (node *p = head; p; p = p->next)
			std::cout << p->value << (++cnt % 10 ? ' ' : '\n');
		std::cout << std::endl;
	}
};
#endif
