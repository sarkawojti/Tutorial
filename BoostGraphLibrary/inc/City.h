#pragma once

#include<iostream>

class City  /** PropertyVertex **/
{
public:
    City(std::string _name = ""): name(_name){}

    friend bool operator==(const City& lCity, const City& rCity)
    {
        return lCity.name == rCity.name;
    }

    friend std::ostream& operator<<(std::ostream& p_os, const City& pCity)
    {
        p_os << pCity.name;
        return p_os;
    }

    ~City(){ std::cout << "Destroyed " << this << "." << std::endl; }

private:
    std::string name;
};
