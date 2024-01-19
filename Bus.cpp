#include "Bus.h"
#include <iostream>

Bus::Bus(const std::string& name, int capacity) : name_(name), capacity_(capacity), passengers_on_board_(0) {}

std::string Bus::GetName() const {
    return name_;
}

int Bus::GetCapacity() const {
    return capacity_;
}

void Bus::LoadPassengers(int num_passengers) {
    if (num_passengers > capacity_ - passengers_on_board_) {
        num_passengers = capacity_ - passengers_on_board_;
    }

    passengers_on_board_ += num_passengers;
    std::cout << "Loaded " << num_passengers << " passengers onto the bus " << GetName() << std::endl;
}

void Bus::MoveToNextStop() {
    std::cout << "Moving bus " << GetName() << " to the next stop" << std::endl;
}

void Bus::UnloadPassengers() {
    std::cout << "Unloaded " << passengers_on_board_ << " passengers from the bus " << GetName() << std::endl;
    passengers_on_board_ = 0;
}
