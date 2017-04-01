#include <iostream>
#include <memory>

class B
{
public:

    B(const int b)
    {
        if(b > 10)
        {
            throw 1;
        }

        _b = b;
        std::cout << " Created object B with " << _b << std::endl;
    }

    ~B()
    {
        std::cout << " Destroyed object B with " << _b << std::endl;
    }

private:
    int _b;
};

class A
{
public:
    /** Czy tworzenie obiektu zakonczylo sie powodzeniem ?? **/
    A(int one, int two, int three) try :b3(std::make_shared<B>(one)), b1(two), b2(three)
        /** konstrukcja try-catch dla list inicjalizacyjnych konstruktora **/
    {
        /** cialo konstruktora **/
    }
    catch(int _exception)
    {
        /** Brak dostepu do pol klasy A poniewaz nie zostala stworzona **/
        std::cout << "Catch exception in A. [" << _exception << "]" << std::endl;
        //throw 2;
    }

    /**
        rzucanie wyjatkow w konstruktorze moze powodowac szereg problemow :
            wyciek pamieci, niespojnosc obiektu.

        gwarancja , iz w momencie rzucenia wyjatku podobiekty poprawnie
        skonstruowane (jak rowniez poprawnie stworzone klasy bazowe)
        zostana zniszczone a obiekty nie calkiem stworzone nie.
        [OBIEKTY NA STOSIE]

        dla skladowych wskaznikowych powinnismy skorzystac z idiomu RAII
        czyli wzorca projektowego. ktorego zadaniem jest przejecie kontroli
        nad zasobem w chwili tworzenia obiektu i zagwarantowanie, ze zasob
        zostanie automatycznie zwolniony.
    **/

    ~A()
    {
         /** delete b3; **/

         /** Co jesli destruktor rzuci wyjatek **/

         /**
            NIE RZUCA SIE WYJATKOW Z DESTRUKTORA

            - rzucenie wyjatku spowoduje identyczne skutki co nie zlapanie wyjatku:
              wywolanie funkcji "terminate" a ona wola w sobie funkcje "abort"
              [destruktory lokalnych obiektow nie zostana wykonane].

            - w tym wypadku rzucenie wyjatku nie spowoduje niejawnego
              zawolania destruktorow dla podobiektow.
         **/
    }
private:
    /** B* b3 **/
    std::shared_ptr<B> b3;  /** wzorzec projektowy RAII **/
    B b1;
    B b2;
};


int main()
{
    try
    {
        A a(3, 9, 12);
    }
    catch(int _exception)
    {
        std::cout << "Catch exception in main. [" << _exception << "]" << std::endl;
    }



    return 0;
}
