#include <iostream>
#include <vector>

/** TASK-1 : Dodanie klasy reprezentujacej pracownika, ktory musi jesc **/
/** TASK-2 : Dodanie klasy reprezentujacej pracownika-robota, ktory nie musi jesc **/


/** TASK-1/ TASK-2: dodanie interfejsu 'pracuj' i 'jedz' **/
class IWorker
{
public:
    /** MINUS - interfejs odpowiedzialny za dwie nie powiazane funkcjonalnosci - 'fat interface' **/
    virtual void work() = 0;
    virtual void eat() = 0;

    virtual ~IWorker() = default;
};

/** TASK-1: dodanie klasy reprezentujacej pracownika, ktory musi jesc **/
class Worker : public IWorker
{
public:
   void work() override
   {
       std::cout << "Now a worker works." << std::endl;
   }

   void eat() override
   {
       std::cout << "Now a worker eats." << std::endl;
   }
};

/** TASK-1: dodanie klasy reprezentujacej pracownika-robota, ktory nie musi jesc **/
class Robot : public IWorker
{
public:
   void work() override
   {
       std::cout << "Now a worker-robot works." << std::endl;
   }

   /** MINUS - dostarczony interfejs zmusza klienta do implementacji
            pustej metody ['dummy function'] - 'fat interface', aby
            sprostac wymaganiom interfejsu

       istnieja pracownicy,ktorzy tylko pracuja bez jedzenia **/
   void eat() override
   {
       std::cout << "Robot does not have to eat" << std::endl;
       throw std::string("Robot not implemented eat function");
   }
};

int main()
{
    Worker worker;
    Robot robot;

    std::vector<IWorker*> workers =
    {
        &worker,
        &robot
    };

    for(IWorker* worker : workers)
    {
        worker->work();
        try{
            worker->eat();
        } catch(const std::string& e){
            std::cout << e << std::endl;
        }
    }
}
