/* CSCI 261 Assignment 1: Hello World and ASCII Art
 *
 * Author: Jarod Spencer
 *
 * Using cout statements and variables to make art and informative personal facts.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants or global variables below this comment.

    int age = 19;
    double swimTime = 1.019;
    int year = 2027;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

    /******** INSERT YOUR CODE BELOW HERE ********/

//Here's a smiley face!
    cout << " " << endl;
    cout << "              00000000              " << endl;
    cout << "           00000000000000           " << endl;
    cout << "         00000  0000  00000         " << endl;
    cout << "        00000    00    00000        " << endl;
    cout << "       000000    00    000000       " << endl;
    cout << "       0000000  0000  0000000       " << endl;
    cout << "       0000000000000000000000       " << endl;
    cout << "        000   00000000   000        " << endl;
    cout << "         000    0000    000         " << endl;
    cout << "          0000        0000          " << endl;
    cout << "            000000000000            " << endl;
    cout << "              00000000              " << endl;
    cout << " " << endl;

//Personal Facts
    cout << "Three facts about me are" << endl;
    cout << " 1) I will be " << age << " years old in 2 weeks," << endl;
    cout << " 2) I swam a 100m butterfly race in " << swimTime << " minutes," << endl;
    cout << " 3) I believe that SpaceX will land on Mars in " << year << "." << endl;

    /******** INSERT YOUR CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}