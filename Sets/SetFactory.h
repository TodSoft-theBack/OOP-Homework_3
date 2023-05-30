#pragma once
#include <iostream>
#include <fstream>
#include "Set.h"
#include "BasicSet.h"
#include "SetByCriteria.h"
#include "SetCriteria.h"
#include "IntersectionSet.h"
#include "UnionSet.h"
#include "String.h"

class SetFactory
{
    private:
        Set* set = nullptr;
        std::fstream file;

    public:
        SetFactory(const char* filename);
        SetFactory(uint16_t type, const int32_t* elements, uint16_t count);
        SetFactory(uint16_t type, const char* elements[], uint16_t count);
        const Set* SetPtr() const;
        void SaveToFile(const char* filename);
        Set* ReadFromFile(const char* filename);

        ~SetFactory();
};
