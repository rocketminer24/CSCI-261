/* CSCI 261 Lab 2A: Math Equations
*
* Author: Jordan Turnquest and Jarod Spencer
*/

#include <iostream>

using namespace std;

int main() {

   double P;
   double T;
   const double R = .082057;
   double V;
   double n;
   double v;
   double I;
   double r;

   cout << "Enter volume: ";
   cin >> V;
   cout << "Enter temperature in Kelvins: ";
   cin >> T;
   cout << "Enter moles: ";
   cin >> n;
   cout << "Enter amps: ";
   cin >> I;
   cout << "Enter resistance: ";
   cin >> r;


   P = (n * R * T) / V;
   cout << "The pressure is: " << P << endl;
   v = I * r;
   cout << "The voltage is: " << v;


   return 0;
}
