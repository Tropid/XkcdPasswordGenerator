#include "generator.hpp"

#include "rng_factory.hpp"

#include <algorithm>
#include <sstream>

namespace pwgen
{

Generator::Generator(const std::string& wordFile)
: wordFile(wordFile)
{
    rng = getRNG();
    lineCount = CountLines();

    if (!this->wordFile.good())
        throw std::logic_error("No 'words.dic' file provided.");
}

std::string Generator::GeneratePassword(uint32 wordCount)
{
    std::stringstream ss;
    for (uint32 iWord = 0; iWord < wordCount; iWord++)
    {
        ss << GetRandomWord();

        if (iWord < wordCount - 1)
            ss << " ";
    }

    return ss.str();
}

std::string Generator::GetRandomWord()
{
    // Search from the beginning
    wordFile.seekg(std::ios::beg);

    // Take random line/word
    uint32 randomLine = rng->GenerateNumber(lineCount);

    // Skip new line chars until we are at the correct line.
    for (uint32_t i = 0; i < randomLine; i++)
        wordFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string ret;
    std::getline(wordFile, ret);
    return ret;
}

uint32 Generator::CountLines()
{
    wordFile.seekg(std::ios::beg);
    return std::count(
            std::istreambuf_iterator<char>(wordFile),
            std::istreambuf_iterator<char>(), '\n'
    );
}

}

