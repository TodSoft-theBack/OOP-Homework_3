#include "SetByCriteria.h"

const uint16_t SetByCriteria::TYPES[2] = {1,2};

SetByCriteria::SetByCriteria(const SetCriteria& criteria)
{
    this->criteria = criteria;
}

bool SetByCriteria::Contains(int32_t element) const
{
    return criteria(element);
}

void SetByCriteria::PrintInInterval(int a, int b) const
{

}

void SetByCriteria::PrintNext(unsigned current) const
{

}

void SetByCriteria::SaveToFile(const char* filename) const
{

}