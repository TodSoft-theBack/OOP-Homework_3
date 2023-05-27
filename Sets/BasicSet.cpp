#include "BasicSet.h"

BasicSet::BasicSet(const int32_t* elements, uint16_t count)
{
    _elements = std::move(Vector<int32_t>(elements, count));
}

bool BasicSet::Contains(int32_t element) const 
{
    return _elements.Contains(element);
}

void BasicSet::PrintInInterval(int a, int b) const
{
    std::cout << "[" << a << ", " << b << "] => { ";
    for (int32_t i = a; i <= b; i++)
        if (_elements.Contains(i))
            std::cout << i << ( i != b ? ", ": "");
    std::cout << " }" << std::endl;
}

void BasicSet::PrintNext(unsigned current) const 
{

}

void BasicSet::SaveToFile(const char* filename) const
{
    std::ofstream stream(filename, std::ios::out | std::ios::binary);
    if (!stream)
        throw std::runtime_error("Problem opening file!!!");
    uint16_t N = _elements.Count();
    stream.write((const char*)&N, sizeof(uint16_t));
    stream.write((const char*)&BasicSet::TYPE, sizeof(uint16_t));
    stream.write((const char*)_elements.Collection(), sizeof(int32_t) * N);
    stream.close();
}