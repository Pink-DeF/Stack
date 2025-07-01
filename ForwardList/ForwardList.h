#pragma once
#include <cstddef>
#include <iostream>

using ValueType = double;

class ForwardList
{
private:
	struct Node
	{
		Node(ValueType value, Node *next)
		{
			_value = value;
			_next = next;
		}

		ValueType _value;
		Node* _next;
	};


public:
	ForwardList();
	ForwardList(ValueType value);
	~ForwardList();

	void push_front(ValueType value);
	void pop_front();
	ValueType& front();
	const ValueType& front() const;

	size_t size() const;
	bool empty() const;
	void display();
	void clear();

private:
	
	Node* head;
	size_t size_list;
};
