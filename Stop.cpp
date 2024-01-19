#include "Stop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Stop::Stop(const std::string& name, double passenger_arrival_rate_day, double passenger_arrival_rate_night, bool is_terminal)
    : name_(name), passenger_arrival_rate_day_(passenger_arrival_rate_day), passenger_arrival_rate_night_(passenger_arrival_rate_night), is_terminal_(is_terminal) {}

std::string Stop::GetName() const {
    return name_;
}

double Stop::GetPassengerArrivalRate() const {
    return is_terminal_ ? passenger_arrival_rate_night_ : passenger_arrival_rate_day_;
}

bool Stop::IsTerminal() const {
    return is_terminal_;
}

double Stop::GetBusArrivalTime() const {
    return (rand() % 10) + 1; 
}

bool Stop::HasPassengers() const {
    return rand() % 2 == 1; 
}
