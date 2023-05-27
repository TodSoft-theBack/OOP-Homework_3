#include "SetFactory.h"

SetFactory::SetFactory(const char* filename)
{
    set = ReadFromFile(filename);
}

SetFactory::SetFactory(uint16_t type, const int32_t* elements, uint16_t count)
{
    switch (type)
    {
        case 0:
            set = new BasicSet(elements, count);
        break;

        case 1:
        case 2:
            set = new SetByCriteria(std::move(SetCriteria(type == 2, elements, count)));
        break;

        default:
            throw std::runtime_error("Arguments do not match the provided set type!!");
        break;
    }
}

SetFactory::SetFactory(uint16_t type, const String* elements, uint16_t count)
{
    Set* sets[Set::MAX_ELEMENT_COUNT] = {nullptr};
    for (size_t i = 0; i < count; i++)
        sets[i] = ReadFromFile(elements[i].C_Str());
    
    switch (type)
    {
        case 3:
            set = new UnionSet(sets);
        break;

        case 4:
            set = new IntersectionSet(sets);
        break;

        default:
            throw std::runtime_error("Arguments do not match the provided set type!!");
        break;
    }
}

const Set* SetFactory::SetPtr() const
{
    return set;
}

void SetFactory::SaveToFile(const char* filename)
{
    set->SaveToFile(filename);
}

Set* SetFactory::ReadFromFile(const char* filename)
{
    if (file.is_open())
        file.close();
    file.open(filename, std::ios::in | std::ios::binary);
    uint16_t N = 0, T = 0;
    file.read((char*)&N, sizeof(N));
    if (N > Set::MAX_ELEMENT_COUNT)
    {
        file.close();
        throw std::runtime_error("The value of count in the file was too big!!!");
    }  
    file.read((char*)&T, sizeof(T));
    int32_t elements[Set::MAX_ELEMENT_COUNT] = { 0 };
    String filenames[Set::MAX_ELEMENT_COUNT] = { nullptr };
    Set* sets[Set::MAX_ELEMENT_COUNT] = { nullptr };

    switch (T)
    {
        case 0:
            file.read((char*)&elements, sizeof(int32_t) * N);
            return new BasicSet(elements, N);

        case 1:
        case 2:
            file.read((char*)&elements, sizeof(uint32_t) * N);
            return new SetByCriteria(std::move(SetCriteria(T == 2, elements, N)));
        break;

            for (size_t i = 0; i < N; i++)
                file >> filenames[i];
            
            for (uint16_t i = 0; i < N; i++)
                sets[i] = ReadFromFile(filenames[i].C_Str());
        case 3:    
            return new UnionSet(sets);

        case 4:
            return new IntersectionSet(sets);

        default:
            break;
    }
    return nullptr;
}

SetFactory::~SetFactory()
{
    delete set;
    set = nullptr;
}