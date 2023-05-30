#pragma once
#include <iostream>

class Set
{
    public:
        static const uint16_t MAX_ELEMENT_COUNT  = 32u;
        static const char* FILE_NAMES[MAX_ELEMENT_COUNT];
        static uint16_t UNIQUE_INDEX;

    public:
        Set() = default;
        virtual bool Contains(int32_t element) const = 0;
        virtual void PrintInInterval(int32_t a, int32_t b) const;
        virtual void PrintNext(int32_t current) const;
        virtual void SaveToFile(const char* filename) const = 0;
        virtual ~Set() = default;
};