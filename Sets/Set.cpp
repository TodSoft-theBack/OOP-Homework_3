#include "Set.h"

uint16_t Set::UNIQUE_INDEX = 0;
const char* Set::FILE_NAMES[MAX_ELEMENT_COUNT] = { "./BinaryFiles/First.bin", "./BinaryFiles/Second.bin", "./BinaryFiles/Third.bin", "./BinaryFiles/Forth.bin", "./BinaryFiles/Fifth.bin"};

void Set::PrintInInterval(int32_t a, int32_t b) const
{
    std::cout << "[" << a << ", " << b << "] => { ";
    for (int32_t i = a; i <= b; i++)
        if ((*this).Contains(i))
            std::cout << i << ", ";
    std::cout << " }" << std::endl;
}

void Set::PrintNext(int32_t current) const
{
    std::cout << current << " => { ";
    int32_t	maxValue = std::numeric_limits<std::int32_t>::max();
    for (int32_t i = current + 1; i < maxValue; i++)
        if ((*this).Contains(i))
        {
            std::cout << i;
            break;
        }
    std::cout << " }" << std::endl;
}