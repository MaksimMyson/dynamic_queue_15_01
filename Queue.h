#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 100;
    T elements[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool IsEmpty() const {
        return front == -1 && rear == -1;
    }

    bool IsFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    void Enqueue(const T& value) {
        if (IsFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (IsEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void Show() const {
        if (IsEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int current = front;
        while (current != rear) {
            std::cout << elements[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        std::cout << elements[rear] << "\n";
    }
};

#endif // QUEUE_H