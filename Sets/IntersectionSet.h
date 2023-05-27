#pragma once
#include "Set.h"

class IntersectionSet : public  Set
{
    private:
        Set* sets[Set::MAX_ELEMENT_COUNT];
        static const uint16_t TYPE = 4;
    public:
        IntersectionSet(Set* const sets[Set::MAX_ELEMENT_COUNT]);
        bool Contains(int32_t element) const override;
        void PrintInInterval(int a, int b) const override;
        void PrintNext(unsigned current) const override;
        void SaveToFile(const char* filename) const override;
        ~IntersectionSet();
};