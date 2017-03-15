#include <iostream>

#pragma once;

class Logger
{
public:
    // publiczna statyczna metoda odpowiedzialna za:
    // 1. stworzenie obiektu tylko raz i tylko gdy jest on potrzebny (lazy initialization)
    // 2. dost�p do statycznego pola b�d�cego jedyn� instancj� obiektu
    static Logger& Instance();

    // inne metody i pola u�ytkowe
    void consolLog(const std::string&) const;
private:
    // private constructor
    Logger() = default;
};

void Logger::consolLog(const std::string& text) const
{
    std::cout << text << std::endl;
}

Logger& Logger::Instance()
{
   static Logger instance;
   return instance;
}
