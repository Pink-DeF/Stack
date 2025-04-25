#pragma once
#include "Stack.h"
#include "StackImplementation.h"

Stack::Stack(StackContainer container = StackContainer::Vector)
    : _containerType(container)
{
	switch (container)
	{
	case StackContainer::Vector:
		_pimpl = new VectorContainer();
		break;
	case StackContainer::List:
		_pimpl = new ListContainer();
		break;
	default:
		break;
	}
}
Stack::Stack(const ValueType* valueArray, const size_t arraySize,
	StackContainer container = StackContainer::Vector)
	: _containerType(container)
{
	switch (container)
	{
	case StackContainer::Vector:
		_pimpl = new VectorContainer(valueArray, arraySize);
		break;
	case StackContainer::List:
		_pimpl = new ListContainer(valueArray, arraySize);
		break;
	default:
		break;
	}
}

Stack::Stack(const Stack& copyStack)
{
	*this = copyStack;
}
Stack& Stack::operator=(const Stack& copyStack)
{
	if (this != &copyStack)
	{
		delete _pimpl;
		switch (_containerType)
		{
		case StackContainer::Vector:
		{
			_pimpl = new VectorContainer(*static_cast<VectorContainer*>(copyStack._pimpl));
			break;
		}
		case StackContainer::List:
		{
			_pimpl = new ListContainer(*static_cast<ListContainer*>(copyStack._pimpl));
			break;
		}
		}

		_containerType = copyStack._containerType;
	}
	return  *this;
}

Stack::Stack(Stack&& moveStack) noexcept
{
	Stack(moveStack);
	delete _pimpl;
}
Stack& Stack::operator=(Stack&& moveStack) noexcept
{
	if (this == &moveStack) { return *this; }

	delete _pimpl;
	_pimpl = moveStack._pimpl;

	_containerType = moveStack._containerType;
	moveStack._pimpl = nullptr;

	return *this;


}

Stack::~Stack() { delete _pimpl; }


void Stack::push(const ValueType& value) { return _pimpl->push(value); }

void Stack::pop() { return _pimpl->pop(); }

const ValueType& Stack::top() const { return _pimpl->top(); }

bool Stack::isEmpty() const { return _pimpl->isEmpty(); }
 
size_t Stack::size() const { return _pimpl->size(); }