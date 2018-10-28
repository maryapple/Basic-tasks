#include "array.h"
#include <fstream>

Array::Array()
{
    _arr = new Cars[10];
    _len = 0;
    _gabs._l = 30;
    _gabs._w = 30;
    _coord._x = 0;
    _coord._y = 0;
    _coord._z = 0;
}

Array::Array(int size, double l, double w, double x, double y, double z)
{
    _arr = new Cars[abs(size) + 10];
    _len = abs(size);
    _gabs._l = abs(l);
    _gabs._w = abs(w);
    _coord._x = abs(x);
    _coord._y = abs(y);
    _coord._z = abs(z);
}

Array::Array(const Array& a)
{
    _len = a._len;
    _gabs._l = a._gabs._l;
    _gabs._w = a._gabs._w;
    _coord._x = a._coord._x;
    _coord._y = a._coord._y;
    _coord._z = a._coord._z;

    _arr = new Cars[_len + 10];

    for(int i = 0; i < _len; i++)
        _arr[i] = a._arr[i];
}

void Array::push(Cars car)
{
    if (_len+1 > sizeof (_arr))
    {
        Cars *arr2 = new Cars();
        for(int i = 0; i < _len; i++)
            arr2[i] = _arr[i];
        _arr = new Cars[_len + 10];
        for(int i = 0; i < _len; i++)
            _arr[i] = arr2[i];
        delete arr2;
    }
    _len ++;
}

bool Array::setCars(int position, Cars car)
{
    if (position >= _len || position < 0)
        return false;
    _arr[position] = car;
    return true;
}

bool Array::deleteCars(int position)
{
    if (position >= _len || position < 0)
        return false;
    for (int j = position; j < _len - 1; j++)
        _arr[j] = _arr[j+1];
    _len--;
    return true;
}

void Array::deleteAll()
{
    if(_arr != nullptr)  // Проверка существования массива
        delete [] _arr;
    _len = 0;
}

int Array::getLen() const
{
    return _len;
}

Cars Array::getCar(int position) const
{
    return _arr[position];
}

void Array::readFromFile(std::string fileName)
{
    char buff[50];
    std::ifstream fin(fileName);
    if(_len == 0)
        _arr = new Cars[10];

    if (fin.is_open())
        while(!fin.eof())
        {
            Cars car = Cars();

            fin.getline(buff,50);
            car.setName(string(buff));

            fin.getline(buff,50);
            car.setAngle(int(buff));

            fin.getline(buff,50);
            car.setDoor(int(buff));

            fin.getline(buff, 50);
            car.setLength(int(buff));

            fin.getline(buff, 50);
            car.setWidth(int(buff));

            fin.getline(buff, 50);
            car.setX(int(buff));

            fin.getline(buff, 50);
            car.setY(int(buff));

            fin.getline(buff, 50);
            car.setZ(int(buff));

            push(car);
        }

    fin.close();
}

void Array::writeToFile(std::string fileName) const
{
    std::ofstream fout(fileName);
    for(int i = 0; i <_len; i++)
    {
        fout << _arr[i].getName() << '\n';  // Она нужна?
        fout << _arr[i].getAngle() << '\n';  // Она нужна?
        fout << _arr[i].getDoor() << '\n';  // Она нужна?
        fout << _arr[i].getLength() << '\n';
        fout << _arr[i].getWidth() << '\n';
        fout << _arr[i].getX() << "\n";
        fout << _arr[i].getY() << "\n";
        fout << _arr[i].getZ() << "\n";
    }
    fout.close();
}

bool Array::check(int position)
{
    double len, wid, xorigin, yorigin;
    _arr[position].getSizeWithOpenDoors(wid,len,xorigin,yorigin);

    if (_coord._x <= xorigin && _coord._x + _gabs._w >= xorigin + wid &&
        _coord._y <= yorigin && _coord._y + _gabs._l >= yorigin + len)
        return true;
    else
        return false;
}

bool Array::checkCars(int position1, int position2)
{
    double len1, wid1, xorigin1, yorigin1;
    _arr[position1].getSizeWithOpenDoors(wid1,len1,xorigin1,yorigin1);

    double len2, wid2, xorigin2, yorigin2;
    _arr[position2].getSizeWithOpenDoors(wid2,len2,xorigin2,yorigin2);


    if ((xorigin1 + wid1 <= xorigin2 || xorigin2 + wid2 <= xorigin1) &&
    (yorigin1 + len1 <= yorigin2 || yorigin2 + len2 <= yorigin1))
        return true;
    else
        return false;
}

