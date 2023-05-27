#include<iostream>
#include "String.h"
#include "SetFactory.h"

int main()
{
    String file = std::move("Meme.dat");
    const char* filename = file.C_Str();
    std::cout << "Starting set madness..." << std::endl;
    //const String buffer[3] = {"first.bin", "second.bin", "third.bin"};
    //SetFactory factory(4, buffer ,3);
    int32_t	elements[Set::MAX_ELEMENT_COUNT] = {1, 3, 4, 6, 2, 8, 9};
    SetFactory factory(0, elements, 7);
    factory.SaveToFile("./BinaryFiles/set.bin");
    auto meme = factory.ReadFromFile("./BinaryFiles/set.bin");
    meme->PrintInInterval(0, 10);
    std::cout << "Closing set madness..." << std::endl;
    return EXIT_SUCCESS;
}