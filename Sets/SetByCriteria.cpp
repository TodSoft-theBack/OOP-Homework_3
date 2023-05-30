#include "SetByCriteria.h"

const uint16_t SetByCriteria::TYPES[2] = {1,2};

SetByCriteria::SetByCriteria(const SetCriteria& criteria)
{
    _criteria = criteria;
}

bool SetByCriteria::Contains(int32_t element) const
{
    return _criteria(element);
}

void SetByCriteria::SaveToFile(const char* filename) const
{
    std::ofstream stream(filename, std::ios::out | std::ios::binary);
    if (!stream)
        throw std::runtime_error("Problem opening file!!!");
    _criteria.SaveToStream(stream);
    stream.close();
}