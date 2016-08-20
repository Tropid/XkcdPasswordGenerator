#pragma once

#ifdef _WIN32
#include "rng.hpp"
#include "windows_rng.hpp"

static pwgen::WindowsRNG rng;

pwgen::RNG* getRNG()
{
    return &rng;
}
#else
static_assert(false, "No RNG for OS");
#endif


