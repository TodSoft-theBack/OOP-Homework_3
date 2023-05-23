#include <iostream>
#include "PriorityQueue.hpp"

int main()
{
    std::cout << "Starting test..." << std::endl;
    PriorityQueue<char> pq(4);
    try
    {
        
        pq.Enqueue('A', 0);
        pq.Enqueue('B', 3);
        pq.Enqueue('C', 2);
        pq.Enqueue('D', 2);
        pq.Enqueue('E', 1);
        pq.Enqueue('F', 5);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        std::cout << "Peek: " << pq.Peek() << std::endl; // B
        pq.Dequeue();

        std::cout << "Peek: " << pq.Peek() << std::endl; // C
        pq.Dequeue();

        std::cout << "Peek: " << pq.Peek() << std::endl; // D
        pq.Dequeue();

        std::cout << "Peek: " << pq.Peek() << std::endl; // E
        pq.Dequeue();

        std::cout << "Peek: " << pq.Peek() << std::endl; // A
        pq.Dequeue();
        
        std::cout << "Peek: " << pq.Peek() << std::endl; // A
        pq.Dequeue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    std::cout << "Ending test..." << std::endl;
    return EXIT_SUCCESS;
}