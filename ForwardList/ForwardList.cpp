#include "ForwardList.h"

ForwardList::ForwardList() : head(nullptr), size_list(0) {}
ForwardList::ForwardList(ValueType n) : head(nullptr), size_list(1)
{
	head = new Node(n, nullptr);
}
ForwardList::~ForwardList()
{
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
	if (empty()){ throw std::out_of_range("Error 113. List is empty"); }

	Node* temp = head->_next;
	delete head;
	head = temp;
	size_list--;

}

ValueType& ForwardList::front()
	{ 
		if (empty()){ throw std::out_of_range("Error 111. List is empty"); }
		return head->value;
	}
const ValueType& ForwardList::front() const
	{ 
		if (empty()){ throw std::out_of_range("Error 112. List is empty"); }
		return head->value;
	}

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
		std::cout << temp->_value << " // ";
		temp = temp->_next;
	}
	std::cout << std::endl;
}
void ForwardList::clear()
{
	while (head != nullptr)
	{
        Node* temp = head;
        head = head->_next;
        delete temp;
	}
	size_list = 0;
}
