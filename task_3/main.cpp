#include "Football.h"

int main() {
    // Створення об'єкта класу Football
    Football football("Football", 11, 3);

    // Виведення інформації в консоль
    football.outputInfo(cout);

    // Збереження інформації у файл
    football.saveToFile("sports_info.txt");

    return 0;
}
