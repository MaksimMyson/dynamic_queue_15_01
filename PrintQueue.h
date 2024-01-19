#ifndef PRINTQUEUE_H
#define PRINTQUEUE_H

#include "PrintRequest.h"
#include <queue>

class PrintQueue {
public:
    void AddPrintRequest(const PrintRequest& request);
    void PrintStatistics();

private:
    std::queue<PrintRequest> printQueue;
};

#endif // PRINTQUEUE_H
