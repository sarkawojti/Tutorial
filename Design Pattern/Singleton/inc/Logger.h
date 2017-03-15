#include <iostream>
#include <mutex>

#pragma once

class Logger
{
public:
    // publiczna statyczna metoda odpowiedzialna za:
    // 1. stworzenie obiektu tylko raz i tylko gdy jest on potrzebny (lazy initialization)
    // 2. dostêp do statycznego pola bêd¹cego jedyn¹ instancj¹ obiektu
    static Logger& Instance();

    // inne metody i pola u¿ytkowe
    void consolLog(const std::string&);
private:
    // private constructor
    Logger() = default;

    //mutex odpowiada za synchronizacje miêdzy w¹tkami
    //chroni wspó³dzielony obszar przed jednoczesnym dostêpem wielu w¹tków
    static std::mutex createInstanceMutex;
    std::mutex consolLogMutex;
};

std::mutex Logger::createInstanceMutex;

void Logger::consolLog(const std::string& text)
{
    //thread-safe cout method
    std::lock_guard<std::mutex> guard(consolLogMutex);
    std::cout << text << std::endl;
}

Logger& Logger::Instance()
{
   //thread-safe Singleton
   //lock guard - koncepcja wzorca projektowego RAII
   //zak³ada sekcjê krytyczn¹ (lock) i zwalnia j¹ w momencie gdy przestaje istnieæ (unlock).
   //
   //mo¿na równie¿ u¿yæ: unique_lock lub mutex.lock()/unlock()
   //
   std::lock_guard<std::mutex> guard(createInstanceMutex);
   static Logger instance;
   return instance;
}
