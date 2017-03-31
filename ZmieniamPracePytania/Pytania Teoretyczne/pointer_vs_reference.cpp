
#include <iostream>
#include <cassert>

int main()
{
    /** ZMIENNA - zajmuje komorke pamieci, czyli wlasny adres dzieki
                  ktoremu procesor sie do niej odwoluje. **/
    int _value = 8;

    /** WSKAZNIK - specjalna zmienna, przechowujaca adres komorki pamieci [liczbe] **/
    int* _pointer;                                /** inicjalizacja nie jest wymagana w definicji           **/
    _pointer = &_value;                           /** inicjalizacja                                         **/
    int** _pointer_to_pointer = &_pointer;        /** zajmuje miejsce w pamieci - ma swoj unikatowy adres   **/
    assert(sizeof(int*) == sizeof(char*));        /** i swoj staly rozmiar 4bajty - system 32bitowy         **/
    assert(sizeof(_pointer) == 4);                /** 8 bajtow - system 64bitowy                            **/
    assert(_value == *_pointer);                  /** dereferncja - wyluskanie watosci zmiennej wskazywanej **/
    *_pointer = 100;                              /** mozemy zmieniac wartosc zmiennej na ktora wskazuje    **/
    assert(_value == 100);
    _value = 7;
    assert(*_pointer == 7);

    int _value_2;
    _pointer = &_value_2;                         /** wskazywana zmienna mozna zmieniac [type check]        **/

    /** REFERENCJA - "przezwisko" zmiennej **/
    int& _reference = _value;                     /** nalezy zainicjowac podczas dekalaracji              **/
    assert(&_reference == &_value);               /** nie zajmuje miejsca w pamieci tzn. ma ten sam adres **/
    assert(sizeof(_reference) == sizeof(_value)); /** i rozmiar co zmienna pod ktora sie podszywa         **/
    assert(_reference == _value);
    _reference = 9;                               /** zmieniajac zmianna lub referencje do niej           **/
    assert(9 == _value);                          /** automatycznie zmienia sie wartosc drugiej           **/
    _value = 100;
    assert(100 == _reference);

    _reference =_value_2;                         /** referencji nie mozna zmienic                        **/
    _value_2 = 7;
    assert(7 != _reference);


    return 0;
}
