#include "inc/Logger.h"

void log(const std::string& text)
{
    ConsolLogger::Instance().log(text);
}

int main()
{
    log("Hello world!!!");
    return 0;
}
