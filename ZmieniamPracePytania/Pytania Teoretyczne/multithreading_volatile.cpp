
#include <iostream>


/**
    zmienna ulotna

    - zapobiega wprowadzaniu optymalizacji przez kompilator
    - wymusza na kompilatorze odczyt wartosci przy kazdym uzyciu zmiennej
    - uzywane gdy inny proces ma dostep do danej zmiennej [moze zmienic jej wartosc]
**/

/**
    [C++11]
    To safely write lock-free code that communicates between threads without using locks,
    prefer to use ordered atomic variables: Java/.NET volatile, C++0x atomic, and C-compatible atomic_T.

    To safely communicate with special hardware or other memory that has unusual semantics,
    use unoptimized variables: ISO C/C++ volatile. Remember that reads and writes of these
    variables are not necessarily atomic, however.
**/


volatile int _vlaue;

int main()
{
    std::cout << "Volatile variable : " << _vlaue << std::endl;
    return 0;
}
