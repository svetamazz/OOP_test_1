#include "Word.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

using namespace std;

class Dictionary {
private:
    // Вектор для зберігання об'єктів класу Word
    vector<Word> words;

public:
    // Перевантаження операторів для додавання та видалення слів
    Dictionary& operator+(const Word& word);
    Dictionary& operator-(const Word& word);

    // Сортування словника за українськими та англійськими словами
    void sortByUkrainian();
    void sortByEnglish();

    // Пошук слова за українським та англійським перекладом
    Word searchByUkrainian(const char* ukr) const;
    Word searchByEnglish(const char* eng) const;

    // Виведення на екран усіх слів словника
    void printAll() const;
};
