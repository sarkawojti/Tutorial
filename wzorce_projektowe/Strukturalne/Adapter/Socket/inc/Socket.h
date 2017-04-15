#pragma once

#include "EuropeanSocketInterface.h"

class Socket : public EuropeanSocketInterface
{
public:
    int voltage() override;

    int live() override;
    int neutral() override;
    int earth() override;
};
