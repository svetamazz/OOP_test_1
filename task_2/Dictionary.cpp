#include "Dictionary.h"

// Перевантаження операції додавання слова
Dictionary& Dictionary::operator+(const Word& word) {
    words.push_back(word);
    return *this;
}

// Перевантаження операції видалення слова
Dictionary& Dictionary::operator-(const Word& word) {
    auto it = remove_if(words.begin(), words.end(),
        [&](const Word& w) {
            // Використовуємо перевантажений оператор в класі Word для порівняння
            return w == word;
        });

    if (it != words.end()) {
        words.erase(it, words.end());
    } else {
        throw invalid_argument("Word not found in the dictionary.");
    }

    return *this;
}

// Сортування словника за українськими словами
void Dictionary::sortByUkrainian() {
    // Використовуємо перевантажений оператор в класі Word для сортування
    sort(words.begin(), words.end());
}

// Сортування словника за англійськими словами
void Dictionary::sortByEnglish() {
    sort(words.begin(), words.end(),
        [](const Word& a, const Word& b) {
            // Використовуємо strcmp для порівняння
            return strcmp(a.getEnglish(), b.getEnglish()) < 0;
        });
}

// Пошук слова за його українським перекладом
Word Dictionary::searchByUkrainian(const char* ukr) const {
    for (const auto& word : words) {
        if (strcmp(word.getUkrainian(), ukr) == 0) {
            return word;
        }
    }
    throw invalid_argument("Word not found in the dictionary.");
}

// Пошук слова за його англійським перекладом
Word Dictionary::searchByEnglish(const char* eng) const {
    for (const auto& word : words) {
        if (strcmp(word.getEnglish(), eng) == 0) {
            return word;
        }
    }
    throw invalid_argument("Word not found in the dictionary.");
}

// Виведення на екран усіх слів словника
void Dictionary::printAll() const {
    for (const auto& word : words) {
        word.print();
    }
}