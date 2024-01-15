#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node(const T& value, int priority) : data(value), priority(priority), next(nullptr) {}
    };

    static const int MAX_SIZE = 100;
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() {
        while (!IsEmpty()) {
            PullHighestPriorityElement();
        }
    }

    bool IsEmpty() const {
        return front == nullptr;
    }

    bool IsFull() const {
        // Assuming a fixed size for simplicity
        return false;
    }

    void InsertWithPriority(const T& value, int priority) {
        Node* newNode = new Node(value, priority);

        if (IsEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* current = front;

            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void PullHighestPriorityElement() {
        if (IsEmpty()) {
            std::cout << "PriorityQueue is empty. Cannot pull highest priority element.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    T Peek() const {
        if (IsEmpty()) {
            std::cout << "PriorityQueue is empty. Cannot peek.\n";
            exit(1); // Handle this case according to your needs
        }

        return front->data;
    }
};

#endif // PRIORITY_QUEUE_H