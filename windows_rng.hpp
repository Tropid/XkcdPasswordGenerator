#ifdef _WIN32

#pragma once

#include "rng.hpp"
#include "types.hpp"

#include <Windows.h>
#include <Wincrypt.h>

namespace pwgen
{

class WindowsRNG : public RNG
{
public:
    WindowsRNG();

    virtual uint32 GenerateNumber(uint32 max) override;

private:
    HCRYPTPROV hCryptProv;
};

}
#endif
