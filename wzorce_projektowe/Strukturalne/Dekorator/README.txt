
Nazwa:	     Dekorator - strukturalny wzorzec projektowy (obiekowy)


Problem:     dynamiczne [run-time, w czasie dzialania programu] dolaczanie do
             obiektow dodatkowej funkcjonalnosci zamiast statycznego dziedziczenia
             gdzie nowe zobowiazania dolaczane sa na etapie kompilacji [compile-time]

Rozwiazanie: 

    Component         - klasa definiujaca wspolny interfejs dla ConcreteComponent i Decorator.

    ConcreteComponent - definiuje rzeczywisty objekt/klase dekorawany przez Dekorator.

    Decorator         - przechowuje odwolanie umozliwiajace dostep do ConcreteComponent,
                        orginalny obiekt przekazujemy jako parametr konstruktora dekoratora
                        zapewnia identyczny interfejs co ConcreteComponent.

    ConcreteDecorator - dodaje nowa funkcjonalnosc,
                        metoda dekoratora wywoluje metode orginalna i doklada nowe zoobowiazanie.

Konsekwencje:
    - zapewnia wieksza elastycznosc niz statyczne dziedziczenie,
    - pozwala iniknac tworzenia przeladowanych funkcjami klas na wysokich poziomach hierarchii,
    - konkretny dekorator i powiazany z nim komponent NIE SA IDENTYCZNE,
    - powstaje wiele malych obiektow.