#pragma once

#include "ILevelLogger.h"

#include <memory>

class ILogger;

/** adapter obiektowy **/
/** dziedziczy po interfejsie docelowym Target(ILevelLogger) **/
class LevelLogger : public ILevelLogger
{
    /** przechowuje odwolanie umoziliwajace dostep do metod obiektu Adaptee (ILogger) **/
    /** mozliwosc adaptacji klasy i jej podklas - wskaznik na klase bazowa (ILogger) **/
    std::shared_ptr<ILogger> _logger;

public:
    LevelLogger(const std::shared_ptr<ILogger>&);

    void set_adaptee(const std::shared_ptr<ILogger>&);

    void info(const std::string&) const override;
    void error(const std::string&) const override;
    void warning(const std::string&) const override;
    void debug(const std::string&) const override;
};
