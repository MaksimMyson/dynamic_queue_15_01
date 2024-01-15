#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> myPriorityQueue;

    std::cout << "Is Priority Queue Empty? " << (myPriorityQueue.IsEmpty() ? "Yes" : "No") << "\n";

    myPriorityQueue.InsertWithPriority(10, 2);
    myPriorityQueue.InsertWithPriority(20, 1);
    myPriorityQueue.InsertWithPriority(30, 3);

    std::cout << "Priority Queue elements:\n";
    myPriorityQueue.Show();

    std::cout << "Is Priority Queue Full? " << (myPriorityQueue.IsFull() ? "Yes" : "No") << "\n";

    int pulledElement = myPriorityQueue.PullHighestPriorityElement();
    std::cout << "Pulled element with highest priority: " << pulledElement << "\n";

    std::cout << "Peeked element with highest priority: " << myPriorityQueue.Peek() << "\n";

    std::cout << "Priority Queue elements after pulling:\n";
    myPriorityQueue.Show();

    return 0;
}