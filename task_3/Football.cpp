#include "Football.h"

// Конструктор
Football::Football(const string& name, int players, int goals) 
    : SportGame(name, players), goals(goals) {}

// Деструктор
Football::~Football() {}

// Перевизначений метод для виведення інформації
void Football::outputInfo(ostream& os) const {
    // Виклик методу базового класу
    SportGame::outputInfo(os);
    os << "Goals: " << goals << endl;
}
