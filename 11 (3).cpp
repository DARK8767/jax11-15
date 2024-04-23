// or Q2. Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram),
// Volume (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program
// to perform read, convert and display operations. (Use Pure virtual function)//not understand
#include <iostream>
#include <string>
using namespace std;

class Conversion {
   public:
      virtual void read() = 0;
      virtual void convert() = 0;
      virtual void display() = 0;
};

class Weight : public Conversion {
   private:
      float value;
      string unit;

   public:
      void read() {
         cout << "Enter value: ";
         cin >> value;

         cout << "Enter unit (g or kg): ";
         cin >> unit;
      }

      void convert() {
         if (unit == "g") {
            value /= 1000;
            unit = "kg";
         }
      }

      void display() {
         cout << value << " " << unit << endl;
      }
};

class Volume : public Conversion {
   private:
      float value;
      string unit;

   public:
      void read() {
         cout << "Enter value: ";
         cin >> value;

         cout << "Enter unit (ml or l): ";
         cin >> unit;
      }

      void convert() {
         if (unit == "ml") {
            value /= 1000;
            unit = "l";
         }
      }

      void display() {
         cout << value << " " << unit << endl;
      }
};

class Currency : public Conversion {
   private:
      float value;
      string unit;

   public:
      void read() {
         cout << "Enter value: ";
         cin >> value;

         cout << "Enter unit (Rs or paise): ";
         cin >> unit;
      }

      void convert() {
         if (unit == "paise") {
            value /= 100;
            unit = "Rs";
         }
      }

      void display() {
         cout << value << " " << unit << endl;
      }
};

int main() {
   Conversion* conversions[3];
   conversions[0] = new Weight();
   conversions[1] = new Volume();
   conversions[2] = new Currency();

   for (int i = 0; i < 3; i++) {
      conversions[i]->read();
      conversions[i]->convert();
      conversions[i]->display();
      cout << endl;
   }

   return 0;
}
