#include "SetCriteria.h"
#include "SetByCriteria.h"

SetCriteria::SetCriteria(bool type, const int32_t* elements, uint16_t count)
{
    _elements = std::move(Vector<int32_t>(elements, count));
    _type = type;
    predicate = type ? &SetCriteria::HasNoFactorsFromElements : &SetCriteria::HasExactlyOneFactorFromElements;
}


bool SetCriteria::HasExactlyOneFactorFromElements(int32_t element) const
{
    size_t counter = 0, count = _elements.Count();
    for (size_t i = 0; i < count; i++)
    {
        if (element % _elements[i] == 0)
            counter++;
        if (counter > 1)
            return false;
    }
    return true;
}

bool SetCriteria::HasNoFactorsFromElements(int32_t element) const
{
    size_t count = _elements.Count();
    for (size_t i = 0; i < count; i++)
        if (element % _elements[i] == 0)
            return false;
    return true;
}

void SetCriteria::SaveToStream(std::ofstream& stream) const
{
    uint16_t N = _elements.Count(), T = SetByCriteria::TYPES[_type];
    stream.write((const char*)&N, sizeof(N));
    stream.write((const char*)&T, sizeof(T));
    stream.write((const char*)_elements.Collection(), sizeof(int32_t) * N);
}

bool SetCriteria::operator()(int32_t element) const
{
    return (this->*predicate)(element);
}