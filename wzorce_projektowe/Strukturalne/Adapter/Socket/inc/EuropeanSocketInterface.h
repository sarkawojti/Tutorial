#pragma once

class EuropeanSocketInterface
{
public:
    virtual int voltage() = 0;

    virtual int live() = 0;
    virtual int neutral() = 0;
    virtual int earth() = 0;
};
