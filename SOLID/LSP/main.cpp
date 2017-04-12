#include <cassert>


/** Zasada podstawienia Liskov **/

/**
    „Funkcje ktore uzywaja wskaznikow lub referencji do klas bazowych,
    musza byc w stanie uzywac rowniez obiektow klas pochodnych po
    klasach bazowych, bez dokladnej znajomosci tych obiektow”.
**/
/**
    "... bez dokladnej znajomosci ..."
    w funkcji nie powinnismy sie poslugiwac zadnymi konstrukcjami
    warunkowymi aby wymusic poprawne dzialanie

    - zlamanie zasady:
    void func(Base *base)
    {
        if(base jest instancja kalsy bazowej)
            // zrob to ...
        else if(base jest instancja klasy pochodnej)
            // zrob to ...
    }
    - poprawne zachowanie:
    void func(Base* base)
    {
        //zrob cos
    }
**/

class Rectangle
{
protected:
    double width = 0, height = 0;
public:
    virtual void set_width(double _width) { width = _width; }
    virtual void set_height(double _height) { height = _height; }
    double area(){ return width*height; }
};

class Square : public Rectangle
{
public:
    void set_width(double _width) override { width = _width; height = _width; }
    void set_height(double _height) override { height = _height; width = _height; }
};

int main()
{
    /** ...musza byc w stanie uzywac... **/

    //Rectangle &&_rectangle = Rectangle();
    //Rectangle* _rectangle = new Rectangle();
    /** zmiana referencji do obiektu nie powinna wplywac na rezultat funkcji. **/
    Rectangle &&_rectangle = Square();
    _rectangle.set_height(10);
    _rectangle.set_width(8);
    //assert(80 == _rectangle.area());
    /** zlamanie zasady: zmiana referencji wplywa na resultat funckji **/
    assert(80 != _rectangle.area());

    /**
        Rozwiazanie tego problemu:
        - wykorzystanie polimorfizmu/klas abstrakcyjnych/interfejsow
        - stworzenie wspolnego interfejsu lub klasy abstrakcyjnej 'Shape' z funkcja 'area'
        - ustawienie by klasy 'Rectangle' i 'Square' dziedziczyly z IShape
          oraz implementowaly funkcje 'area'
    **/
}
