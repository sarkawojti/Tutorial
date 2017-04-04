
#include <iostream>
#include <vector>
#include <memory>

#include "inc/ShapeFactory.h"


int main()
{
    IShapeFactory* shape_factory = new ShapeFactory();

    std::vector<std::shared_ptr<IShape>> shapes;

    shapes.push_back(shape_factory->create(ShapeType::SQUARE));
    shapes.push_back(shape_factory->create(ShapeType::RECTANGLE));
    shapes.push_back(shape_factory->create(ShapeType::TRIANGLE));
    shapes.push_back(shape_factory->create(ShapeType::SQUARE));
    shapes.push_back(shape_factory->create(ShapeType::SQUARE));
    shapes.push_back(shape_factory->create(ShapeType::RECTANGLE));
    shapes.push_back(shape_factory->create(ShapeType::RECTANGLE));
    shapes.push_back(shape_factory->create(ShapeType::SQUARE));
    shapes.push_back(shape_factory->create(ShapeType::RECTANGLE));
    shapes.push_back(shape_factory->create(ShapeType::TRIANGLE));

    shapes.clear();
    delete shape_factory;

    return 0;
}

/** Metoda Wytworcza - kreacyjny wzorzec projektowy **/

/**

abstrakcja tworzenia nieokreslonych obiektow o powiazanym typie.

ARCHITEKTURA:
    interfejs/klasa abstrakcyjna produktu       IShape
    konkretna klasa produktu                    Square/Rectangle/Triangle
    interfejs/klasa abstrakcyjna kreatora       IShapeFactory
    konkretna kalsa kreatora                    ShapeFactory


    parametryzowana metoda wytworcza            virtual std::shared_ptr<IShape> create(const ShapeType&) = 0;



**/
