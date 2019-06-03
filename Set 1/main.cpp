/* CSCI 261 Lab 1C: GEOMETRIC CALCULATIONS
 *
 * Author: Jarod Spencer
 *
 * Description: Using a computer to perform geometric calculations.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

    /******** MODIFY OR INSERT CODE BELOW HERE ********/

    //Begin volume of box calculation

    int length;
    int width;
    int height;
    int volume;

    cout << "If the dimensions of your prism are: ";
    cin >> length;
    cin >> width;
    cin >> height;

    // Volume of a box is length times width times height.

    volume = length * width * height;
    cout << "The volume of your box is " << volume << " cubic units." << endl;

    //End box calculation

    //Begin area of circle calculation

    const double PI = 3.14159265358979;
    double radius;
    double area;

    cout << "If the radius of your circle is ";
    cin >> radius;

    area = PI * radius * radius;

    cout << "then the area of your circle is " << area << " square units." << endl;


    /******** MODIFY OR INSERT CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}