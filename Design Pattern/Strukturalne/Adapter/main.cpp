
#include <memory>
#include <cassert>

#include "inc/IStack.h"
#include "inc/Stack.h"
#include "inc/StackClassAdapter.h"


int main()
{
    std::shared_ptr<IStack<int>> _stack = std::make_shared<Stack<int>>();

    assert(true == _stack->isEmpty());
    assert(0 == _stack->size());

    _stack->push(97);
    _stack->push(96);
    _stack->push(91);

    assert(false == _stack->isEmpty());
    assert(3 == _stack->size());

    assert(91 == _stack->pop());
    assert(96 == _stack->pop());
    assert(97 == _stack->pop());

    assert(true == _stack->isEmpty());
    assert(0 == _stack->size());


    std::shared_ptr<IIStack<int>> _stack_ = std::make_shared<StackClassAdapter<int>>();

    assert(true == _stack_->is_empty());
    assert(0 == _stack_->num_of_elem());

    _stack_->push_elem(97);
    _stack_->push_elem(96);
    _stack_->push_elem(91);

    assert(false == _stack_->is_empty());
    assert(3 == _stack_->num_of_elem());

    assert(91 == _stack_->pop_elem());
    assert(96 == _stack_->pop_elem());
    assert(97 == _stack_->pop_elem());

    assert(true == _stack_->is_empty());
    assert(0 == _stack_->num_of_elem());

    return 0;
}

/**

    ====================================================================================================

    NAZWA           ADAPTER - obiektowy lub klasowy wzorzec strukturalny

    ====================================================================================================

    PRZEZNACZENIE   konwersja interfejsu danej klasy/obiektu do postaci zgodnej z oczekiwaniami klienta,
                    pomoc we wspolpracy dwoch klas o niekompatybilnym interfejsie

    ====================================================================================================

    ARCHITEKTURA
            CLIENT  - wspolpraca z obiektami dostaczonymi do interfejsu TARGET
            TARGET  - definiuje interfejs oczekiwany przez CLIENT
            ADAPTEE - definiuje istniejacy intrfejs wymagajacy zaadoptowania do wymagan
            ADAPTER - adaptuje interfejs ADAPTEE do TARGET


            Adapter obiektowy:
                - dziedziczy interfejs docelowy
                - przechowuje odwolanie umozliwiajace dostep do ADAPTEE

            Adapter klasowy:
                - dziedziczy wielkrotnie: prywatnie z ADAPTEE i publicznie z TARGET

    ====================================================================================================

    KONSEKWENCJE

            Adapter obiektowy:
                - jeden ADAPTER moze dzialac z wieloma obiektami adaptowanymi (ADAPTEE i jej podklasami)
                - przedefiniowanie zachowania ADAPTEE jest trudne
                 [tworzenie odklas ADAPTEE i odwolanie sie do nich ADAPTERA]

            Adapter klasowy:
                - jeden ADAPTER moze dziaalc tylko z jedna konkretna klasa ADAPTEE
                - przedefiniowanie zachowania ADAPTEE jest proste

    ====================================================================================================
**/


