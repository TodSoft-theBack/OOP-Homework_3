#pragma once
#include <fstream>
#include "Vector.hpp"

class SetCriteria
{
    private:
        Vector<int32_t> _elements;
        bool _type;
        bool (SetCriteria::*predicate)(int32_t) const = nullptr;
        bool HasExactlyOneFactorFromElements(int32_t element) const;
        bool HasNoFactorsFromElements(int32_t element) const;
    public:
        SetCriteria() = default;
        SetCriteria(bool type, const int32_t* elements, uint16_t count);
        void SaveToStream(std::ofstream& stream) const;
        bool operator()(int32_t element) const;
};