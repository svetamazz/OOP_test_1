#include "List.h"

class Stack
{
private:
    List* list;
    int top;
    int size;

public:
    Stack(int size);
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    void show() const;
    bool isEmpty() const;
    bool isFull() const;
};