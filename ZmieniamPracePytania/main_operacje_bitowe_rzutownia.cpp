#include <iostream>
#include <cassert>
#include <limits>

class Object
{
private:
    unsigned _value = 4;
    //unsigned char _char = 6;
};

constexpr unsigned char BAJT_2_BITS = 8;
constexpr unsigned char MASK_128 = 128;

template<class T>
void printObjectAsBits(T&& object)
{
    unsigned char* _char_pointer = reinterpret_cast<unsigned char*>(&object);
    for(unsigned i = 0; i < sizeof(object); ++i)
    {
        unsigned char _char_temp = *_char_pointer;
        for(unsigned j = 0; j < BAJT_2_BITS; ++j)
        {
            std::cout << (unsigned)((_char_temp & MASK_128) >> 7);
            _char_temp = _char_temp << 1;
        }
        _char_pointer++;
    }
}

bool isBigEndian()
{
    unsigned value = 7;
    unsigned char* _char_pointer = reinterpret_cast<unsigned char*>(&value);
    return not (*_char_pointer == value);
}

int main()
{
    //printAsBits(Object());
    //std::cout << "Is Big Endian? " << std::boolalpha << isBigEndian() << std::endl;

    /** KONWERSJE NIEJAWNE - implicit **/

    /**
        konwersja rozszerzajaca (promocja)
        wartosc mniejszej zmiennej przypisywana zostaje do wiekszej zmiennej bez utraty danych
    **/
    bool bool_value = true;
    int int_value = bool_value;
    assert(1 == int_value);
    float float_value = int_value;
    assert(1.f == float_value);
    double double_value = float_value;
    assert(1. == double_value);

    /**
        konwersja zawezajaca (przeksztalcenie)
        wartosc wiekszej zmiennej przypisywana zostaje do mniejszej zmiennej z mozliwa utrata danych
    **/
    double_value = 5.5;
    int_value = double_value;
    assert(5 == int_value);
    float_value = 5.5f;
    int_value = float_value;
    assert(5 == int_value);

    /** bez utrata danych, kompilator nie generuje ostrzezenie **/
    unsigned char unsigned_char_value = 200;
    /** utrata danych, kompilator generuje ostrzezenie - jawne rzutowanie usunie ostrzezenie **/
    unsigned_char_value = 400;
    /** w tym przypadku wartosc po utracie danych wyniesie 144 **/
    assert(144 == unsigned_char_value);

    /**
        konwersja ze znakiem i bez znaku
    **/

    unsigned short unsigned_short_value = std::numeric_limits<unsigned short>::max();
    short signed_short_value = unsigned_short_value;
    assert(65535 == unsigned_short_value);
    assert(-1 == signed_short_value);

    /**
        konwersja wskaznikow
    **/
    const char* unsigned_char_pointer = "Help" + 3;
    /** staly literal ciagow znakow konwertowany jest na char* a +3 przesunie  wskaznik z pierwszego elementu o trzy **/
    assert(*unsigned_char_pointer == 'p');


    /** KONWERSJE JAWNE **/

    /** c-style **/
    double_value = 5.5;
    int_value = (unsigned)double_value;
    int_value = unsigned(double_value);
    /** nie zalecane  - nie czytelne, ciezkie do wyszukania **/


    /** operator static_cast **/
    /** rzutowanie sprawdzane podczas kompilacji, zwraca blad jesli podejmiemy probe konwersji miedzy calkowicie niezgodnymi typami **/
    int_value = std::numeric_limits<int>::max();
    unsigned_char_value = int_value; /** warning: mozliwa utrata danych **/
    unsigned_char_value = static_cast<unsigned char>(400); /** no warning: kompilator ufa uzytkownikowi **/

    //std::string string_value = static_cast<std::string>(int_value); /** error: nie znana konwersja **/

    /** konwersja zdefiniowana przez uzytkownika **/
    class A{};
    class B
    {
    public:
        operator A(){ return A(); }
    };
    static_cast<A>(B());

    class Dog
    {
    public:
        Dog(const std::string& name):_name(name){}
    private:
        std::string _name;
    };
    static_cast<Dog>(std::string("Pluto"));

    /** konwersja w gore - dziedziczenie, safe conversion **/
    class Base
    {
    public:
        virtual ~Base(){};
    };
    class Derived : public Base{};

    Base* _base = static_cast<Base*>(new Derived());
    Base __base = static_cast<Base>(Derived());
    delete _base;

    /** konwersja w dol - dziedziczenie, not safe conversion **/

    /** jesli obiekt _base wskazuje na obiekt typu Derived to static_cast w dol jest bezpieczny  **/
    _base = new Derived();
    Derived* _derived = static_cast<Derived*>(_base);
    /** jesli obiekt _base ma wartosc 0 to static_cast w dol jest bezpieczny                     **/
    _derived = static_cast<Derived*>(nullptr);
    _derived = static_cast<Derived*>(0);
    /** jesli obiekt _base wskazuje na obiekt typu Base to static_cast w dol jest nie bezpieczny
        Derived class can have fields and methods that are not in Base                           **/
    delete _base;
    _base = new Base();
    _derived = static_cast<Derived*>(_base);
    delete _base;

    _derived = _derived;

    /** operator dynamic_cast **/
    /** rzutowanie sprawdzane w czasie wykonywania, dodatkowe obciazenie, safe **/

    /** konwersja w dol - dziedziczenie **/

    _base = new Base();
    _derived = dynamic_cast<Derived*>(_base);
    /** jesli obiekt _base wskazuje na obiekt typu Base to dynamic_cast zwroci 0 **/
    assert(nullptr == _derived);
    assert(0 == _derived);
    delete _base;

    /** jesli obiekt _base wskazuje na obiekt typu Derived to dynamic_cast dokona poprawnego rzutownia **/
    _base = new Derived();
    _derived = dynamic_cast<Derived*>(_base);
    assert(nullptr != _derived);
    assert(0 != _derived);

    /** operator const_cast **/
    /** usuniecie klasyfikatorow const lub volatile z typu : referencja, wskaznik, wskaznik do skladowej kalsy  **/

    const int const_int_value = 7;
    assert(7 == const_int_value);
    const int& cref_int_value = const_int_value;
    const_cast<int&>(cref_int_value) = 4;
    assert(4 == cref_int_value);

    int* pointer_int_value = const_cast<int*>(&const_int_value);
    *pointer_int_value = 9; /** undefined behavior **/

    class Temp
    {
    private:
        int _int = 9;
    public:
        int get_value() const { return _int; }
        void set_value(int value) const
        {
            const_cast<Temp*>(this)->_int = value;
        }  /** obejscie constowosci metody klasy **/
    };
    Temp temp;
    assert(9 == temp.get_value());
    temp.set_value(87);
    assert(87 == temp.get_value());


    /** operator reinterpret_cast **/
    /** rzutowanie miedzy typami nie powiazanymi **/

    _base = reinterpret_cast<Base*>(&temp);
}

/**
1. Wypisz dowolny obiekt binarnie.
2. Big Endian vs Little Endian.
3. Napisz funkcje informujaca o tym jakiej konwencji uzywa nasz sysytem
4. Konwersja typow.
**/

/**
- konwencje ustalajace kolejnosc bitow.
- wystepuje powyzej dwoch bajtow

BIG ENDIAN
 - najbardziej znaczacy bajt umieszczany jest jako pierwszy
 - analogiczna do codziennego zapisu liczb

 32 -bitowa wartosc w pamieci - 0x4A3B2C1D od adresu 100 bedzie wygladac:
    100 - 4A
    101 - 3B
    102 - 2C
    103 - 1D


LITTLE ENDIAN
 - mniej znaczacy bajt umieszczamy jako pierwszy

  32 -bitowa wartosc w pamieci - 0x4A3B2C1D od adresu 100 bedzie wygladac:
    100 - 1D
    101 - 2C
    102 - 3B
    103 - 4A

**/
