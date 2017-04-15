#pragma once

#include "USASocketInterface.h"

#include <memory>

class EuropeanSocketInterface;

class AdapterSocket : public USASocketInterface
{
    std::shared_ptr<EuropeanSocketInterface> socket;

public:
    void plug_in(const std::shared_ptr<EuropeanSocketInterface>&);

    int voltage() override;
    int live() override;
    int neutral() override;
};
