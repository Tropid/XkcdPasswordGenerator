#pragma once

#include "types.hpp"

namespace pwgen
{

// Describes a cryptographically secure random number generator
class RNG
{
public:
    virtual uint32 GenerateNumber(uint32 max) = 0;
};

}

