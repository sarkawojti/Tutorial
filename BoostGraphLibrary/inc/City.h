#pragma once

#include<iostream>

class City  /** PropertyVertex **/
{
public:
    City(const std::string& _name = ""): name(_name)
    {
    }

    friend bool operator==(const City& lCity, const City& rCity)
    {
        return lCity.name == rCity.name;
    }

    friend bool operator!=(const City& lCity, const City& rCity)
    {
        return not (lCity == rCity);
    }

    friend std::ostream& operator<<(std::ostream& p_os, const City& pCity)
    {
        p_os << pCity.name;
        return p_os;
    }

private:
    std::string name;
};
