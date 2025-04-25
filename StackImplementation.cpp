#pragma once
#include "StackImplementation.h"

//ListContainer

ListContainer::ListContainer(const ValueType* valueArray, const size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        list.push_front(valueArray[i]);
    }
}

ListContainer::ListContainer(const ListContainer& copyList) { list = copyList.list; }
ListContainer& ListContainer::operator=(const ListContainer& copyList)
{
    if (this != &copyList) { list = copyList.list; }
    return  *this;
}

void ListContainer::push(const ValueType& value) { list.push_front(value); }
void ListContainer::pop() { list.pop_front(); }
const ValueType& ListContainer::top() const { return (list.front())->value; }

bool ListContainer::isEmpty() const { return list.empty(); };
size_t ListContainer::size() const { return list.size(); };


//VectorContainer

VectorContainer::VectorContainer(const ValueType* valueArray, const size_t arraySize) : vec(Vector(valueArray, arraySize)) {}

VectorContainer::VectorContainer(const VectorContainer& copyStack) { vec = copyStack.vec; }
VectorContainer& VectorContainer::operator=(const VectorContainer& copyStack)
{
    if (this != &copyStack) { vec = copyStack.vec; }
    return *this;
}

void VectorContainer::push(const ValueType& value)  { vec.pushBack(value); }

void VectorContainer::pop()  { vec.popBack(); }

const ValueType& VectorContainer::top() const  { return vec[size() - 1]; }

bool VectorContainer::isEmpty() const  { return vec.size() == 0; }

size_t VectorContainer::size() const  { return vec.size(); }