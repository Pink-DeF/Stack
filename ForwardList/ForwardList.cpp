#include "ForwardList.h"

ForwardList::ForwardList(ValueType n) : size_list(1)
{
	head = new Node(n, nullptr);
}
ForwardList::~ForwardList() {
	while (head != nullptr) { pop_front(); }
}


void ForwardList::push_front(ValueType value)
{
	Node* newNode = new Node{ value, head };
	head = newNode;
	size_list++;
}
void ForwardList::pop_front()
{
	if (head != nullptr)
	{
		Node* temp = head->back;
		delete head;
		head = temp;
	}

}
Node* ForwardList::front() { return head; }
Node* ForwardList::front() const { return head; }

size_t ForwardList::size() const
{
	return size_list;
}
bool ForwardList::empty() const
{
	return head == nullptr;
}
void ForwardList::display()
{
	Node* temp = head;
	while (temp)
	{
		std::cout << temp->value << " // ";
		temp = temp->back;
	}
	std::cout << std::endl;
}
void ForwardList::clear()
{
	while (head != nullptr)
	{
		pop_front();
	}
}