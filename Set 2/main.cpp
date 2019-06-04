/* CSCI 261 Lab 2E: RPS: Human vs. Computer
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

    // Establishes playerChoice char, seeds the rand function, and gives rand to computerChoice.
    char playerChoice;
    srand(time(0));
    int computerChoice = rand() % 3;

    //Begins game.
    cout << "\nWelcome one and all to a round of Rock, Paper, Scissors! (Enter R, P, or S)" << endl;

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
    else {
        cout << "Woops! It appears you did not choose either rock, paper, or scissors." << endl;
        cout << "Please enter R, P, or S next time. \n" << endl;
    }

    //Computer chooses which statement to print based on computer's choice.
    if (computerChoice == 0)   {
        cout << "Computer chooses Rock" << endl;
    }
    else if (computerChoice == 1) {
        cout << "Computer chooses Paper" << endl;
    }
    else {
        cout << "Computer chooses Scissors" << endl;
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
        //Player wins
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 2)    {
        cout << "Rock beats scissors. Player wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 0)    {
        cout << "Paper beats rock. Player wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 1)    {
        cout << "Scissors beats paper. Player wins!" << endl;
    }
        //Computer wins
    if ((playerChoice == 'R' || playerChoice == 'r') && computerChoice == 1)    {
        cout << "Paper beats rock. Computer wins!" << endl;
    }
    if ((playerChoice == 'P' || playerChoice == 'p') && computerChoice == 2)    {
        cout << "Scissors beats paper. Computer wins!" << endl;
    }
    if ((playerChoice == 'S' || playerChoice == 's') && computerChoice == 0)    {
        cout << "Rock beats scissors. Computer wins!" << endl;
    }
    return 0;
}