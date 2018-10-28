#ifndef CARS_H
#define CARS_H
#include <iostream>
using std::string;

class Cars
{
public:
    //constructors
    Cars();  // Конструктор по умолчанию
    Cars(string name, double angle, double door, double l, double w, double x, double y, double z); // Конструктор с параметрами
    Cars(const Cars& car);  // Конструктор копирования

    //getters
    string getName();
    double getAngle();
    double getDoor();
    double getLength();
    double getWidth();
    double getX();
    double getY();
    double getZ();

    //setters
    void setName(string name);
    void setAngle(double angle);
    void setDoor(double door);
    void setLength(double l);
    void setWidth(double w);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void setCoord(double x, double y, double z);  // Метод, если понадобятся сразу все координаты

    void getSizeWithOpenDoors(double &w, double &l, double &xorigin, double &yorigin);

private:
    string _name;
    double _angle;
    double _door;  // Переменная, которая характеризует пространство в результате открытия двери машины
    double _back;
    double _front;

    struct Gabarites
    {
        double _l;
        double _w;
    };

    Gabarites _gab;

    struct Coordinates
    {
        double _x;
        double _y;
        double _z;
    };

    Coordinates _coord;

    static const string _defaultName;  // static - переменная не зависит от объекта класса (_defaultName не зависит от объектов класса)
    static const double _defaultNumber;
};

#endif // CARS_H
