// Q2.Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram), Volume
// (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program to perform
// read, convert and display operations. (Use Pure virtual function)//not understand
#include <iostream>
using namespace std;

// Base class
class Conversion {
public:
    virtual void read() = 0; // Pure virtual function
    virtual void convert() = 0; // Pure virtual function
    virtual void display() = 0; // Pure virtual function
};

// Derived class for weight conversion
class Weight : public Conversion {
private:
    double value;
    string unit;
public:
    void read() {
        cout << "Enter the weight value: ";
        cin >> value;
        cout << "Enter the unit (g or kg): ";
        cin >> unit;
    }
    void convert() {
        if (unit == "g") {
            value /= 1000; // convert grams to kilograms
            unit = "kg";
        }
    }
    void display() {
        cout << "Weight: " << value << " " << unit << endl;
    }
};

// Derived class for volume conversion
class Volume : public Conversion {
private:
    double value;
    string unit;
public:
    void read() {
        cout << "Enter the volume value: ";
        cin >> value;
        cout << "Enter the unit (ml or l): ";
        cin >> unit;
    }
    void convert() {
        if (unit == "ml") {
            value /= 1000; // convert milliliters to liters
            unit = "l";
        }
    }
    void display() {
        cout << "Volume: " << value << " " << unit << endl;
    }
};

// Derived class for currency conversion
class Currency : public Conversion {
private:
    double value;
    string unit;
public:
    void read() {
        cout << "Enter the currency value: ";
        cin >> value;
        cout << "Enter the unit (Rs or paise): ";
        cin >> unit;
    }
    void convert() {
        if (unit == "paise") {
            value /= 100; // convert paise to rupees
            unit = "Rs";
        }
    }
    void display() {
        cout << "Currency: " << value << " " << unit << endl;
    }
};

int main() {
    // Declare an array of pointers to Conversion objects
    const int NUM_CONVERSIONS = 3;
    Conversion* conversions[NUM_CONVERSIONS] = {nullptr};
    
    // Populate the array with objects of the derived classes
    conversions[0] = new Weight;
    conversions[1] = new Volume;
    conversions[2] = new Currency;
    
    // Call read(), convert(), and display() for each object in the array
    for (int i = 0; i < NUM_CONVERSIONS; i++) {
        conversions[i]->read();
        conversions[i]->convert();
        conversions[i]->display();
        cout << endl;
    }
    
    // Free memory allocated for objects in the array
    for (int i = 0; i < NUM_CONVERSIONS; i++) {
        delete conversions[i];
        conversions[i] = nullptr;
    }
    
    return 0;
}
