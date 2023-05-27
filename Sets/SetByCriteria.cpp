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

void SetByCriteria::PrintInInterval(int a, int b) const
{
    std::cout << "[" << a << ", " << b << "] => { ";
    for (int32_t i = a; i <= b; i++)
        if (this->Contains(i))
            std::cout << i << ( i != b ? ", ": "");
    std::cout << " }" << std::endl;
}

void SetByCriteria::PrintNext(unsigned current) const
{

}

void SetByCriteria::SaveToFile(const char* filename) const
{
    std::ofstream stream(filename, std::ios::out | std::ios::binary);
    if (!stream)
        throw std::runtime_error("Problem opening file!!!");
    _criteria.SaveToStream(stream);
    stream.close();
}