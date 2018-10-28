#include "cars.h"

const string Cars::_defaultName = "Car";  // инициализация констант для значений по умолчанию
const double Cars::_defaultNumber = 1.;

Cars::Cars()
{
    _name = _defaultName;
    _angle = _defaultNumber;
    _door = _defaultNumber;

    _gab._l = _defaultNumber;
    _gab._w = _defaultNumber;

    _coord._x = _defaultNumber;
    _coord._y = _defaultNumber;
    _coord._z = _defaultNumber;
}

Cars::Cars(string name, double angle, double door, double l, double w, double x, double y, double z)
{
    _name = _defaultName;
    _angle = _defaultNumber;
    _door = _defaultNumber;

    _gab._l = _defaultNumber;
    _gab._w = _defaultNumber;

    _coord._x = _defaultNumber;
    _coord._y = _defaultNumber;
    _coord._z = _defaultNumber;

    setName(name);
    setAngle(angle);
    setDoor(door);

    setLength(l);
    setWidth(w);

    setX(x);
    setY(y);
    setZ(z);
}

Cars::Cars(const Cars& car)
{
    this->_name = car._name;
    this->_angle = car._angle;
    this->_door = car._door;

    this->_gab._l = car._gab._l;
    this->_gab._w = car._gab._w;

    this->_coord._x = car._coord._x;
    this->_coord._y = car._coord._y;
    this->_coord._z = car._coord._z;
}

string Cars::getName()
{
    return _name;
}
double Cars::getAngle()
{
    return _angle;
}
double Cars::getDoor()
{
    return _door;
}


double Cars::getLength()
{
    return _gab._l;
}
double Cars::getWidth()
{
    return _gab._w;
}


double Cars::getX()
{
    return _coord._x;
}
double Cars::getY()
{
    return _coord._y;
}
double Cars::getZ()
{
    return _coord._z;
}



void Cars::setName(string name)  // меняет значение параматера внутри класса
{
    if (name != "")
        _name = name;  // присваевается переданное значение
}
void Cars::setAngle(double angle)
{
    if (angle > 0)
        _angle = angle;
}
void Cars::setDoor(double door)
{
    if (door > 0)
        _door = door;
}


void Cars::setLength(double l)
{
    if (l > 0)
        _gab._l = l;
}
void Cars::setWidth(double w)
{
    if (w > 0)
        _gab._w = w;
}


void Cars::setX(double x)
{
    if (x > 0)
        _coord._x = x;
}
void Cars::setY(double y)
{
    if (y > 0)
        _coord._y = y;
}
void Cars::setZ(double z)
{
    if (z > 0)
        _coord._z = z;
}



void Cars::setCoord(double x, double y, double z)
{
    setX(x);
    setY(y);
    setZ(z);
}

void Cars::getSizeWithOpenDoors(double &w, double &l, double &xorigin, double &yorigin)
{
    l = _gab._l + _back + _front;
    yorigin = _coord._y - _back;

    w = _gab._w + 2 * _door;
    xorigin = _coord._x - _door;
}
