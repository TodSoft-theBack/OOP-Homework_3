#pragma once
#include <iostream>
#include "Queue.hpp"
#include "Vector.hpp"

template<typename T>
class PriorityQueue
{
    private:
        unsigned _maxPriority;
        Vector<Queue<T>> queues;

    public:
        PriorityQueue(unsigned maxPriority);
        void Enqueue(const T& item, unsigned priority);
        void Enqueue(T&& item, unsigned priority);
        const T& Peek() const;
        void Dequeue();
        size_t Count() const;
        bool IsEmpty() const;
};

template<typename T>
PriorityQueue<T>::PriorityQueue(unsigned maxPriority)
{
    _maxPriority = maxPriority;
    queues = Vector<Queue<T>>(_maxPriority);
    for (unsigned i = 0; i < _maxPriority; i++)
        queues.PushBack(std::move(Queue<T>()));
}

template<typename T>
void PriorityQueue<T>::Enqueue(const T& item, unsigned priority)
{
    if (priority >= _maxPriority)
        throw std::runtime_error("Invalid priority!");

    queues[priority].Enqueue(item);
}

template<typename T>
void PriorityQueue<T>::Enqueue(T&& item, unsigned priority)
{
    if (priority >= _maxPriority)
        throw std::runtime_error("Invalid priority!");

    queues[priority].Enqueue(std::move(item));
}

template<typename T>
const T& PriorityQueue<T>::Peek() const
{
    try
    {
        for (int i = _maxPriority - 1; i >= 0; i--)
        if (!queues[i].IsEmpty())
            return queues[i].Peek();
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("The queue was empty!!!");
    }
    
    throw std::runtime_error("The queue was empty!!!");
}

template<typename T>
void PriorityQueue<T>::Dequeue()
{
    try
    {
        for (int i = _maxPriority - 1; i >= 0; i--)
        if (!queues[i].IsEmpty())
        {
            queues[i].Dequeue();
            return;
        }
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("The queue was empty!!!");
    }
    
    
    throw std::runtime_error("The queue was empty!!!");
}

template<typename T>
size_t PriorityQueue<T>::Count() const
{
    size_t count = 0;
    for (size_t i = 0; i < _maxPriority; i++)
        count += queues[i].Count();
    return count;
}

template<typename T>
bool PriorityQueue<T>::IsEmpty() const
{
    return Count() == 0;
}
