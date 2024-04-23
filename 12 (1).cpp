// Q1.Write a C++ program to accept length and width of a rectangle. Calculate and display perimeter
// as well as area of a rectangle by using inline function.
#include <iostream>
using namespace std;

inline void calculate(double length, double width, double& area, double& perimeter)
{
    area = length * width;
    perimeter = 2 * (length + width);
}

int main()
{
    double length, width, area, perimeter;
    
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    
    calculate(length, width, area, perimeter);
    
    cout << "Area of the rectangle is: " << area << endl;
    cout << "Perimeter of the rectangle is: " << perimeter << endl;
    
    return 0;
}
