#pragma once
#include <iostream>

template<typename T>
class PriorityQueue
{
    private:
        unsigned _maxPriority;
        T** collection;

        void Initilize()
        {
            collection = new T*[_maxPriority];
            for (size_t i = 0; i < _maxPriority; i++)
                collection[i] = nullptr; 
        }

        void Free()
        {
            for (size_t i = 0; i < _maxPriority; i++)
                delete[] collection[i];
            delete[] collection;
            collection = nullptr;
        }

    public:
        PriorityQueue(unsigned maxPriority)
        {
            _maxPriority = maxPriority;
            Initilize();
        }

        void Push(const T& item, unsigned priority)
        {
            if (priority > _maxPriority)
                throw 0;
            if (collection[priority] == nullptr)
            {
                /* code */
            }
            
            
        }

        const T& Peek() const
        {

        }

        void Pop()
        {

        }

        ~PriorityQueue()
        {
            Free();
        }
};
