#ifndef BUS_H
#define BUS_H

#include <string>

class Bus {
public:
    Bus(const std::string& name, int capacity);

    std::string GetName() const;
    int GetCapacity() const;

    
    void LoadPassengers(int num_passengers);
    void MoveToNextStop();
    void UnloadPassengers();

private:
    std::string name_;
    int capacity_;
    int passengers_on_board_;
};

#endif // BUS_H
