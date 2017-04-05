
#include <iostream>

#include "inc/FileReader.h"
#include "inc/ConsoleReader.h"
#include "inc/WhiteSpaceCleanReader.h"
#include "inc/UpperReader.h"

int main()
{
    std::shared_ptr<IReader> reader_console = std::make_shared<ConsoleReader>("Podaj: ");;
    std::cout << reader_console->read() << std::endl;

    std::shared_ptr<IReader> reader_file = std::make_shared<FileReader>("data.txt");
    std::cout << reader_file->read() << std::endl;

    WhiteSpaceCleanReader white_space_clean_file_reader(reader_file);
    std::cout << white_space_clean_file_reader.read() << std::endl;

    WhiteSpaceCleanReader white_space_clean_console_reader(reader_console);
    std::cout << white_space_clean_console_reader.read() << std::endl;

    UpperReader upper_file_reader(reader_file);
    std::cout << upper_file_reader.read() << std::endl;

    UpperReader upper_console_reader(reader_console);
    std::cout << upper_console_reader.read() << std::endl;

    return 0;
}

/**

Nazwa:      DEKORATOR - obiektowy wzorzec strukturalny

Problem:    dynamiczne [run-time, w czasie dzialania programu] dolaczanie do
            obiektow dodatkowej funkcjonalnosci zamiast statycznego dziedziczenia
            gdzie nowe zobowiazania dolaczane sa na etapie kompilacji [compile-time]

Rozwiazanie:

        Component           - klasa definiujaca wspolny interfejs dla ConcreteComponent i Decorator.
        ConcreteComponent   - definiuje rzeczywisty objekt/klase dekorawany przez Dekorator.
        Decorator           - przechowuje odwolanie umozliwiajace dostep do ConcreteComponent,
                              orginalny obiekt przekazujemy jako parametr konstruktora dekoratora
                              zapewnia identyczny interfejs co ConcreteComponent.
        ConcreteDecorator   - dodaje nowa funkcjonalnosc,
                              metoda dekoratora wywoluje metode orginalna i doklada nowe zoobowiazanie

Konsekwencje:
        - zapewnia wieksza elastycznosc niz statyczne dziedziczenie
        - pozwala iniknac tworzenia przeladowanych funkcjami klas na wysokich poziomach hierarchii
        - konkretny dekorator i powiazany z nim komponent NIE SA IDENTYCZNE
        - powstaje wiele malych obiektow

**/
