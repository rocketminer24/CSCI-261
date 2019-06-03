/* CSCI 261 Lab 2E Extra Credit: RPSLV: Human vs. Computer
 *
 * Author: Jarod Spencer
 *
 * Description: Making a rock, paper, scissors, lizard, Spock game.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    // Establishes playerChoice char, seeds the rand function, and gives rand to computerChoice.
    char playerChoice;
    srand(time(0));
    int computerChoice = rand() % 5;

    //Begins game.
    cout << "\nWelcome one and all to a round of Rock, Paper, Scissors, Lizard, Spock! (Enter R, P, S, L , or V (for Spock))" << endl;

    cout << "Player one: ";
    cin >> playerChoice;
    cout << endl;

    //Computer chooses which statement to print based on player's choice.
    if (playerChoice == 'R' || playerChoice == 'r')   {
        cout << "Player chooses Rock" << endl;
    }
    else if (playerChoice == 'P' || playerChoice == 'p') {
        cout << "Player chooses Paper" << endl;
    }
    else if (playerChoice == 'S' || playerChoice == 's')    {
        cout << "Player chooses Scissors" << endl;
    }
    else if (playerChoice == 'L' || playerChoice == 'l')    {
        cout << "Player chooses Lizard" << endl;
    }
    else if (playerChoice == 'V' || playerChoice == 'v')    {
        cout << "Player chooses Spock" << endl;
    }
    else {
        cout << "Woops! It appears you did not choose either rock, paper, scissors, lizard, or Spock." << endl;
        cout << "Please enter R, P, S, L, or V next time. \n" << endl;
    }

    //Computer chooses which statement to print based on computer's choice.
    if (computerChoice == 0)   {
        cout << "Computer chooses Rock" << endl;
    }
    else if (computerChoice == 1) {
        cout << "Computer chooses Paper" << endl;
    }
    else if (computerChoice == 2) {
        cout << "Computer chooses Scissors" << endl;
    }
    else if (computerChoice == 3) {
        cout << "Computer chooses Lizard" << endl;
    }
    else {
        cout << "Computer chooses Spock" << endl;
    }
    cout << endl;

    //Computer determines who won and prints appropriate cout statement.
        //Ties
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 0)    {
        cout << "Tie." << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 1)    {
        cout << "Tie." << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 2)    {
        cout << "Tie." << endl;
    }
    if ((playerChoice == 'L' || playerChoice == 'l') && computerChoice == 3)    {
        cout << "Tie." << endl;
    }
    if ((playerChoice == 'V' || playerChoice == 'v') && computerChoice == 4)    {
        cout << "Tie." << endl;
    }

        //Player wins
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 2)    {
        cout << "Rock crushes scissors. Player wins!" << endl;
    }
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 3)    {
        cout << "Rock crushes lizard. Player wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 0)    {
        cout << "Paper covers rock. Player wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 4)    {
        cout << "Paper disproves Spock. Player wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 1)    {
        cout << "Scissors cuts paper. Player wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 3)    {
        cout << "Scissors decapitates lizard. Player wins!" << endl;
    }
    if ((playerChoice == 'L' || playerChoice == 'l') && computerChoice == 1)    {
        cout << "Lizard eats paper. Player wins!" << endl;
    }
    if ((playerChoice == 'L' || playerChoice == 'l') && computerChoice == 4)    {
        cout << "Lizard poisons Spock. Player wins!" << endl;
    }
    if ((playerChoice == 'V' || playerChoice == 'v') && computerChoice == 0)    {
        cout << "Spock vanquishes rock. Player wins!" << endl;
    }
    if ((playerChoice == 'V' || playerChoice == 'v') && computerChoice == 2)    {
        cout << "Spock smashes scissors. Player wins!" << endl;
    }

        //Computer wins
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 1)    {
        cout << "Paper covers rock. Computer wins!" << endl;
    }
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 4)    {
        cout << "Spock vanquishes rock. Computer wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 2)    {
        cout << "Scissors cuts paper. Computer wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 3)    {
        cout << "Lizard eats paper. Computer wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 0)    {
        cout << "Rock crushes scissors. Computer wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 4)    {
        cout << "Spock smashes scissors. Computer wins!" << endl;
    }
    if ((playerChoice == 'L' || playerChoice == 'l') && computerChoice == 0)    {
        cout << "Rock crushes lizard. Computer wins!" << endl;
    }
    if ((playerChoice == 'L' || playerChoice == 'l') && computerChoice == 2)    {
        cout << "Scissors decapitates lizard. Computer wins!" << endl;
    }
    if ((playerChoice == 'V' || playerChoice == 'v') && computerChoice == 1)    {
        cout << "Paper disproves Spock. Computer wins!" << endl;
    }
    if ((playerChoice == 'V' || playerChoice == 'v') && computerChoice == 3)    {
        cout << "Lizard poisons Spock. Computer wins!" << endl;
    }

    return 0;
}