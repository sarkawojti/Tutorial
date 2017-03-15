#include "inc/Logger.h"

void log(const std::string& text)
{
    Logger::Instance().console_log(text);
}

int main()
{
    log("Hello world!!!");
    return 0;
}
