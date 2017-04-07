
#include "inc/Invoker.h"
#include "inc/Calculator.h"
#include "inc/AddCommand.h"
#include "inc/SubCommand.h"

int main()
{
    Invoker<int> invoker;
    invoker.invoke(4, 6);

    std::shared_ptr<ICommand<int>> add_command = std::make_shared<AddCommand<int>>();

    invoker.set_command(add_command);
    int param1 = 4, param2 = 7;
    std::cout << param1 << " + " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;
    param1 = 4, param2 = -7;
    std::cout << param1 << " + " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;

    std::shared_ptr<ICommand<int>> sub_command = std::make_shared<SubCommand<int>>();

    invoker.set_command(sub_command);
    param1 = 4, param2 = 7;
    std::cout << param1 << " - " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;
    param1 = 4, param2 = -7;
    std::cout << param1 << " - " << param2 << " = " << invoker.invoke(param1, param2) << std::endl;


    return 0;
}
