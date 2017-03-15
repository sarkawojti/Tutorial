#include "inc/Logger.h"

void log(const std::string& text)
{
    Logger::Instance().consolLog(text);
}

int main()
{
    log("Hello world!!!");
    return 0;
}
