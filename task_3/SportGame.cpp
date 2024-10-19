#include "SportGame.h"
    
// Конструктор
SportGame::SportGame(const string& name, int players) 
    : name(name), players(players) {}

// Віртуальний деструктор
SportGame::~SportGame() {}

// Віртуальний метод для виведення інформації про гру
void SportGame::outputInfo(ostream& os) const {
    os << "Sport Game: " << name << endl << "Players: " << players << endl;
}

// Метод для збереження інформації про гру у файл
void SportGame::saveToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        outputInfo(file);
        file.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}
