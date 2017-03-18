#include <iostream>
#include <mutex>

#pragma once

/****    Singleton         kreacyjny wzorzec projektowy    ****/

class ConsolLogger
{
public:
    /**
    publiczna statyczna metoda
    - ogranicza mo¿liwoœæ tworzenia obiektu danej klasy do jednej instancji
    - tworzenie obiektu w momencie jego pierwszego u¿ycia (lazy initialization)
    - globalny dostêp do stworzenego obiektu
    **/
    static ConsolLogger& Instance();

    /** delete move/copy constructor and move/copy assignment operator **/
    ConsolLogger(ConsolLogger const&) = delete;
    ConsolLogger(ConsolLogger&&) = delete;
    ConsolLogger& operator=(ConsolLogger const&) = delete;
    ConsolLogger& operator=(ConsolLogger &&) = delete;

    /**
    inne metody i pola u¿ytkowe
    **/
    void log(const std::string&);
private:
    /** private constructor **/
    ConsolLogger() = default;

    /** mutex odpowiada za synchronizacje miêdzy w¹tkami i chroni
        wspó³dzielony obszar przed jednoczesnym dostêpem wielu w¹tków **/
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
   lock_guard - koncepcja wzorca projektowego RAII która
        zak³ada sekcjê krytyczn¹ w momencie tworzenia (lock) i
        zwalnia j¹ w momencie gdy przestaje istnieæ (unlock).

   mo¿na równie¿ u¿yæ: unique_lock lub mutex.lock()/unlock()
   **/
   std::lock_guard<std::mutex> guard(create_instance_m);
   static ConsolLogger instance;
   return instance;
}
