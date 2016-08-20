#include "generator.hpp"

#ifdef _WIN32
#include <Windows.h>
#include <Wincon.h>
#endif

#include <iostream>

int main()
{
#ifdef _WIN32
    // Enable special chars in console
    SetConsoleOutputCP(1252);
#endif

    try
    {
        pwgen::Generator generator("words.dic");

        char input;
        do
        {
            std::cout << generator.GeneratePassword(4) << std::endl;
        } while ((input = std::getchar()) != 'e');
    }
    catch (std::exception& e)
    {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
}

