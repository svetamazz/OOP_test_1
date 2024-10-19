#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size)
{
    this->size = size;
    list = new List(size);
    top = -1; // Ініціалізація вершини стеку
}

Stack::~Stack()
{
    delete list;
}

void Stack::push(int value)
{
    if (top < size - 1) // Перевірка на переповнення стеку
    {
        top++;
        list->setItem(top, value);
    }
    else
    {
    throw runtime_error("Stack overflow! Cannot push more elements.");
    }
}

int Stack::pop()
{
    if (top >= 0) // Перевірка на пустоту стеку
    {
        int value = list->getItem(top);
        top--;
        return value;
    }
    throw runtime_error("Stack underflow! No elements to pop.");
}

int Stack::peek() const
{
    if (top >= 0) // Перевірка на пустоту стеку
    {
        return list->getItem(top);
    }
    throw runtime_error("Stack is empty!");
}

bool Stack::isEmpty() const 
{
    return top == -1;
}

bool Stack::isFull() const
{
    return top == size - 1;
}
