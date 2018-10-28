#include "cars.h"
#include "array.h"
#include <cassert>

bool collectionEqual(Array *salon1, Array *salon2)
{
    for (int i = 0; i < salon2->getLen(); i++)
    {
        if(salon2->getLen() == salon1->getLen())
        if(salon2->getCar(i).getLength() == salon1->getCar(i).getLength())
        if(salon2->getCar(i).getWidth() == salon1->getCar(i).getWidth())
        if(salon2->getCar(i).getX() == salon1->getCar(i).getX())
        if(salon2->getCar(i).getY() == salon1->getCar(i).getY())
        if(salon2->getCar(i).getZ() == salon1->getCar(i).getZ()) continue;
        return false;
    }
    return true;
}

void printCollection(Array *salon)
{
    for(int i = 0; i < salon->getLen(); i++)
    {
        std::cout << "Record #" << i + 1 << ':' << '\n';
        std::cout << salon->getCar(i).getLength() << "\n";
        std::cout << salon->getCar(i).getWidth() << "\n";
        std::cout << salon->getCar(i).getX() << "\n";
        std::cout << salon->getCar(i).getY() << "\n";
        std::cout << salon->getCar(i).getZ() << "\n\n";
    }
}

int main()
{
    // Тесты для класса cars.cpp

    Cars cardef = Cars();  // cardef - объект класса Cars, проверяющий дефолтный конструкор

    assert(cardef.getName() == "Car");
    assert(cardef.getAngle() == 1.);
    assert(cardef.getDoor() == 1.);
    assert(cardef.getLength() == 1.);
    assert(cardef.getWidth() == 1.);
    assert(cardef.getX() == 1.);
    assert(cardef.getY() == 1.);
    assert(cardef.getZ() == 1.);

    Cars carparametr = Cars("toyota", 90, 30, 444, 222, 3, 2, 1);  // carparametr - объект класса Cars, проверяющий конструктор с параметрами

    assert(carparametr.getName() == "toyota");
    assert(carparametr.getAngle() == 90.);
    assert(carparametr.getDoor() == 30.);
    assert(carparametr.getLength() == 444.);
    assert(carparametr.getWidth() == 222.);
    assert(carparametr.getX() == 3.);
    assert(carparametr.getY() == 2.);
    assert(carparametr.getZ() == 1.);

    Cars carcopy = Cars(carparametr);  // carcopy - объект класса Cars, проверяющий копирующий конструктор

    assert(carcopy.getName() == "toyota");
    assert(carcopy.getAngle() == 90.);
    assert(carcopy.getDoor() == 30.);
    assert(carcopy.getLength() == 444.);
    assert(carcopy.getWidth() == 222.);
    assert(carcopy.getX() == 3.);
    assert(carcopy.getY() == 2.);
    assert(carcopy.getZ() == 1.);

    // Неправильные параметры:

    Cars incorrcar = Cars("", -2, 0, -2, -2, 0, 0, -5);

    assert(incorrcar.getName() == "Car");  // поскольку условия не выполняются, не срабатывают setters, и только getters
    assert(incorrcar.getAngle() == 1.);
    assert(incorrcar.getDoor() == 1.);
    assert(incorrcar.getLength() == 1.);
    assert(incorrcar.getWidth() == 1.);
    assert(incorrcar.getX() == 1.);
    assert(incorrcar.getY() == 1.);
    assert(incorrcar.getZ() == 1.);

    carparametr.setName("");
    assert(carparametr.getName() != "");

    std::cout << "Tests are correct" << std::endl;

    // Тесты для коллекций

    Array *salon1 = new Array(5, 10000, 500, 0, 0, 0);
    assert(salon1->getLen() == 5); // Проверка конструктора инициализации

    Array *salon2 = new Array(*salon1);
    assert(collectionEqual(salon1, salon2) == true); // Проверка конструктора копирования
    salon2->push(incorrcar);
    assert(collectionEqual(salon1, salon2) == false); // Проверка конструктора копирования

    int len1 = salon1->getLen();
    salon1->push(cardef);
    assert(len1 + 1 == salon1->getLen()); // Проверка метода добавления объектов
    salon1->deleteCars(len1 - 1);
    assert(len1 == salon1->getLen()); // Проверка метода удаления объектов

    salon1->deleteAll();
    assert(salon1->getLen() == 0); // Проверка метода удаления всех объектов

    printCollection(salon2);

    salon2->writeToFile("test.txt");
    salon1->readFromFile("test.txt");
    assert(collectionEqual(salon1, salon2) == true);

    delete salon1;
    delete salon2;

    return 0;
}
