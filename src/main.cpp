#include <iostream>
#include <memory>
#include "composite_password_generator.h"
#include "digit_generator.h"
#include "symbol_generator.h"
#include "letter_generator.h"


int main(int argc, char *argv[]) 
{
    size_t difficult = 3;

    if(argc == 2)
    {
        int arg = std::atoi(argv[1]);
        if (arg <=0 || arg >9)
        {
            std::cout << "wrong difficult value (int argument), it must be between 0 and 10" << std::endl;
            return 0;
        }
        difficult = arg;
    }

    CompositePasswordGenerator generator;
    generator.Add(std::make_unique<LowerLetterGenerator>(difficult));
    generator.Add(std::make_unique<UpperLetterGenerator>(difficult));
    generator.Add(std::make_unique<DigitGenerator>(difficult));
    generator.Add(std::make_unique<SymbolGenerator>(difficult));
    auto password = generator.Generate();

    std::cout << password << std::endl;
    return 0;
}