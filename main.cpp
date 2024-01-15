#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> myQueue;

    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);

    myQueue.Show();  // Output: 1 2 3

    myQueue.Dequeue();

    myQueue.Show();  // Output: 2 3

    cout << "Is Queue empty? " << (myQueue.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Is Queue full? " << (myQueue.IsFull() ? "Yes" : "No") << endl;

    return 0;
}