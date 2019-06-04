/* CSCI 261 Lab 4B: Polar to Cartesian Converter
 *
 * Author: Jarod Spencer
 *
 * Description: Writing a program that calls polar to cartesian and cartesian
 *               to polar conversion functions.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

//Functions declared, will be defined later
void polarToCartesian (double r, double theta, double &x, double &y);
void cartesianToPolar (double x, double y, double &r, double &theta);

int main() {

    string choice;
    double r = 0;
    double theta = 0;
    double x = 0;
    double y = 0;

    //Asks user to choose to convert from cartesian to polar or from polar to cartesian
    cout << "Do you want to convert from cartesian to polar or from polar to cartesian?" << endl;
    cout << "(Type p2c or c2p): ";
    cin >> choice;

    //Runs if user did not choose either p2c or c2p
    while (choice != "p2c" && choice != "c2p")  {
        cout << "Invalid choice. Please try again." << endl;
        cout << "(Type p2c or c2p): ";
        cin >> choice;
    }

    //calls appropriate function based on user input
    if (choice == "p2c") {
        cout << "Enter polar coordinates: ";
        cin >> r;
        cin >> theta;
        cout << endl;
        polarToCartesian(r, theta, x, y);
        cout << "Your coordinates in cartesian are (" << x << ", " << y << ")";
    } else {
        cout << "Enter cartesian coordinates: ";
        cin >> x;
        cin >> y;
        cout << endl;
        cartesianToPolar(x, y, r, theta);
        cout << "Your coordinates in polar are (" << r << ", " << theta << ")";
    }


    return 0;
}

//Functions defined
void polarToCartesian (double r, double theta, double &x, double &y) {
    x = r * cos(theta);
    y = r * sin(theta);
}

void cartesianToPolar (double x, double y, double &r, double &theta) {
    r = sqrt(pow(x, 2) + pow(y, 2));
    theta = atan(y / x);
}
