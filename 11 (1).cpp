// Q1.Write a C++ program to read two float numbers. Perform arithmetic binary operations +,-,*,/ on
// these numbers using inline function. Display the resultant value.
#include <iostream>
using namespace std;

inline float add(float a, float b) {
   return a + b;
}

inline float subtract(float a, float b) {
   return a - b;
}

inline float multiply(float a, float b) {
   return a * b;
}

inline float divide(float a, float b) {
   return a / b;
}

int main() {
   float num1, num2;

   cout << "Enter two float numbers: ";
   cin >> num1 >> num2;

   cout << "Addition: " << add(num1, num2) << endl;
   cout << "Subtraction: " << subtract(num1, num2) << endl;
   cout << "Multiplication: " << multiply(num1, num2) << endl;
   cout << "Division: " << divide(num1, num2) << endl;

   return 0;
}
