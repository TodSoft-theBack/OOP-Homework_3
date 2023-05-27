#include<iostream>
#include "SetCriteria.h"
#include "String.h"
#include "SetFactory.h"

int main()
{
    String file = std::move("Meme.dat");
    const char* filename = file.C_Str();
    std::cout << "Starting set madness..." << std::endl;
    const String buffer[3] = {"first.bin", "second.bin", "third.bin"};
    SetFactory factory(4, buffer ,3);
    factory.SaveToFile("./BinaryFiles/set.bin");
    Set* ptr = factory.ReadFromFile("./BinaryFiles/set.bin");
    ptr->PrintInInterval(0, 10);
    std::cout << "Closing set madness..." << std::endl;
    return EXIT_SUCCESS;
}