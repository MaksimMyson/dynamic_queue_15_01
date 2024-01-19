#ifndef PRINTREQUEST_H
#define PRINTREQUEST_H

#include <string>
#include <ctime>

struct PrintRequest {
    std::string user;
    std::string priority;
    time_t timestamp;

    PrintRequest(const std::string& user, const std::string& priority);
    void Print() const;
};

#endif // PRINTREQUEST_H
