
#pragma once

class Driver
{
private:
    int _age;

public:
    Driver(const int& age):_age(age){}

    int age() const { return _age; }
};
