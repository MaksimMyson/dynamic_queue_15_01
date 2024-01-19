#ifndef STOP_H
#define STOP_H

#include <string>

class Stop {
public:
    Stop(const std::string& name, double passenger_arrival_rate_day, double passenger_arrival_rate_night, bool is_terminal);

    std::string GetName() const;
    double GetPassengerArrivalRate() const;
    bool IsTerminal() const;

    
    double GetBusArrivalTime() const;
    bool HasPassengers() const;

private:
    std::string name_;
    double passenger_arrival_rate_day_;
    double passenger_arrival_rate_night_;
    bool is_terminal_;
};

#endif // STOP_H
