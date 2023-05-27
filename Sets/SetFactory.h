#pragma once
#include <iostream>
#include <fstream>
#include "String.h"
#include "Set.h"
#include "BasicSet.h"
#include "SetByCriteria.h"
#include "IntersectionSet.h"
#include "UnionSet.h"

class SetFactory
{
    private:
        Set* set = nullptr;
        std::fstream file;

    public:
        SetFactory(const char* filename);
        SetFactory(uint16_t type, const int32_t* elements, uint16_t count);
        SetFactory(uint16_t type, const String* elements, uint16_t count);
        void SaveToFile(const char* filename);
        Set* ReadFromFile(const char* filename);

        ~SetFactory();
};
