
#include "../inc/ProxyCar.h"

void ProxyCar::drive(const Driver& driver) const
{
    /** kontrola dostepu do chronionego obiektu, sprawdzajac prawa obiektu wywolujacego  **/
    if(MIN_AGE_TO_DRIVE_A_CAR > driver.age())
    {
        /** wykonania dodatkowych akcji podczas dostepu do obiektu  - zliczanie statystyk **/
        _fail_drive++;
        return;
    }

    /** lazy initialization - opoznienie tworzenia kosztownego obiektu, tworzac go gdy jest potrzebny **/
    if(not _car)
    {
        const_cast<ProxyCar*>(this)->_car = std::make_shared<Car>();
    }

    /** wykonania dodatkowych akcji podczas dostepu do obiektu  - zliczanie statystyk **/
    _success_drive++;
    _car->drive(driver);
}
