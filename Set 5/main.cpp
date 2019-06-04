/* CSCI 261: L5B: Find the Array Max
 *
 * Author: Jarod Spencer
 *
 * Description: An easy example of how arrays can be taken in, iterated through, and used.
 */

#include <iostream>

using namespace std;

int main() {
    //Declares array and variables
    const int SLOTS = 15;
    int numbers [SLOTS];
    int bigOne = 0;
    int smallOne = 0;

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

    //Identifies largest and smallest numbers
    for (int k = 0; k < SLOTS; ++k) {
        if (numbers[k] > bigOne)    {
            bigOne = numbers[k];
        }
    }
    for (int l = 0; l < SLOTS; ++l) {
        if (numbers[l] < smallOne)  {
            smallOne = numbers[l];
        }
    }

    cout << "The largest number is: " << bigOne << endl;
    cout << "The smallest number is: " << smallOne << endl;
    cout << "Gaze at my awesome." << endl;
    return 0;
}