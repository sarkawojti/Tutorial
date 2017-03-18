#include <iostream>
#include <mutex>

#pragma once

/****    Singleton         kreacyjny wzorzec projektowy    ****/

class ConsolLogger
{
public:
    /**
    publiczna statyczna metoda
    - ogranicza mo�liwo�� tworzenia obiektu danej klasy do jednej instancji
    - tworzenie obiektu w momencie jego pierwszego u�ycia (lazy initialization)
    - globalny dost�p do stworzenego obiektu
    **/
    static ConsolLogger& Instance();

    /** delete move/copy constructor and move/copy assignment operator **/
    ConsolLogger(ConsolLogger const&) = delete;
    ConsolLogger(ConsolLogger&&) = delete;
    ConsolLogger& operator=(ConsolLogger const&) = delete;
    ConsolLogger& operator=(ConsolLogger &&) = delete;

    /**
    inne metody i pola u�ytkowe
    **/
    void log(const std::string&);
private:
    /** private constructor **/
    ConsolLogger() = default;

    /** mutex odpowiada za synchronizacje mi�dzy w�tkami i chroni
        wsp�dzielony obszar przed jednoczesnym dost�pem wielu w�tk�w **/
    static std::mutex create_instance_m;
    std::mutex console_log_mutex;
};

std::mutex ConsolLogger::create_instance_m;

void ConsolLogger::log(const std::string& text)
{
    /** thread-safe cout method **/
    std::lock_guard<std::mutex> guard(console_log_mutex);
    std::cout << text << std::endl;
}

ConsolLogger& ConsolLogger::Instance()
{
   /**thread-safe Singleton
   lock_guard - koncepcja wzorca projektowego RAII kt�ra
        zak�ada sekcj� krytyczn� w momencie tworzenia (lock) i
        zwalnia j� w momencie gdy przestaje istnie� (unlock).

   mo�na r�wnie� u�y�: unique_lock lub mutex.lock()/unlock()
   **/
   std::lock_guard<std::mutex> guard(create_instance_m);
   static ConsolLogger instance;
   return instance;
}
