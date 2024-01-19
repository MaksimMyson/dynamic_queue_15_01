#include "Stop.h"
#include "Bus.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // User input for stops and buses
    cout << "Enter details for Stop A:" << endl;
    string stopA_name;
    double stopA_arrival_rate_day, stopA_arrival_rate_night;
    cout << "Name: ";
    cin >> stopA_name;
    cout << "Daytime passenger arrival rate: ";
    cin >> stopA_arrival_rate_day;
    cout << "Nighttime passenger arrival rate: ";
    cin >> stopA_arrival_rate_night;
    Stop stopA(stopA_name, stopA_arrival_rate_day, stopA_arrival_rate_night, false);

    cout << "\nEnter details for Stop B:" << endl;
    string stopB_name;
    double stopB_arrival_rate_day, stopB_arrival_rate_night;
    cout << "Name: ";
    cin >> stopB_name;
    cout << "Daytime passenger arrival rate: ";
    cin >> stopB_arrival_rate_day;
    cout << "Nighttime passenger arrival rate: ";
    cin >> stopB_arrival_rate_night;
    Stop stopB(stopB_name, stopB_arrival_rate_day, stopB_arrival_rate_night, false);

    cout << "\nEnter details for Terminal Stop:" << endl;
    string terminalStop_name;
    double terminalStop_arrival_rate_day, terminalStop_arrival_rate_night;
    cout << "Name: ";
    cin >> terminalStop_name;
    cout << "Daytime passenger arrival rate: ";
    cin >> terminalStop_arrival_rate_day;
    cout << "Nighttime passenger arrival rate: ";
    cin >> terminalStop_arrival_rate_night;
    Stop terminalStop(terminalStop_name, terminalStop_arrival_rate_day, terminalStop_arrival_rate_night, true);

    cout << "\nEnter details for Bus 1:" << endl;
    string bus1_name;
    int bus1_capacity;
    cout << "Name: ";
    cin >> bus1_name;
    cout << "Capacity: ";
    cin >> bus1_capacity;
    Bus bus1(bus1_name, bus1_capacity);

    cout << "\nEnter details for Bus 2:" << endl;
    string bus2_name;
    int bus2_capacity;
    cout << "Name: ";
    cin >> bus2_name;
    cout << "Capacity: ";
    cin >> bus2_capacity;
    Bus bus2(bus2_name, bus2_capacity);

    // Simulating stops and buses
    for (int i = 0; i < 10; ++i) {
        // Passengers arrive at the stop
        if (stopA.HasPassengers()) {
            int num_passengers = rand() % 5 + 1; 
            bus1.LoadPassengers(num_passengers);
        }

        if (stopB.HasPassengers()) {
            int num_passengers = rand() % 5 + 1; 
            bus2.LoadPassengers(num_passengers);
        }

        // Bus arrives
        bus1.MoveToNextStop();
        bus2.MoveToNextStop();

        // Bus moves to the next stop
        bus1.MoveToNextStop();
        bus2.MoveToNextStop();

        
        bus1.UnloadPassengers();
        bus2.UnloadPassengers();

        this_thread::sleep_for(chrono::seconds(2)); 
    }

    return 0;
}
 