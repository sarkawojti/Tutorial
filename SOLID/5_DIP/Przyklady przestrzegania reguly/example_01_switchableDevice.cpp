#include <iostream>
#include <memory>

/** TASK-1 : Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt radio   **/
/** TASK-2 : Dodanie klasy sterujacej przyciskiem wlacz/wylacz obiekt czajnik **/

/** TASK-1/TASK-2 dodanie abstrakcji dla modulu niskopoziomowego **/
class SwitchableDevice
{
public:
    virtual void turn_off() = 0;
    virtual void turn_on() = 0;

    virtual ~SwitchableDevice() = default;
};

/** TASK-1: dodanie modulu niskiego poziomu do rodziny 'abstrakcji' **/
class Radio : public SwitchableDevice
{
public:
    void turn_on() override { std::cout << "Radio ON" << std::endl; }
    void turn_off() override { std::cout << "Radio OFF" << std::endl; }
};

/** TASK-2: dodanie modulu niskiego poziomu do rodziny 'abstrakcji' **/
class Kettle : public SwitchableDevice
{
public:
    void turn_on() override { std::cout << "Kettle ON" << std::endl; }
    void turn_off() override { std::cout << "Kettle OFF" << std::endl; }
};

/** TASK-1/TASK-2: dodanie abstrakcji dla modulu wyskiego poziomu **/
class ClickButton
{
    virtual void click() = 0;

    virtual ~ClickButton() = default;
};

/** TASK-1/TASK-2: Dodanie modulu wysokiego poziomu zarzadzajacego
    przyciskiem wlacz/wylacz obiektu TYPU 'SwitchableDevice' -
    sterujacego dowolnym modulem niskopoziomowym z danej rodziny 'abstrakcji' **/
class SwitchButton : public ClickButton
{
    std::shared_ptr<SwitchableDevice> _device;

    bool on = false;

public:
    SwitchButton(const std::shared_ptr<SwitchableDevice>& device): _device(device){}

    void click() override
    {
        if(on) _device->turn_off();
        else   _device->turn_on();
        on = not on;
    }
};

int main()
{
    std::shared_ptr<SwitchableDevice> radio = std::make_shared<Radio>();
    SwitchButton _radio_button(radio);
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();
    _radio_button.click();

    std::shared_ptr<SwitchableDevice> kettle = std::make_shared<Kettle>();
    SwitchButton _kettle_button(kettle);
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();
    _kettle_button.click();

    return 0;
}

