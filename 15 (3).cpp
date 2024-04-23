// or Q2. Write C++ program to create a class Employee containing data members Emp_no, Emp_Name,
// Designation and Salary. Create and initialize the objects using default, parameterized and Copy
// Constructor. Also write member function to calculate Income tax of the employee which is 20%
// of salary.
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int Emp_no;
    string Emp_Name;
    string Designation;
    double Salary;

public:
    // Default Constructor
    Employee() {
        Emp_no = 0;
        Emp_Name = "";
        Designation = "";
        Salary = 0;
    }

    // Parameterized Constructor
    Employee(int empNo, string empName, string designation, double salary) {
        Emp_no = empNo;
        Emp_Name = empName;
        Designation = designation;
        Salary = salary;
    }

    // Copy Constructor
    Employee(const Employee& e) {
        Emp_no = e.Emp_no;
        Emp_Name = e.Emp_Name;
        Designation = e.Designation;
        Salary = e.Salary;
    }

    // Member function to calculate Income tax
    double calculateIncomeTax() {
        return 0.2 * Salary;
    }

    // Member function to display Employee details
    void displayEmployee() {
        cout << "Employee No: " << Emp_no << endl;
        cout << "Employee Name: " << Emp_Name << endl;
        cout << "Designation: " << Designation << endl;
        cout << "Salary: " << Salary << endl;
    }
};

int main() {
    // Initializing objects using different constructors
    Employee e1;
    Employee e2(101, "John Doe", "Manager", 50000);
    Employee e3 = e2;

    // Displaying Employee details
    cout << "Employee 1 details:" << endl;
    e1.displayEmployee();
    cout << endl;

    cout << "Employee 2 details:" << endl;
    e2.displayEmployee();
    cout << "Income Tax: " << e2.calculateIncomeTax() << endl << endl;

    cout << "Employee 3 details:" << endl;
    e3.displayEmployee();
    cout << "Income Tax: " << e3.calculateIncomeTax() << endl << endl;

    return 0;
}
