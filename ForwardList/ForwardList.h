#pragma once
#include <cstddef>
#include <iostream>

using ValueType = double;

class ForwardList
{
private:
	struct Node
	{
		ValueType value;
		Node* back;

		Node(ValueType _value, Node *_back)
		{
			value = _value;
			back = _back;
		}
	};


public:
	ForwardList();
	ForwardList(ValueType value);
	~ForwardList();

	void push_front(ValueType value);
	void pop_front();
	Node* front();
	Node* front() const;

	size_t size() const;
	bool empty() const;
	void display();
	void clear();

private:
	
	Node* head;
	size_t size_list;
};
