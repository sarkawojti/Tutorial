#include <iostream>
#include <mutex>

#pragma once

/****    Singleton         kreacyjny wzorzec projektowy    ****/

class Logger
{
public:
    /**
    publiczna statyczna metoda
    - ogranicza mo�liwo�� tworzenia obiektu danej klasy do jednej instancji
    - tworzenie obiektu w momencie jego pierwszego u�ycia (lazy initialization)
    - globalny dost�p do stworzenego obiektu
    **/
    static Logger& Instance();

    /** delete move/copy constructor and move/copy assignment operator **/
    Logger(Logger const&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger const&) = delete;
    Logger& operator=(Logger &&) = delete;

    /**
    inne metody i pola u�ytkowe
    **/
    void console_log(const std::string&);
private:
    /** private constructor **/
    Logger() = default;

    /** mutex odpowiada za synchronizacje mi�dzy w�tkami i chroni
        wsp�dzielony obszar przed jednoczesnym dost�pem wielu w�tk�w **/
    static std::mutex create_instance_m;
    std::mutex console_log_mutex;
};

std::mutex Logger::create_instance_m;

void Logger::console_log(const std::string& text)
{
    /** thread-safe cout method **/
    std::lock_guard<std::mutex> guard(console_log_mutex);
    std::cout << text << std::endl;
}

Logger& Logger::Instance()
{
   /**thread-safe Singleton
   lock_guard - koncepcja wzorca projektowego RAII kt�ra
        zak�ada sekcj� krytyczn� w momencie tworzenia (lock) i
        zwalnia j� w momencie gdy przestaje istnie� (unlock).

   mo�na r�wnie� u�y�: unique_lock lub mutex.lock()/unlock()
   **/
   std::lock_guard<std::mutex> guard(create_instance_m);
   static Logger instance;
   return instance;
}
