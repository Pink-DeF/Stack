#pragma once
#include "../ForwardList/ForwardList.h"
#include "../Vector/Vector.h"

using ValueType = double;

// интерфейс для конкретных реализаций контейнера для стека
class IStackImplementation {
public:
    // добавление в хвост
    virtual void push(const ValueType& value) = 0;
    // удаление с хвоста
    virtual void pop() = 0;
    // посмотреть элемент в хвосте
    virtual const ValueType& top() const = 0;
    // проверка на пустоту
    virtual bool isEmpty() const = 0;
    // размер 
    virtual size_t size() const = 0;
    // виртуальный деструктор
    virtual ~IStackImplementation() = default;
};

class ListContainer : public IStackImplementation
{
public:
    ListContainer() = default;
    ListContainer(const ValueType* valueArray, const size_t arraySize);

    ListContainer(const ListContainer& copyList);
    ListContainer& operator=(const ListContainer& copyList);

    virtual void push(const ValueType& value) override;
    virtual void pop() override;
    virtual const ValueType& top() const override;

    virtual bool isEmpty() const override;
    virtual size_t size() const override;

private:
    ForwardList list;
};

class VectorContainer : public IStackImplementation {
private:
    Vector vec;

public:

    VectorContainer() = default;
    VectorContainer(const ValueType* valueArray, const size_t arraySize);

    VectorContainer(const VectorContainer& copyStack);
    VectorContainer& operator=(const VectorContainer& copyStack);

    virtual void push(const ValueType& value) override;

    virtual void pop() override;

    virtual const ValueType& top() const override;

    virtual bool isEmpty() const override;

    virtual size_t size() const override;
};

