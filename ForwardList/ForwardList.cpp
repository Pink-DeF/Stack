#include "ForwardList.h"

ForwardList::ForwardList() : head(nullptr), size_list(0) {}
ForwardList::ForwardList(ValueType n) : head(nullptr), size_list(1)
{
	head = new Node(n, nullptr);
}

ForwardList::ForwardList(const ForwardList& other)
    	   : head(nullptr), size_list(0)
{
    Node* current = other.head;
    while (current != nullptr)
	{
        push_back(current->_value);
        current = current->_next;
    }
}
ForwardList& ForwardList::operator=(const ForwardList& other)
{
    if (this != &other)
	{
        ForwardList temp(other);
        std::swap(head, temp.head);
        std::swap(size_list, temp.size_list);
    }
    return *this;
}

ForwardList::~ForwardList()
{
	while (head != nullptr) { pop_front(); }
}

void ForwardList::push_back(ValueType value)
{
	if (!head)
	{
        push_front(value);
        return;
    }
    Node* current = head;
    while (current->_next) {
        current = current->_next;
    }
    current->_next = new Node(value, nullptr);
    size_list++;
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
		if (empty()){ throw std::out_of_range("Error 121. List is empty"); }
		return head->_value;
	}
const ValueType& ForwardList::front() const
	{ 
		if (empty()){ throw std::out_of_range("Error 122. List is empty"); }
		return head->_value;
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
