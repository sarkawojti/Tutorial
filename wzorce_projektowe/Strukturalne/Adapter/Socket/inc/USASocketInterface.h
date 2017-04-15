#pragma once

class USASocketInterface
{
public:
    virtual int voltage() = 0;

    virtual int live() = 0;
    virtual int neutral() = 0;
};
