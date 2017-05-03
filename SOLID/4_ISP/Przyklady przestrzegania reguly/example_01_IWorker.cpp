#include <iostream>
#include <vector>

/** TASK-1 : Dodanie klasy reprezentujacej pracownika, ktory musi jesc **/
/** TASK-2 : Dodanie klasy reprezentujacej pracownika-robota, ktory nie musi jesc **/

/** TASK-1/ TASK-2: dodanie interfejsu 'pracuj' **/
class IWorkable
{
public:
    virtual void work() = 0;
};

/** TASK-1: dodanie interfejsu 'jedz' **/
class IFeedable
{
public:
    virtual void eat() = 0;
};

/** TASK-1: dodanie klasy reprezentujacej pracownika, ktory musi jesc **/
class Worker : public IWorkable, public IFeedable
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
class Robot : public IWorkable
{
public:
   void work() override
   {
       std::cout << "Now a worker-robot works." << std::endl;
   }
};

int main()
{
    Worker worker;
    Robot robot;

    std::vector<IWorkable*> workable_workers =
    {
        &worker,
        &robot
    };

    for(IWorkable* worker : workable_workers)
    {
        worker->work();
    }

    std::vector<IFeedable*> feedable_workers =
    {
        &worker
    };

    for(IFeedable* worker : feedable_workers)
    {
        worker->eat();
    }
}
