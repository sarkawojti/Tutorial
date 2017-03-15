#include <iostream>
#include <mutex>

#pragma once

/****    Singleton         kreacyjny wzorzec projektowy    ****/

class Logger
{
public:
    /**
    publiczna statyczna metoda
    - ogranicza mo¿liwoœæ tworzenia obiektu danej klasy do jednej instancji
    - tworzenie obiektu w momencie jego pierwszego u¿ycia (lazy initialization)
    - globalny dostêp do stworzenego obiektu
    **/
    static Logger& Instance();

    /** delete move/copy constructor and move/copy assignment operator **/
    Logger(Logger const&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger const&) = delete;
    Logger& operator=(Logger &&) = delete;

    /**
    inne metody i pola u¿ytkowe
    **/
    void console_log(const std::string&);
private:
    /** private constructor **/
    Logger() = default;

    /** mutex odpowiada za synchronizacje miêdzy w¹tkami i chroni
        wspó³dzielony obszar przed jednoczesnym dostêpem wielu w¹tków **/
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
   lock_guard - koncepcja wzorca projektowego RAII która
        zak³ada sekcjê krytyczn¹ w momencie tworzenia (lock) i
        zwalnia j¹ w momencie gdy przestaje istnieæ (unlock).

   mo¿na równie¿ u¿yæ: unique_lock lub mutex.lock()/unlock()
   **/
   std::lock_guard<std::mutex> guard(create_instance_m);
   static Logger instance;
   return instance;
}
