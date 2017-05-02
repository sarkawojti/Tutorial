#include <iostream>

/** TASK-1 : Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt radio   **/
/** TASK-2 : Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt czajnik **/

class Radio
{
public:
    void turn_on(){ std::cout << "ON" << std::endl; }
    void turn_off(){ std::cout << "OFF" << std::endl; }

    friend std::ostream& operator << (std::ostream& _os, const Radio& _radio)
    {
        _os << "Radio ";
        return _os;
    }
};

class Kettle
{
public:
    void turn_on(){ std::cout << "ON" << std::endl; }
    void turn_off(){ std::cout << "OFF" << std::endl; }

    friend std::ostream& operator << (std::ostream& _os, const Kettle& _kettle)
    {
        _os << "Kettle ";
        return _os;
    }
};

/** TASK-1: Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt TYPU 'Radio'**/
class RadioButton
{
    /** MINUS - uzaleznienie modulu wysokopoziomowego 'RadioButton' od niskopoziomowego 'Radio' - podejscie tradycyjne **/
    /** MINUS - zmiany w klasie 'Radio' moga wymusic zmiany w klasie 'RadioButton' **/
    /** MINUS - obiekt klasy 'RadioButton' moze sterowac tylko obiektem klasy 'Radio'**/
    Radio _radio;

    bool on = false;

public:
    RadioButton(const Radio& radio): _radio(radio){}
    void click()
    {
        std::cout << _radio;
        if(on) _radio.turn_off();
        else   _radio.turn_on();
        on = not on;
    }
};

/** TASK-1: Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt TYPU 'Czajnik'**/
class KettleButton
{
    Kettle _kettle;
    /** MINUS - dodanie nowej klasy sprowadza sie do skopiowania klasy 'RadioButton'
        i wprowadzenia niezbednych poprawek - DUPLIKACJA KODU **/
    bool on = false;

public:
    KettleButton(const Kettle& kettle): _kettle(kettle){}
    void click()
    {
        std::cout << _kettle;
        if(on) _kettle.turn_off();
        else   _kettle.turn_on();
        on = not on;
    }
};

int main()
{
    Radio radio;
    RadioButton _radio_button(radio);
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();

    Kettle kettle;
    KettleButton _kettle_button(kettle);
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();

    return 0;
}
