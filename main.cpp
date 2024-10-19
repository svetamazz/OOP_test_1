#include <iostream>
#include <limits>
#include "Stack.h"

using namespace std;

int getValidInteger();

int main()
{
    // Отримання розміру стеку від користувача
    int size;
    cout << "Enter stack size: ";
    size = getValidInteger();

    // Створення стеку
    Stack stack(size);

    cout << "==================================" << endl;

    // Отримання елементів стеку від користувача
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer value to push onto the stack: ";
        int value = getValidInteger();
        stack.push(value);
    }

    cout << "==================================" << endl;

    // Виведення стеку
    cout << "Stack output: " << endl;
    while (!stack.isEmpty())
    {
        cout << stack.pop() << endl;
    }

    return 0;
}

/**
 * @brief Отримання цілого числа від користувача
 * 
 * @return int 
 */
int getValidInteger()
{
    int value;
    while (true)
    {
        cin >> value;

        // Перевірка на введення цілого числа
        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear(); // Скидаємо прапорець помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо буфер вводу
            cout << "Invalid input! Please enter an integer: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо буфер вводу
            break;
        }
    }
    return value;
}