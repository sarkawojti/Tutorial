
#include "inc/Invoker.h"
#include "inc/Calculator.h"
#include "inc/Command.h"

int main()
{
    Invoker<int> invoker;
    invoker.invoke(4, 6);

    Calculator<int> calculator;

    using IntCommandType = Command<int, int(Calculator<int>::*)(const int&, const int&) const, Calculator<int>>;

    std::shared_ptr<ICommand<int>> add_command = std::make_shared<IntCommandType>(calculator, &Calculator<int>::add);
    std::shared_ptr<ICommand<int>> sub_command = std::make_shared<IntCommandType>(calculator, &Calculator<int>::sub);

    invoker.set_command(add_command);
    int param1 = 4, param2 = 7;
    std::cout << param1 << " + " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;
    param1 = 4, param2 = -7;
    std::cout << param1 << " + " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;

    invoker.set_command(sub_command);
    param1 = 4, param2 = 7;
    std::cout << param1 << " - " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;
    param1 = 4, param2 = -7;
    std::cout << param1 << " - " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;


    return 0;
}
