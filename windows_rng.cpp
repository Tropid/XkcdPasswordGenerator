#ifdef _WIN32

#include "windows_rng.hpp"

#include <exception>
#include <stdexcept>

namespace pwgen
{

WindowsRNG::WindowsRNG()
{
    if (!CryptAcquireContext(&hCryptProv, nullptr, nullptr, PROV_RSA_AES, 0))
    {
        throw std::runtime_error("Failed to acquire crypto context.");
    }
}

uint32 WindowsRNG::GenerateNumber(uint32 max)
{
    uint32 out;
    if (!CryptGenRandom(hCryptProv, sizeof(out), reinterpret_cast<BYTE*>(&out)))
    {
        throw std::runtime_error("Failed to generate random number.");
    }

    return out % max;
}

}

#endif
