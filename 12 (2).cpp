// Q2.Write a C++ program to create a class which contains single dimensional integer array of
// given size. Define member function to display median of a given array. (Use Dynamic
// Constructor to allocate and Destructor to free memory of an object).
#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    Array(int sz) {
        size = sz;
        arr = new int[size];
    }

    ~Array() {
        delete[] arr;
    }

    void displayMedian() {
        sort(arr, arr + size);

        if (size % 2 == 0) {
            int mid = size / 2;
            cout << "Median of the array is: " << (arr[mid] + arr[mid - 1]) / 2.0 << endl;
        }
        else {
            int mid = size / 2;
            cout << "Median of the array is: " << arr[mid] << endl;
        }
    }

    void readArray() {
        cout << "Enter " << size << " elements of the array:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
};

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    Array a(n);

    a.readArray();
    a.displayMedian();

    return 0;
}
