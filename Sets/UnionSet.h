#pragma once
#include "Set.h"
#include <fstream>

class UnionSet : public Set
{
    private:
        Set* _sets[Set::MAX_ELEMENT_COUNT];
        uint16_t _count = 0;
        static const uint16_t TYPE = 3;

    public:
        UnionSet(Set* const sets[Set::MAX_ELEMENT_COUNT], uint16_t count);
        bool Contains(int32_t element) const override;
        void SaveToFile(const char* filename) const override;
        ~UnionSet();
};
