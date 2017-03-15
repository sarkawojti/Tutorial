#include <iostream>
#include <mutex>

#pragma once

class Logger
{
public:
    // publiczna statyczna metoda odpowiedzialna za:
    // 1. stworzenie obiektu tylko raz i tylko gdy jest on potrzebny (lazy initialization)
    // 2. dost�p do statycznego pola b�d�cego jedyn� instancj� obiektu
    static Logger& Instance();

    // inne metody i pola u�ytkowe
    void consolLog(const std::string&);
private:
    // private constructor
    Logger() = default;

    //mutex odpowiada za synchronizacje mi�dzy w�tkami
    //chroni wsp�dzielony obszar przed jednoczesnym dost�pem wielu w�tk�w
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
   //zak�ada sekcj� krytyczn� (lock) i zwalnia j� w momencie gdy przestaje istnie� (unlock).
   //
   //mo�na r�wnie� u�y�: unique_lock lub mutex.lock()/unlock()
   //
   std::lock_guard<std::mutex> guard(createInstanceMutex);
   static Logger instance;
   return instance;
}
