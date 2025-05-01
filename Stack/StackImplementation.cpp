#include "StackImplementation.h"

//ListContainer

ListContainer::ListContainer(const ValueType* valueArray, const size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        _list.push_front(valueArray[i]);
    }
}

ListContainer::ListContainer(const ListContainer& copyList) { _list = copyList._list; }
ListContainer& ListContainer::operator=(const ListContainer& copyList)
{
    if (this != &copyList) { _list = copyList._list; }
    return  *this;
}

void ListContainer::push(const ValueType& value) { _list.push_front(value); }
void ListContainer::pop() { _list.pop_front(); }
const ValueType& ListContainer::top() const { return (_list.front())->value; }

bool ListContainer::isEmpty() const { return _list.empty(); };
size_t ListContainer::size() const { return _list.size(); };

//VectorContainer

VectorContainer::VectorContainer(const ValueType* valueArray, const size_t arraySize) 
	: _vector(Vector(valueArray, arraySize)) {}

VectorContainer::VectorContainer(const VectorContainer& copyStack) { _vector = copyStack._vector; }
VectorContainer& VectorContainer::operator=(const VectorContainer& copyStack)
{
    if (this != &copyStack) { _vector = copyStack._vector; }
    return *this;
}

void VectorContainer::push(const ValueType& value)  { _vector.pushBack(value); }

void VectorContainer::pop()  { _vector.popBack(); }

const ValueType& VectorContainer::top() const  { return _vector[size() - 1]; }

bool VectorContainer::isEmpty() const  { return _vector.size() == 0; }

size_t VectorContainer::size() const  { return _vector.size(); }
