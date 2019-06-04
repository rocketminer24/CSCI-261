/* CSCI 261 A3: Guess the Number
 *
 * Author: Jarod Spencer
 *
 * Description: Use selection and looping statements to make a guessing game.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    int numLow = 0;
    int numHigh = 0;
    int actualNumber = 0;
    int playerGuess = 0;
    int numTries = 0;
    int TOO_CLOSE_DIFFERENCE = 5;
    int TOO_HIGH_DIFFERENCE = 25;

    cout << "\nWelcome to Guess the Number!" << endl;

    //User inputs low end of number range.
    cout << "Enter your lowest possible number: ";
    cin >> numLow;
    cout << endl;

    //User inputs high end of number range
    cout << "Enter your highest possible number: ";
    cin >> numHigh;

    //Asks for high end of range again if high end is less than 100 greater than the low end.
    while (numHigh < (numLow + 100)) {
        cout << "High number must be at least 100 more than the low number.\n" << endl;
        cout << "Enter your highest possible number: ";
        cin >> numHigh;
    }
    cout << endl;

    //Seeds random function and assigns random number with variable actualNumber.
    srand(time(0));
    actualNumber = rand() % (numHigh + 1 - numLow) + numLow;

    //Player takes initial guess.
    cout << "Pick a number between " << numLow << " and " << numHigh << ": ";
    cin >> playerGuess;
    numTries++;

    //Prints statements based on proximity of playerGuess to actualNumber and asks player to guess again.
    while (playerGuess != actualNumber) {
        if (playerGuess < numLow || playerGuess > numHigh) {
            cout << "Invalid guess.";
        } else {
            if (playerGuess < actualNumber) {
                cout << "Too low! ";
            }
            if (playerGuess > actualNumber) {
                cout << "Too high! ";
            }
            if (playerGuess >= (actualNumber - TOO_CLOSE_DIFFERENCE) &&
                playerGuess <= (actualNumber + TOO_CLOSE_DIFFERENCE)) {
                cout << "Oooh you're close!";
            }
            if (playerGuess <= (actualNumber - TOO_HIGH_DIFFERENCE) ||
                playerGuess >= (actualNumber + TOO_HIGH_DIFFERENCE)) {
                cout << "Not even close!";
            }
        }
        cout << "\n\nPick a number between " << numLow << " and " << numHigh << ": ";
        cin >> playerGuess;
        numTries++;
    }

    //Player guessed right. Prints congratulatory statement and reports number of guesses used.
    cout << "\nThat's right! You won the game in " << numTries << " tries." << endl;

    return 0;

}
