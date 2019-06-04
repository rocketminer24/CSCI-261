/* CSCI 261 Lab 2B: Math Equations
*
* Author: Jordan Turnquest and Jarod Spencer
*/

#include <iostream>
#include <iomanip>

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

    cout << "\nEnter volume: ";
    cin >> V;
    cout << "Enter temperature in Kelvins: ";
    cin >> T;
    cout << "Enter moles: ";
    cin >> n;
    cout << endl;

    cout << "Enter amps: ";
    cin >> I;
    cout << "Enter resistance: ";
    cin >> r;
    cout << endl;

    P = (n * R * T) / V;
    cout << setfill('.');
    cout << setprecision(3);
    cout << "Equation #01" << setw(41) << right << "Ideal Gas Law (Chemistry):  " << P << endl;

    v = I * r;
    cout << setprecision(5);
    cout << "Equation #03" << setw(40) << right << "Voltage (Physics)  : " << v << endl;


    return 0;
}
