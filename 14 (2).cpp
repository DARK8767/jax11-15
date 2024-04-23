// Q2. Write a C++ program to define a class Bus with the following specifications: Bus No, Bus
// Name, No of Seats, Starting point, Destination .Write a menu driven program by using
// appropriate manipulators to
// a. Accept details of n buses.
// b. Display all bus details.
// c. Display details of bus from specified starting point to destination
#include <iostream>
#include <iomanip>1
#include <string>
using namespace std;

class Bus {
    int busNo, noOfSeats;
    string busName, startPoint, destination;
public:
    void acceptDetails();
    void displayDetails();
    bool matchesRoute(string start, string dest);
};

void Bus::acceptDetails() {
    cout << "Enter bus number: ";
    cin >> busNo;
    cout << "Enter bus name: ";
    cin >> busName;
    cout << "Enter number of seats: ";
    cin >> noOfSeats;
    cout << "Enter starting point: ";
    cin >> startPoint;
    cout << "Enter destination: ";
    cin >> destination;
}

void Bus::displayDetails() {
    cout << setw(8) << busNo << setw(20) << busName << setw(8) << noOfSeats << setw(15) << startPoint << setw(15) << destination << endl;
}

bool Bus::matchesRoute(string start, string dest) {
    return startPoint == start && destination == dest;
}

int main() {
    const int MAX_BUSES = 10;
    Bus buses[MAX_BUSES];
    int numBuses = 0;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a bus\n";
        cout << "2. Display all buses\n";
        cout << "3. Display buses from specified route\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (numBuses < MAX_BUSES) {
                    buses[numBuses].acceptDetails();
                    numBuses++;
                } else {
                    cout << "Cannot add more buses. Maximum limit reached.\n";
                }
                break;
            case '2':
                cout << setw(8) << "Bus No" << setw(20) << "Bus Name" << setw(8) << "Seats" << setw(15) << "Start Point" << setw(15) << "Destination" << endl;
                for (int i = 0; i < numBuses; i++) {
                    buses[i].displayDetails();
                }
                break;
            case '3': {
                string start, dest;
                bool found = false;
                cout << "Enter starting point: ";
                cin >> start;
                cout << "Enter destination: ";
                cin >> dest;
                cout << setw(8) << "Bus No" << setw(20) << "Bus Name" << setw(8) << "Seats" << setw(15) << "Start Point" << setw(15) << "Destination" << endl;
                for (int i = 0; i < numBuses; i++) {
                    if (buses[i].matchesRoute(start, dest)) {
                        buses[i].displayDetails();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No buses found for specified route.\n";
                }
                break;
            }
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
