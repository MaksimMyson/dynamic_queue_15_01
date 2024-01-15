#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> myPriorityQueue;

    myPriorityQueue.InsertWithPriority(3, 1);
    myPriorityQueue.InsertWithPriority(5, 2);
    myPriorityQueue.InsertWithPriority(1, 3);

    std::cout << "Peek: " << myPriorityQueue.Peek() << std::endl;

    myPriorityQueue.PullHighestPriorityElement();

    std::cout << "Peek after pulling highest priority element: " << myPriorityQueue.Peek() << std::endl;

    std::cout << "Is PriorityQueue empty? " << (myPriorityQueue.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is PriorityQueue full? " << (myPriorityQueue.IsFull() ? "Yes" : "No") << std::endl;

    return 0;
}