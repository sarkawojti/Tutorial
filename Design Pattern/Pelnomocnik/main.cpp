
#include <iostream>
#include <memory>
#include <cassert>

#include "inc/ProxyCar.h"

int main()
{
    std::shared_ptr<ICar> car = std::make_shared<ProxyCar>();

    assert(0 == static_cast<ProxyCar&>(*car)._fail_drive);
    assert(0 == static_cast<ProxyCar&>(*car)._success_drive);

    car->drive(Driver(9));

    assert(1 == static_cast<ProxyCar&>(*car)._fail_drive);
    assert(0 == static_cast<ProxyCar&>(*car)._success_drive);

    car->drive(Driver(18));

    assert(1 == static_cast<ProxyCar&>(*car)._fail_drive);
    assert(1 == static_cast<ProxyCar&>(*car)._success_drive);

    return 0;
}

/** Pelnomocnik  - obiektowy wzorzec strukturalny **/

/**

Stworzenie klasy, ktora zastepuje/emuluje zachowanie innego obiektu/klasy w celu:
    - kontrola dostepu do chronionego obiektu, sprawdzajac prawa obiektu wywolujacego                [ochraniajacy pelnomocnik]
    - opoznienie tworzenia kosztownego obiektu, tworzac go gdy jest potrzebny [lazy initialization]  [wirtualny pelnomocnik]
    - reprezentacja obiektow z innej przestrzeni adresowej                                           [zdalny pelnomocnik (ambasador)]
    - wykonania dodatkowych akcji podczas dostepu do obiektu (np. zliczanie referencji)              [sprytne odwolanie (sprytne wskazniki)]


ARCHITEKTURA:
    Subject     - klasa definiujaca wspolny interfejs dla RealSubject i Proxy.
    RealSubject - definiuje rzeczywisty objekt/klase representowany przez Proxy.
    Proxy       - przechowuje odwolanie umozliwiajace dostep do RealSubject,
                  zapewnia identyczny interfejs co Subject,
                  moze byc zastapiony obiektem typu Subject,
                  kontroluje dostep do RealSubject oraz moze byc odpowiedzialny za jego tworzenie/usuwanie.
**/
