#include "IntersectionSet.h"


IntersectionSet::IntersectionSet(Set* const sets[Set::MAX_ELEMENT_COUNT])
{

}

bool IntersectionSet::Contains(int32_t element) const
{
    return true;
}

void IntersectionSet::PrintInInterval(int a, int b) const
{

}

void IntersectionSet::PrintNext(unsigned current) const
{

}

void IntersectionSet::SaveToFile(const char* filename) const 
{
    
}

IntersectionSet::~IntersectionSet()
{
    for (size_t i = 0; i < Set::MAX_ELEMENT_COUNT; i++)
        delete sets[i];
}