class List
{
private:
    int* items; // Масив елементів
    int size; // Кількість елементів

public:
    List(int size);
    ~List();

    void setItem(int index, int value);
    int getItem(int index) const;
    int getSize() const;
};