// Q2.Write a C++ program to create a class Distance which contains data members as kilometer, meter.
// Write a program to perform the following functions
// a.To accept distance
// b.To display distance
// c.To overload > operator to compare two distance
#include <iostream>
using namespace std;

class Distance {
private:
    int kilometer;
    int meter;
public:
    Distance() {
        kilometer = 0;
        meter = 0;
    }
    void accept_distance() {
        cout << "Enter distance in kilometers: ";
        cin >> kilometer;
        cout << "Enter distance in meters: ";
        cin >> meter;
        normalize_distance();
    }
    void display_distance() {
        cout << "Distance: " << kilometer << " km " << meter << " m" << endl;
    }
    bool operator>(Distance d2) {
        int total_meter1 = kilometer * 1000 + meter;
        int total_meter2 = d2.kilometer * 1000 + d2.meter;
        return total_meter1 > total_meter2;
    }
private:
    void normalize_distance() {
        if(meter >= 1000) {
            int extra_kilometer = meter / 1000;
            meter %= 1000;
            kilometer += extra_kilometer;
        }
    }
};

int main() {
    Distance d1, d2;
    cout << "Enter distance 1:" << endl;
    d1.accept_distance();
    cout << "Enter distance 2:" << endl;
    d2.accept_distance();
    cout << endl;
    cout << "Distance 1:" << endl;
    d1.display_distance();
    cout << "Distance 2:" << endl;
    d2.display_distance();
    cout << endl;
    if(d1 > d2) {
        cout << "Distance 1 is greater than distance 2" << endl;
    } else {
        cout << "Distance 2 is greater than distance 1" << endl;
    }
    return 0;
}
