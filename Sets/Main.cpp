#include<iostream>
#include "SetFactory.h"

int main()
{
    std::cout << "Starting set madness..." << std::endl;
    const char* buffer[3] = {"./BinaryFiles/first.bin", "./BinaryFiles/second.bin", "./BinaryFiles/third.bin"};
    SetFactory factory(4, buffer ,3);
    factory.SaveToFile("./BinaryFiles/set.bin");
    Set* ptr = factory.ReadFromFile("./BinaryFiles/set.bin");
    if (ptr == nullptr)
    {
        std::cout << "Closing set madness..." << std::endl;
        return EXIT_SUCCESS;
    }
    
    ptr->PrintInInterval(0, 10);
    ptr->PrintNext(10);
    std::cout << "Closing set madness..." << std::endl;
    return EXIT_SUCCESS;
}