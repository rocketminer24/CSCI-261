/* CSCI 261 Lab 3B: Multiplication Tables
 *
 * Author: Jarod Spencer and Will McBride
 *
 * Description: Making multiplication tables using loops and user inputs
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    int integer1 = 0;
    int integer2 = 0;
    int x = 0;
    int y = 1;
    int i = 0;
    int multiple;
    bool gotInt1 = false;
    bool gotInt2 = false;

    cout << "\nLet's multiply!" << endl;

    cout << "Enter two integers greater than 1 and less than 11:" << endl;

    //Takes in valid integers
    while (!gotInt1 || !gotInt2) {
        int input = 0;
        cin >> input;
        if (input < 2 || input > 10) {
            continue;
        }
        if (gotInt1 == false) {
            integer1 = input;
            gotInt1 = true;
        } else {
            integer2 = input;
            gotInt2 = true;
        }
    }

    //Displays error message if appropriate. Asks user to re-input numbers to be multiplied.
    while ((integer1 <= 1 || integer1 >= 11) || (integer2 <= 1 || integer2 >= 11)) {
        cout << "Oops! It looks like one or both of the integers you have ";
        cout << "entered is not between 1 and 11.\nPlease try again.\n" << endl;
        cout << "Enter two integers greater than 1 and less than 11:" << endl;
        cin >> integer1;
        cin >> integer2;
    }

    //Prints first line of table.
    cout << endl << "..";
    for (i = 1; i <= integer2; ++i) {
        if (i < 10) {
            cout << "..." << i;
        } else {
            cout << ".." << i;
        }
    }
    cout << endl;

    //Prints all other lines of table.
    for (x = 1; x <= integer1; ++x) {
        if (x < 10) {
            cout << "." << y;
        } else {
            cout << y;
        }
        for (i = 1; i <= integer2; ++i) {
            multiple = x * i;
            if (multiple < 10) {
                cout << "..." << multiple;
            } else if (multiple >= 10 && multiple < 100) {
                cout << ".." << multiple;
            } else {
                cout << "." << multiple;
            }
        }
        cout << endl;
        ++y;
    }

    return 0;
}