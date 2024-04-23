// Q2.Write a C++ program to create a class Person that contains data members as Person_Name, City,
// Mob_No. Write a C++ program to perform following functions:
// a. To accept and display Person information
// b. To search the Person details of a given mobile number
// c. To search the Person details of a given city.
// (Use Function Overloading)
#include <iostream>
#include <string>
using namespace std;

class Person {
   private:
      string Person_Name;
      string City;
      string Mob_No;
   
   public:
      void accept() {
         cout << "Enter Person Name: ";
         getline(cin, Person_Name);

         cout << "Enter City: ";
         getline(cin, City);

         cout << "Enter Mobile Number: ";
         getline(cin, Mob_No);
      }

      void display() {
         cout << "Person Name: " << Person_Name << endl;
         cout << "City: " << City << endl;
         cout << "Mobile Number: " << Mob_No << endl;
      }

      bool search(string search_param) {
         if (search_param == Mob_No || search_param == City) {
            display();
            return true;
         }

         return false;
      }
};

int main() {
   Person persons[3];

   for (int i = 0; i < 3; i++) {
      cout << "Enter details of Person " << i + 1 << ":" << endl;
      persons[i].accept();
      cout << endl;
   }

   string search_param;
   cout << "Enter Mobile Number or City to search: ";
   getline(cin, search_param);

   bool found = false;

   for (int i = 0; i < 3; i++) {
      if (persons[i].search(search_param)) {
         found = true;
      }
   }

   if (!found) {
      cout << "No Person found with the given Mobile Number or City." << endl;
   }

   return 0;
}
