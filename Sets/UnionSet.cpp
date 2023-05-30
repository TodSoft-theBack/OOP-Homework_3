#include "UnionSet.h"


UnionSet::UnionSet(Set* const sets[Set::MAX_ELEMENT_COUNT], uint16_t count)
{
    _count = count;
    for (size_t i = 0; i < count; i++)
        _sets[i] = sets[i];
}

bool UnionSet::Contains(int32_t element) const
{
    for (size_t i = 0; i < _count; i++)
    {
        if (_sets[i] == nullptr)
            throw std::runtime_error("Set pointer was NULL!!!");
        if (!_sets[i]->Contains(element))
            return false;
    }
    return false;
}

void UnionSet::SaveToFile(const char* filename) const
{
    std::ofstream stream(filename, std::ios::out | std::ios::binary);
    if (!stream.is_open())
        throw std::runtime_error("Problem opening file!!!");
        
    uint16_t N = _count, T = UnionSet::TYPE;
    stream.write((const char*)&N, sizeof(N));
    stream.write((const char*)&T, sizeof(T));
    for (size_t i = 0; i < _count; i++)
    {
        const char* uniqueName = Set::FILE_NAMES[Set::UNIQUE_INDEX++];
        _sets[i]->SaveToFile(uniqueName);
        stream << uniqueName << '\0';
    } 
    stream.close();
}

UnionSet::~UnionSet()
{
    for (size_t i = 0; i < Set::MAX_ELEMENT_COUNT; i++)
        delete _sets[i];
}