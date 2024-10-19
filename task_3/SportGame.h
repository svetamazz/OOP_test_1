#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SportGame {
protected:
    string name;
    int players;

public:
    // Конструктор
    SportGame(const string& name, int players);

    // Віртуальний деструктор
    virtual ~SportGame();

    // Віртуальний метод для виведення інформації про гру
    virtual void outputInfo(ostream& os) const;

    // Метод для збереження інформації про гру у файл
    void saveToFile(const string& filename) const;
};
