#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class Word {
private:
    char* ukrainianWord;
    char* englishWord;

    // Приватна допомоіжна функція для копіювання рядка
    char* copyString(const char* str);

public:
    // Конструктор з параметрами
    Word(const char* ukrainian, const char* english);

    // Копіювальний конструктор
    Word(const Word& other);

    // Деструктор
    ~Word();

    // Гетери
    const char* getUkrainian() const;
    const char* getEnglish() const;

    // Перевантаження операцій порівняння
    bool operator<(const Word& other) const;
    bool operator>=(const Word& other) const;
    bool operator==(const Word& other) const;

    // Оператор присвоєння
    Word& operator=(const Word& other);

    // Вивід на екран
    void print() const;
};

