#ifndef ARRAY_H
#define ARRAY_H
#include <cars.h>

class Array
{
public:
    Array();  // Конструктор по умолчанию
    Array(int size, double l, double w, double x, double y, double z); // Конструктор инициализации
    Array(const Array& a); // конструкор копирования

    void push(Cars car);
    bool setCars(int position, Cars car); // Метод добавления элементов
    bool deleteCars(int position); // Метод удаления элементов
    void deleteAll(); // Метод, удаляющий все хранимые объекты
    int getLen() const; // Метод, возвращающий число хранящихся объектов
    Cars getCar(int position) const; // Метод доступа к элементу по индексу

    void readFromFile(string fileName);
    void writeToFile(string fileName) const;

    bool check(int position); // метод проверки на наличие контактов между автомобилями и стенами автосалона
    bool checkCars(int position1, int position2);

private:
    Cars *_arr; // массив машин (салон)
    int _len; // Длина массива = число хранящихся объектов в салоне

    struct Gabarites
    {
        double _l;
        double _w;
    };

    Gabarites _gabs;

    struct Coordinates
    {
        double _x;
        double _y;
        double _z;
    };

    Coordinates _coord;

};

#endif // ARRAY_H
