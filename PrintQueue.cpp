#include "PrintQueue.h"
#include <iostream>
#include <iomanip>

void PrintQueue::AddPrintRequest(const PrintRequest& request) {
    printQueue.push(request);
}

void PrintQueue::PrintStatistics() {
    std::cout << "\nPrint Statistics:\n";
    while (!printQueue.empty()) {
        const PrintRequest& request = printQueue.front();
        request.Print();
        printQueue.pop();
    }
}
