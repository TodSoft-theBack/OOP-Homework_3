#pragma once
#include <fstream>
#include "Set.h"
#include "Vector.hpp"

class BasicSet : public Set
{
    Vector<int32_t> _elements;
    static const uint16_t TYPE = 0;
    public:
        BasicSet(const int32_t* elements, uint16_t count);
        void Add(int32_t element);
        bool Contains(int32_t element) const override;
        void SaveToFile(const char* filename) const override;
        ~BasicSet() = default;
};