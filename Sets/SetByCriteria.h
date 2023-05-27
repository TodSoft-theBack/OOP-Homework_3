#pragma once
#include "Set.h"
#include "Vector.hpp"


class SetCriteria
{
    Vector<int32_t> _elements;
    bool (*predicate)(int) = nullptr;

    public:
        SetCriteria(bool (*predicate)(int))
        {
            this->predicate = predicate;
        }

        SetCriteria(bool type, const int32_t* elements, size_t count)
        {
            _elements = std::move(Vector<int32_t>(elements, count));
        }

        bool operator()(int32_t element) const
        {
            return predicate(element);
        }
};


class SetByCriteria : public Set
{
    private:
        SetCriteria criteria = nullptr;
        static const uint16_t TYPES[2];
    public:
        SetByCriteria(const SetCriteria& criteria);
        bool Contains(int32_t element) const override;
        void PrintInInterval(int a, int b) const override;
        void PrintNext(unsigned current) const override;
        void SaveToFile(const char* filename) const override;
        ~SetByCriteria() = default;
};