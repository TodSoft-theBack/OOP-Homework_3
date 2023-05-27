#pragma once
#include <iostream>

class Set
{
    public:
        static const uint16_t MAX_ELEMENT_COUNT  = 32u;
        Set() = default;
        virtual bool Contains(int32_t element) const = 0;
        virtual void PrintInInterval(int a, int b) const = 0;
        virtual void PrintNext(unsigned current) const = 0;
        virtual void SaveToFile(const char* filename) const = 0;
        virtual ~Set() = default;
};