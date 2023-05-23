#pragma once
#include <iostream>
#include "Vector.hpp"

template<typename T>
class Queue
{
    private:
        static const size_t DEFAULT_CAPACITY = 8;
        T* collection = nullptr;
        size_t count = 0;
        size_t capacity = DEFAULT_CAPACITY;

        unsigned pop = 0;
        unsigned push = 0;

        void CopyMemberData(const Queue<T>& queue);
        void MoveMemberData(Queue<T>&& queue);
        void FreeMemberData();
        void Resize();

    public:
        Queue();
        Queue(size_t capacity);
        Queue(const Queue<T>& queue);
        Queue(Queue<T>&& queue);

        const Queue<T>& operator=(const Queue<T>& queue);
        const Queue<T>& operator=(Queue<T>&& queue);

        size_t Count() const;
        void Enqueue(const T& item);
        void Enqueue(T&& item);
        const T& Peek() const;
        void Dequeue();
        bool IsEmpty() const;
        ~Queue();
};

template<typename T>
void Queue<T>::CopyMemberData(const Queue<T>& queue)
{
    this->capacity = queue.capacity;
    this->collection = new T[capacity];
    for (size_t i = 0; i < capacity; i++)
        collection[i] = queue.collection[i];   
    this->count = queue.count;
    this->pop = queue.pop;
    this->push = queue.push;
}

template<typename T>
void Queue<T>::MoveMemberData(Queue<T>&& queue)
{
    this->capacity = queue.capacity;
    this->collection = queue.collection;
    queue.collection = nullptr;
    this->count = queue.count;
    this->pop = queue.pop;
    this->push = queue.push;
}

template<typename T>
void Queue<T>::FreeMemberData()
{
    delete[] collection;
    collection = nullptr;
}

template<typename T>
void Queue<T>::Resize()
{
    capacity *= 2;
    T* newCollection = new T[capacity];
    for (size_t i = 0; i < count; i++, ++pop %= capacity)
        newCollection[i] = collection[pop];                
    delete[] collection;
    collection = newCollection;
    pop = 0;
    push = count;
}

template<typename T>
Queue<T>::Queue()
{
    collection = new T[capacity];
}

template<typename T>
Queue<T>::Queue(size_t capacity)
{
    this->capacity = capacity;
    collection = new T[capacity];
}

template<typename T>
Queue<T>::Queue(const Queue<T>& queue)
{
    CopyMemberData(queue);
}

template<typename T>
Queue<T>::Queue(Queue<T>&& queue)
{
    MoveMemberData(std::move(queue));
}

template<typename T>
const Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
    if (this != &queue)
    {
        FreeMemberData();
        CopyMemberData(queue);
    }
    return *this;
}

template<typename T>
const Queue<T>& Queue<T>::operator=(Queue<T>&& queue)
{
    if (this != &queue)
    {
        FreeMemberData();
        MoveMemberData(std::move(queue));
    }
    return *this;
}

template<typename T>
size_t Queue<T>::Count() const
{
    return count;
}

template<typename T>
void Queue<T>::Enqueue(const T& item)
{
    if (count == capacity)
        Resize();
    
    collection[push] = item;
    ++push %= capacity;
    count++;
}

template<typename T>
void Queue<T>::Enqueue(T&& item)
{
    if (count == capacity)
        Resize();
    collection[push] = std::move(item);
    ++push %= capacity;
    count++;
}

template<typename T>
const T& Queue<T>::Peek() const
{
    if (IsEmpty())
        throw std::runtime_error("The queue was empty!!!");
    
    return collection[pop];
}

template<typename T>
void Queue<T>::Dequeue()
{
    if (IsEmpty())
        throw std::runtime_error("The queue was empty!!!");

    ++pop %= capacity;
	count--;
}

template<typename T>
bool Queue<T>::IsEmpty() const
{
    return count == 0;
}

template<typename T>
Queue<T>::~Queue()
{
    FreeMemberData();
}