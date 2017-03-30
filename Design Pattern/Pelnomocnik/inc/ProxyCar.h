#pragma once

#include "Car.h"
#include "Driver.h"

#include <memory>
#include <iostream>

/** zapewnia identyczny interfejs co reprezentowany object**/
class ProxyCar : public ICar
{

private:
    /** odwolanie do prawdziwego obiektu **/
    std::shared_ptr<ICar> _car;

    static constexpr short MIN_AGE_TO_DRIVE_A_CAR = 18;
public:

    void drive(const Driver& driver) const override;

    /** wykonania dodatkowych akcji podczas dostepu do obiektu  - zliczanie statystyk **/
    mutable unsigned _fail_drive = 0;
    mutable unsigned _success_drive = 0;
};
