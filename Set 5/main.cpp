/* CSCI 261: L5A: Input & Print an Array
 *
 * Author: Jarod Spencer
 *
 *Description: An easy example of how arrays can be taken in, iterated through, and used.
 */

#include <iostream>

using namespace std;

int main() {
    //Declares array
    const int SLOTS = 15;
    int numbers [SLOTS];
    cout << "\nHey! Witness my first array mojo!" << endl;
    cout << "Enter 15 numbers and I will tell you what they are." << endl;

    //Loop takes in ith value of the array, assigns it, and then prints it
    for (int i = 0; i < SLOTS; ++i) {
        cin >> numbers[i];
        cout << "Number " << i + 1 << ": " << numbers[i] << endl;
    }
    cout << "So awesome!" << endl;
    cout << "The numbers are: ";

    //Loop prints out array values in sequential order
    for (int j = 0; j < SLOTS; ++j) {
        cout << numbers[j] << " ";
    }
    cout << "\nHave a nice day!" << endl;
    return 0;
}