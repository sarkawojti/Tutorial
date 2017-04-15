#pragma once

#include "ILevelLogger.h"
#include "ConsolLogger.h"

/** adapter klasowy **/
/** wykorzystanie wielodziedziczenia:
        publicznie po oczekiwanym interfejsie Traget(ILevelLogger)
        prywatnie po niekompatybilnej klasie Adaptee(ConsolLogger) **/
class LevelConsolLogger : public ILevelLogger, private ConsolLogger
{
private:
    /** mozliwosc przesloniecia metod Adaptee **/
    void log(const std::string&, const std::string&) const override;
public:
    void info(const std::string&) const override;
    void error(const std::string&) const override;
    void warning(const std::string&) const override;
    void debug(const std::string&) const override;
};
