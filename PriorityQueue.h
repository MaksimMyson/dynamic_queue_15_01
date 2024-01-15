#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

template <typename T>
class PriorityQueueElement {
private:
    T value;
    int priority;

public:
    PriorityQueueElement(T val, int pri) : value(val), priority(pri) {}

    T getValue() const {
        return value;
    }

    int getPriority() const {
        return priority;
    }
};

template <typename T>
class PriorityQueue {
private:
    static const int MAX_SIZE = 100;
    std::vector<PriorityQueueElement<T>> elements;

public:
    bool IsEmpty() const;
    bool IsFull() const;
    void InsertWithPriority(T value, int priority);
    T PullHighestPriorityElement();
    T Peek() const;
    void Show() const;
};

#include "PriorityQueue.cpp"  

#endif // PRIORITY_QUEUE_H