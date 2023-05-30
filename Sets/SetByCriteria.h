#pragma once
#include <fstream>
#include "Set.h"
#include "SetCriteria.h"


class SetByCriteria : public Set
{
        SetCriteria _criteria;

    public:
        static const uint16_t TYPES[2];
        SetByCriteria(const SetCriteria& criteria);
        bool Contains(int32_t element) const override;
        void SaveToFile(const char* filename) const override;
        ~SetByCriteria() = default;
};