#include "List.h"
#include <iostream>

using namespace std;

List::List(int size)
{
    this->size = size;
    items = new int[size];
}

List::~List()
{
    delete[] items;
}

void List::setItem(int index, int value)
{
    // Перевірка на виходження за межі масиву
    if (index >= 0 && index < size)
    {
        items[index] = value;
    }
    else
    {
        throw out_of_range("Index out of bounds.");
    }
}

int List::getItem(int index) const
{
    // Перевірка на виходження за межі масиву
    if (index >= 0 && index < size)
    {
        return items[index];
    }
    throw out_of_range("Index out of bounds.");
}

int List::getSize() const
{
    return size;
}
