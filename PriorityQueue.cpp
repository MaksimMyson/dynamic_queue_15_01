#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP

#include "PriorityQueue.h"
#include <algorithm>
#include <iostream>

// ????????? ?????? ????? PriorityQueue

template <typename T>
bool PriorityQueue<T>::IsEmpty() const {
    return elements.empty();
}

template <typename T>
bool PriorityQueue<T>::IsFull() const {
    return elements.size() == MAX_SIZE;
}

template <typename T>
void PriorityQueue<T>::InsertWithPriority(T value, int priority) {
    if (IsFull()) {
        std::cout << "Priority Queue is full. Cannot insert with priority.\n";
        return;
    }

    elements.emplace_back(value, priority);
}

template <typename T>
T PriorityQueue<T>::PullHighestPriorityElement() {
    if (IsEmpty()) {
        std::cerr << "Priority Queue is empty. Cannot pull highest priority element.\n";
        throw std::out_of_range("Priority Queue is empty");
    }

    auto highestPriority = std::max_element(elements.begin(), elements.end(),
        [](const auto& a, const auto& b) { return a.getPriority() < b.getPriority(); });

    T value = highestPriority->getValue();
    elements.erase(highestPriority);

    return value;
}

template <typename T>
T PriorityQueue<T>::Peek() const {
    if (IsEmpty()) {
        std::cerr << "Priority Queue is empty. Cannot peek.\n";
        throw std::out_of_range("Priority Queue is empty");
    }

    auto highestPriority = std::max_element(elements.begin(), elements.end(),
        [](const auto& a, const auto& b) { return a.getPriority() < b.getPriority(); });

    return highestPriority->getValue();
}

template <typename T>
void PriorityQueue<T>::Show() const {
    if (IsEmpty()) {
        std::cout << "Priority Queue is empty.\n";
        return;
    }

    std::cout << "Priority Queue elements:\n";
    for (const auto& element : elements) {
        std::cout << "Value: " << element.getValue() << ", Priority: " << element.getPriority() << "\n";
    }
}

#endif // PRIORITY_QUEUE_CPP