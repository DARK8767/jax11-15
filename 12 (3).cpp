// or Q2. Implement the following class hierarchy:
// Employee: code, ename, desg
// Manager (derived from Employee): year_of_experience, salary
// Define appropriate functions to accept and display details.
// Create n objects of the manager class and display the records.
// Write main function that uses the above class and its member functions.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
protected:
    int code;
    string ename;
    string desg;
public:
    void accept_details() {
        cout << "Enter employee code: ";
        cin >> code;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, ename);
        cout << "Enter employee designation: ";
        getline(cin, desg);
    }
    void display_details() {
        cout << "Employee Code: " << code << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Employee Designation: " << desg << endl;
    }
};

class Manager : public Employee {
    int year_of_experience;
    float salary;
public:
    void accept_details() {
        Employee::accept_details();
        cout << "Enter years of experience: ";
        cin >> year_of_experience;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void display_details() {
        Employee::display_details();
        cout << "Years of Experience: " << year_of_experience << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of managers: ";
    cin >> n;
    vector<Manager> managers(n);
    for(int i=0; i<n; i++) {
        cout << "Enter details for manager " << i+1 << ":" << endl;
        managers[i].accept_details();
    }
    cout << "\nManager Records:\n" << endl;
    for(int i=0; i<n; i++) {
        cout << "Details of manager " << i+1 << ":" << endl;
        managers[i].display_details();
        cout << endl;
    }
    return 0;
}
