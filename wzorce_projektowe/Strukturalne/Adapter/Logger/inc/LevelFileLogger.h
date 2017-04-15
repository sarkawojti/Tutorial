
#pragma once

#include "ILevelLogger.h"
#include "FileLogger.h"

/** adapter klasowy **/
/** wykorzystanie wielodziedziczenia:
    publicznie po oczekiwanym interfejsie Traget(ILevelLogger)
    prywatnie po niekompatybilnej klasie Adaptee(FileLogger) **/
class LevelFileLogger : public ILevelLogger, private FileLogger
{
public:
    LevelFileLogger(const std::string&);

    void info(const std::string&) const override;
    void error(const std::string&) const override;
    void warning(const std::string&) const override;
    void debug(const std::string&) const override;
};
