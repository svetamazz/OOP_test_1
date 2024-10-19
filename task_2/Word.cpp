#include "Word.h"

// Приватна допомоіжна функція для копіювання рядка
char* Word::copyString(const char* str) {
    if (str) {
        char* newStr = new char[strlen(str) + 1];
        strcpy(newStr, str);
        return newStr;
    } else {
        return nullptr;
    }
}

// Конструктор з параметрами
Word::Word(const char* ukrainian, const char* english) {
    // Перевірка чи поля-вказівники ініціалізовані
    if (ukrainian == nullptr || english == nullptr) {
        throw std::invalid_argument("Ukrainian and English words cannot be null.");
    }

    // Виділення пам'яті для копіювання рядків
    ukrainianWord = new char[strlen(ukrainian) + 1];
    strcpy(ukrainianWord, ukrainian);

    englishWord = new char[strlen(english) + 1];
    strcpy(englishWord, english);
}

// Копіювальний конструктор
Word::Word(const Word& other) 
    : ukrainianWord(copyString(other.ukrainianWord)), 
      englishWord(copyString(other.englishWord)) {}

// Деструктор
Word::~Word() {
    delete[] ukrainianWord;
    delete[] englishWord;
}

// Гетери
const char* Word::getUkrainian() const {
    return ukrainianWord;
}

const char* Word::getEnglish() const {
    return englishWord;
}

// Перевантаження операцій порівняння
bool Word::operator<(const Word& other) const {
    return strcmp(ukrainianWord, other.ukrainianWord) < 0;
}

bool Word::operator>=(const Word& other) const {
    return strcmp(ukrainianWord, other.ukrainianWord) >= 0;
}

bool Word::operator==(const Word& other) const {
    return strcmp(ukrainianWord, other.ukrainianWord) == 0 && 
           strcmp(englishWord, other.englishWord) == 0;
}

// Оператор присвоєння
Word& Word::operator=(const Word& other) {
    if (this != &other) {
        delete[] ukrainianWord;
        delete[] englishWord;

        ukrainianWord = copyString(other.ukrainianWord);
        englishWord = copyString(other.englishWord);
    }
    return *this;
}

// Вивід на екран
void Word::print() const {
    std::cout << ukrainianWord << " - " << englishWord << std::endl;
}