#include <iostream>
#include <limits>

using namespace std;

int getValidInteger();

int main()
{
    int size;
    cout << "Enter stack size: ";
    size = getValidInteger(); 

    cout << "Size: " << size << endl;

    return 0;
}

int getValidInteger()
{
    int value;
    while (true)
    {
        cin >> value;

        // Check if the input is valid
        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter an integer: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any extra input
            break;
        }
    }
    return value;
}