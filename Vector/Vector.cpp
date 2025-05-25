#include <iostream>
#include <cstring>
#include "Vector.h"

static void clone(ValueType* _data, const ValueType* data, size_t size)
{
    if (_data == nullptr || data == nullptr || size == 0) { return; }
    for (size_t i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }
}
void realloc(Vector* object, size_t size)
{
    if (size == 0) { return; }
    while (object->_size + size > object->_capacity)
    {
        object->_capacity = object->_capacity ? static_cast<size_t>(object->_capacity * object->_multiplicativeCoef) : static_cast<size_t>(object->_capacity + object->_multiplicativeCoef);
    }
    ValueType* temp = new ValueType[object->_capacity];
    clone(temp, object->_data, object->_size);
    delete[] object->_data;
    object->_data = temp;
}

Vector::Vector(const ValueType* rawArray, const size_t size, float coef) : _size(size), _capacity(size), _multiplicativeCoef(coef), _data(nullptr)
{
    if (size == 0) { _data = nullptr; }
    else
    {
        _data = new ValueType[size];
        clone(_data, rawArray, size);
    }
}

Vector::Vector(const Vector& other) : _size(other._size), _capacity(other._size), _multiplicativeCoef(other._multiplicativeCoef)
{
    if (this == &other) { return; }

    _data = new ValueType[_capacity];
    clone(_data, other._data, _size);
}
Vector& Vector::operator=(const Vector& other)
{
    if (this == &other){ return *this; }
    delete[] _data;

    _size = other._size;
    _capacity = other._size;
    _multiplicativeCoef = other._multiplicativeCoef;

    _data = new ValueType[_capacity];
    clone(_data, other._data, _size);
    return *this;
}

Vector::Vector(Vector&& other) noexcept : _size(other._size),_capacity(other._capacity),_multiplicativeCoef(other._multiplicativeCoef),_data(other._data)
{
    if (this == &other) { return; }
    other._size = 0;
    other._capacity = 0;
    other._multiplicativeCoef = 0;
    other._data = nullptr;
}
Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this == &other) { return *this; }
    delete[] _data;

    _size = other._size;
    _capacity = other._capacity;
    _multiplicativeCoef = other._multiplicativeCoef;
    _data = other._data;

    other._size = 0;
    other._capacity = 0;
    other._multiplicativeCoef = 0;
    other._data = nullptr;
    return *this;
}

Vector::~Vector()
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;

}

void Vector::pushBack(const ValueType& value)
{
    realloc(this, 1);

    _data[_size] = value;
    _size++;
}
void Vector::pushFront(const ValueType& value)
{
    realloc(this, 1);
    std::memmove(_data + 1, _data, sizeof(ValueType) * (_size));

    _data[0] = value;
    _size++;
}

void Vector::insert(const ValueType& value, size_t pos)
{
    if (pos > _size + 1) { return; }
    realloc(this, 1);

    if (pos == _size + 1)
    {
        pushBack(value);
    }
    _size ++;

    std::memmove(_data + pos, _data + pos - 1, sizeof(ValueType) * (_size - pos + 1));
    _data[pos - 1] = value;
}
void Vector::insert(const ValueType* values, size_t size, size_t pos)
{
    if (pos > _size + 1) { return; }
    realloc(this, size);

    std::memmove(_data + pos + size, _data + pos, sizeof(ValueType) * (_size - pos));
    std::memmove(_data + pos, values, sizeof(ValueType) * (size));
    _size += size;
}
void Vector::insert(const Vector& vector, size_t pos)
{
    if (pos > _size + 1) { return; }
    realloc(this, vector._size);

    std::memmove(_data + pos + vector._size, _data + pos, sizeof(ValueType) * (_size - pos));
    std::memmove(_data + pos, vector._data, sizeof(ValueType) * (vector._size));
    _size += vector._size;
}

void Vector::popBack()
{
    if(_size == 0) { return; }
    _size--;
}
void Vector::popFront()
{
    if(_size == 0) { return; }
    _size--;

    std::memmove(_data, _data + 1, sizeof(ValueType) * _size);
}


void Vector::erase(size_t pos, size_t count)
{
    if (_size < pos || _size == 0) { return; }
    if (pos + count <= _size)
    {
        std::memmove(_data + pos, _data + pos + count, sizeof(ValueType) * _size - count);
    }

    _size -= count;
}

void Vector::eraseBetween(size_t beginPos, size_t endPos)
{
    size_t count = endPos - beginPos;
    if (_size < beginPos || _size == 0) { return; }

    if (count + beginPos <= _size)
    {
        std::memmove(_data + beginPos, _data + beginPos + count, sizeof(ValueType) * _size - count);
    }
    _size -= count;
}

size_t Vector::size() const
{
    return _size;
}
size_t Vector::capacity() const
{
    return _capacity;
}
double Vector::loadFactor() const
{
    return (double)(_size) / _capacity;
}

ValueType& Vector::operator[](size_t idx)
{
    return _data[idx];
}
const ValueType& Vector::operator[](size_t idx) const
{
    return _data[idx];
}

long long Vector::find(const ValueType& value) const
{
    for (size_t i = 0; i < _size; ++i)
    {
        if (_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Vector::reserve(size_t capacity)
{
    if (_capacity >= capacity) { return; }

    ValueType* temp = new ValueType[_capacity];
    clone(temp, _data, _size);
    delete[] _data;
    _data = temp;
    temp = nullptr;
    _capacity = capacity;

}
void Vector::shrinkToFit()
{
    if (_size == _capacity) { return; }

    ValueType* temp = new ValueType[_capacity];
    clone(temp, _data, _size);
    delete[] _data;
    _data = temp;
    temp = nullptr;
    _capacity = _size;
}


Vector::Iterator::Iterator(ValueType* ptr)
{
    _ptr = ptr;
}

ValueType& Vector::Iterator::operator*()
{
    return *_ptr;
}
const ValueType& Vector::Iterator::operator*() const
{
    return *_ptr;
}

//https://stackoverflow.com/questions/2696864/are-free-operator-overloads-evil
ValueType* Vector::Iterator::operator->()
{
    return _ptr;
}
const ValueType* Vector::Iterator::operator->() const
{
    return _ptr;
}

Vector::Iterator Vector::Iterator::operator++()
{
    _ptr++;
    return *this;
}
Vector::Iterator Vector::Iterator::operator++(int)
{
    Vector::Iterator temp(_ptr);
    _ptr++;
    return temp;
}

bool Vector::Iterator::operator==(const Iterator& other) const
{
    if (this->_ptr == other._ptr) { return true; }
    return false;
}
bool Vector::Iterator::operator!=(const Iterator& other) const
{
    if (this->_ptr != other._ptr) { return true; }
    return false;
}

Vector::Iterator Vector::begin()
{
    Vector::Iterator temp(_data);
    return temp;
}
Vector::Iterator Vector::end()
{
    Vector::Iterator temp(_data + _size);
    return temp;
}
