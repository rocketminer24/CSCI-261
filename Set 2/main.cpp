/* CSCI 261 Lab 2C: RPS: Human vs. Computer
 *
 * Author: Jarod Spencer
 *
 * Description: Making a rock, paper, scissors game.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    char playerChoice;
    cout << "\nWelcome one and all to a round of Rock, Paper, Scissors! (Enter R, P, or S)" << endl;

    cout << "Player one: ";
    cin >> playerChoice;
    cout << endl;

    cout << "Player chooses " << playerChoice << endl;

    srand(time(0));
    cout << "Computer chooses " << rand() % 3 << endl;

    return 0;
}