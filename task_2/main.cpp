#include <iostream>
#include "Dictionary.h"

int main() {
    Dictionary dictionary;

    try {
        // Додавання слів до словника
        dictionary + Word("привіт", "hello");
        dictionary + Word("кіт", "cat");
        dictionary + Word("собака", "dog");

        cout << "Dictionary after adding words:" << endl;
        dictionary.printAll();

        // Сортування словника за українськими словами
        dictionary.sortByUkrainian();
        cout << "Dictionary after sorting by Ukrainian words:" << endl;
        dictionary.printAll();

        // Сортування словника за англійськими словами
        dictionary.sortByEnglish();
        cout << "Dictionary after sorting by English words:" << endl;
        dictionary.printAll();

        // Пошук слова за українським перекладом
        cout << "Searching for 'привіт':" << endl;
        Word foundByUkrWord = dictionary.searchByUkrainian("привіт");
        foundByUkrWord.print();

        // Пошук слова за англійським перекладом
        cout << "Searching for 'dog':" << endl;
        Word foundByEngWord = dictionary.searchByEnglish("dog");
        foundByEngWord.print();

        // Видалення слова
        dictionary - Word("собака", "dog");
        cout << "Dictionary after removing 'собака':" << endl;
        dictionary.printAll();
        
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    cout << "======================" << endl;

    // Спроба пошуку неіснуючого слова
    try {
        cout << "Searching for a non-existing word 'недоступне':" << endl;
        Word foundWord = dictionary.searchByUkrainian("недоступне");

        // Наступний рядок не буде виконаний, якщо виникне виняткова ситуація
        foundWord.print();
    } catch (const invalid_argument& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "======================" << endl;

    // Спроба видалення неіснуючого слова
    try {
        cout << "Trying to remove a non-existing word 'невідоме':" << endl;
        dictionary - Word("невідоме", "unknown");  

        // Наступний рядок не буде виконаний, якщо виникне виняткова ситуація
        dictionary.printAll();
    } catch (const invalid_argument& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "======================" << endl;

    // Спроба створення об'єкта Word з нульовим вказівником
    try {
        cout << "Trying to create a word with a null pointer:" << endl;
        Word validWord("привіт", nullptr);

        // Наступний рядок не буде виконаний, якщо виникне виняткова ситуація
        validWord.print();
    } catch (const invalid_argument& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
