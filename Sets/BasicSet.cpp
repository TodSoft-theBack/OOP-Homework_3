#include "BasicSet.h"

BasicSet::BasicSet(const int32_t* elements, uint16_t count)
{
    _elements = std::move(Vector<int32_t>(elements, count));
}

bool BasicSet::Contains(int32_t element) const 
{
    return _elements.Contains(element);
}

void BasicSet::SaveToFile(const char* filename) const
{
    std::ofstream stream(filename, std::ios::out | std::ios::binary);
    if (!stream)
        throw std::runtime_error("Problem opening file!!!");
    uint16_t N = _elements.Count(), T = BasicSet::TYPE;
    stream.write((const char*)&N, sizeof(N));
    stream.write((const char*)&T, sizeof(T));
    stream.write((const char*)_elements.Collection(), sizeof(int32_t) * N);
    stream.close();
}