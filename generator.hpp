#pragma once

#include "types.hpp"
#include "rng.hpp"

#include <string>
#include <fstream>

namespace pwgen
{

// Generates secure passwords based on the xkcd password comic.
// see: https://xkcd.com/936/
class Generator
{
public:
    Generator(const std::string& wordFile);

    std::string GeneratePassword(uint32 wordCount);

private:
    uint32 CountLines();

    std::string GetRandomWord();

private:
    std::ifstream wordFile;
    RNG* rng;
    uint32 lineCount;
};

}
