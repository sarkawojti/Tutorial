
#include <iostream>
#include <cassert>
#include <typeinfo>

class Base
{
public:
    virtual ~Base() = default;  /** polimorfizm **/
};

class Derived: public Base
{

};

class NormalBase {};
class NormalDerived : public NormalBase {}; /** normalne dziedziczenie **/

int main()
{

    /** dynamic_cast **/
    /** sprawdza poprawnosc konwersji danych tez w trakcie wynonywania programu [run-time check] **/
    /** uzywany wylacznie ze wskazniami i referencjami **/

    /** static_cast **/
    /** sprawdza poprawnosc konwersji danych w trakcie kompilacji [compile-time check] **/
    /** uzywany pomiedzy zgodnymi typami zdefiniowanymi w standardzie (np. char<->int)
        lub przez uzytkownika (polimorfizm, dziedziczenie, operatory rzutowania) **/

    /** rzutowanie w do�  - wylacznie typ polimorficzny - wskaznik **/

    Base var_base;
    Base* ptr_base = &var_base;

    /** jesli obiekt ptr_base wskazuje na obiekt typu Base
        to dynamic_cast zwroci nullptr **/ /** SAFE **/
    Derived* derived = dynamic_cast<Derived*>(ptr_base);
    assert(nullptr == derived);

    /** jesli obiekt ptr_base wskazuje na obiekt typu Base
        to static_cast zwroci poprawny przyciety wskaznik **/ /** UNSAFE **/
    derived = static_cast<Derived*>(ptr_base);
    assert(nullptr != derived);

    ptr_base = nullptr;
    /** jesli obiekt ptr_base wskazuje na nullptr
        to dynamic_cast/static_cast zwroci nullptr **/ /** SAFE **/
    derived = dynamic_cast<Derived*>(ptr_base);
    assert(nullptr == derived);
    derived = static_cast<Derived*>(ptr_base);
    assert(nullptr == derived);

    Derived var_derived;
    ptr_base = &var_derived;

    /** jesli obiekt ptr_base wskazuje na obiekt typu Derived
        to dynamic_cast/static_cast zwroci poprawny wskaznik **/ /** SAFE **/
    derived = dynamic_cast<Derived*>(ptr_base);
    assert(nullptr != derived);
    derived = static_cast<Derived*>(ptr_base);
    assert(nullptr != derived);

    /** rzutowanie w do�  - wylacznie typ polimorficzny - referencja **/

    ptr_base = &var_base;
    bool is_exeption = false;
    try
    {
        /** jesli obiekt var_base jest referencja na obiekt typu Base
            to dynamic_cast rzuci wyjatek bad_cast**/ /** SAFE **/
        Derived& _derived = dynamic_cast<Derived&>(*ptr_base);
    }
    catch(const std::bad_cast&)
    {
        is_exeption = true;
    }

    /** jesli obiekt var_base jest referencja na obiekt typu Base
        to static_cast zwroci poprawny przyciety obiekt **/ /** UNSAFE **/
    Derived& _derived = static_cast<Derived&>(*ptr_base);
    assert(true == is_exeption);


    is_exeption = false;
    ptr_base = &var_derived;
    try
    {
        /** jesli obiekt var_base jest referencja na obiekt typu Derived
            to dynamic_cast/static_cast zwroci poprawny obiekt**/ /** SAFE **/
        _derived = dynamic_cast<Derived&>(*ptr_base);
    }
    catch(const std::bad_cast&)
    {
        is_exeption = true;
    }
    assert(false == is_exeption);
    _derived = static_cast<Derived&>(*ptr_base);


    /** rzutowanie w gore  - typ polimorficzne i zwykle dziedziczenie - wskaznik **/

    ptr_base = &var_base;
    ptr_base = &var_derived;
    ptr_base = dynamic_cast<Base*>(&var_base);
    assert(nullptr != ptr_base);
    ptr_base = dynamic_cast<Base*>(&var_derived);
    assert(nullptr != ptr_base);

    ptr_base = static_cast<Base*>(&var_base);
    assert(nullptr != ptr_base);
    ptr_base = static_cast<Base*>(&var_derived);
    assert(nullptr != ptr_base);

    Base& _base = var_base;
    _base = var_derived;
    _base = dynamic_cast<Base&>(var_base);
    _base = dynamic_cast<Base&>(var_derived);
    _base = static_cast<Base&>(var_base);
    _base = static_cast<Base&>(var_derived);

    NormalBase var_nbase;
    NormalDerived var_nderived;
    NormalBase* ptr_nbase = &var_nbase;
    ptr_nbase = &var_nderived;
    ptr_nbase = dynamic_cast<NormalBase*>(&var_nbase);
    assert(nullptr != ptr_nbase);
    ptr_nbase = dynamic_cast<NormalBase*>(&var_nderived);
    assert(nullptr != ptr_nbase);

    ptr_nbase = static_cast<NormalBase*>(&var_nbase);
    assert(nullptr != ptr_nbase);
    ptr_nbase = static_cast<NormalBase*>(&var_nderived);
    assert(nullptr != ptr_nbase);

    NormalBase& _nbase = var_nbase;
    _nbase = var_nderived;
    _nbase = dynamic_cast<NormalBase&>(var_nbase);
    _nbase = dynamic_cast<NormalBase&>(var_nderived);
    _nbase = static_cast<NormalBase&>(var_nbase);
    _nbase = static_cast<NormalBase&>(var_nderived);

    return 0;
}
