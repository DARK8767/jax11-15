// or Q2. Create a class Fraction that contains two data members as numerator and denominator.
// Write a C++ program to overload following operators
// a. ++ Unary (pre and post both)
// b. << and >> Overload as friend functions//not understand
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, const Fraction& f);
    Fraction operator++();   // pre-increment
    Fraction operator++(int); // post-increment
};

istream& operator>>(istream& in, Fraction& f) {
    in >> f.numerator >> f.denominator;
    return in;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << '/' << f.denominator;
    return out;
}

Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

int main() {
    Fraction f1(3, 4), f2;
    cout << "Enter fraction (numerator/denominator): ";
    cin >> f2;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    ++f1;
    cout << "After pre-increment, f1 = " << f1 << endl;
    f2++;
    cout << "After post-increment, f2 = " << f2 << endl;
    return 0;
}
