#include "SportGame.h"

class Football : public SportGame {
private:
    int goals;

public:
    // Конструктор
    Football(const string& name, int players, int goals);

    // Деструктор
    ~Football();

    // Перевизначений метод для виведення інформації
    void outputInfo(ostream& os) const override;
};
