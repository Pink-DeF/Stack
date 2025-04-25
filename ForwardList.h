#pragma once

using ValueType = double;

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

class ForwardList
{
private:
	Node* head;
	size_t size_list;
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
};