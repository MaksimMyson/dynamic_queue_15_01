#include "PrintRequest.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>

PrintRequest::PrintRequest(const std::string& user, const std::string& priority) : user(user), priority(priority), timestamp(time(nullptr)) {
    std::transform(this->priority.begin(), this->priority.end(), this->priority.begin(), ::tolower);

    if (this->priority != "low" && this->priority != "medium" && this->priority != "high") {
        std::cerr << "Invalid priority. Use 'low', 'medium', or 'high'." << std::endl;
    }
}

void PrintRequest::Print() const {
    char buffer[80];
    struct tm timeinfo;

#ifdef _WIN32
    localtime_s(&timeinfo, &timestamp);
#else
    localtime_r(&timestamp, &timeinfo);
#endif

    strftime(buffer, sizeof(buffer), "%F %T", &timeinfo);

    std::cout << "User: " << user << " | Priority: " << priority << " | Time: " << buffer << std::endl;
}
