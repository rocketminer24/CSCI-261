/* CSCI 261: A5: Hangman
 *
 * Author: Jarod Spencer
 *
 *Description: Functions to run hangman game.
 */


#include <iostream>
#include "A5_functions.h"

using namespace std;

const int WORD_SIZE = 13;//number of letters in secret word
const int UNIQUE_PLUS_WRONG = 16;//max number of guesses (unique correct letters + 7 incorrect guesses)
char guesses[UNIQUE_PLUS_WRONG];//array that tracks guesses
char hangmanArray[WORD_SIZE] = {'I', 'R', 'O', 'D', 'O', 'S', 'I', 'C', 'L', 'Y', 'T', 'I', 'S'};//array that holds answer

void hangman() {
    char guess;//user inputted guess
    int a = 0;//current guess number
    int wrongCounter = 7;//number of wrong guesses left
    bool complete = false;//bool to check if word has been completely guessed
    bool isFinished = true;//bool to check if game is finished

    //while loop takes in guesses and evaluates them until word is complete or out of wrong guesses
    while (!complete) {
        bool duplicate = false;//bool to check if guess was a duplicate
        bool correct = false;//bool to check if individual guess was correct

        cout << "\nTake a guess: ";

        printBoard(a);

        //if user-entered guess was lowercase, converts to uppercase to check array
        cout << "Your guess: ";
        cin >> guess;
        guess = toupper(guess);

        duplicateCheck(a, guess, duplicate);

        //if guess is a duplicate, informs user and ends current while loop iteration
        //else, determines guess to be valid and assigns guess to a location in guess array
        if (duplicate) {
            cout << "You already picked " << guess << ". Pick again." << endl << endl;
            continue;
        } else {
            guesses[a] = guess;
        }

        //if guess is correct (checked by calling the isCorrectGuess function), calls correctGuess function
        //else, calls wrongGuess function
        if (isCorrectGuess(a, correct)) {
            correctGuess(a);
        } else {
            wrongGuess(a, wrongCounter, isFinished, complete);
        }

        //breaks out of while loop if isFinished == true, which occurs if user ran out of wrong
        // guesses (determined by the wrongGuess function)
        if (!isFinished)    {
            break;
        }

        if (solvedCheck(a, complete)) {
            break;
        }

        ++a;//increments guess number for next while loop iteration
    }

    solved(isFinished);
}

//decides whether to print letter or underscore for game board
void printBoard(int a)   {

    //loops check each letter of secret word to see if they have been guessed and if so prints that
    // letter instead of an underscore
    for (int i = 0; i < WORD_SIZE; ++i) {
        bool printLetter = false;//bool to check if letter will be printed in place of an underscore
        for (int j = 0; j <= a; ++j) {
            if (guesses[j] == hangmanArray[i]) {
                printLetter = true;
            }
        }
        if (printLetter) {
            cout << hangmanArray[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

//checks for duplicate guesses
bool duplicateCheck(int a, char guess, bool &duplicate) {
    for (int g = 0; g < a; ++g) {
        if (guess == guesses[g]) {
            duplicate = true;
        }
    }
    return duplicate;
}

//determines if guess was correct by iterating through the secret word checking the letters
bool isCorrectGuess (int a, bool &correct)   {
    for (int i = 0; i < WORD_SIZE; ++i) {
        if (hangmanArray[i] == guesses[a]) {
            correct = true;
            break;
        }
    }
    if (correct) {
        return true;
    } else {
        return false;
    }
}

//called if guess was correct, informs user of correct guess
void correctGuess(int a) {
    cout << "There's a " << guesses[a] << "!" << endl;
}

//called if guess was wrong
void wrongGuess(int a, int &wrongCounter, bool &isFinished, bool &complete) {
    --wrongCounter;
    cout << "Sorry, no " << guesses[a] << "'s. ";

    //if out of wrong guesses, terminates game
    if (wrongCounter == 0) {
        complete = true;
        isFinished = false;
        cout << "\nYou lose. Try again!" << endl;

    //else, informs user of number of wrong guesses remaining
    } else {
        cout << "You have " << wrongCounter << " wrong guesses remaining." << endl;
    }
}

//bool function checks to see if puzzle has been solved
bool solvedCheck(int a, bool &complete) {
    complete = true;

    //loop checks to see if it would print full word here if given cout commands, and if so, changes complete to true
    for (int i = 0; i < WORD_SIZE; ++i) {
        bool printLetter = false;
        for (int j = 0; j <= a; ++j) {
            if (guesses[j] == hangmanArray[i]) {
                printLetter = true;
            }
        }
        if (!printLetter) {
            complete = false;
        }
    }
    if (complete)   {
        return true;
    } else {
        return false;
    }
}

//game over, prints congratulatory statement if user correctly guessed secret word
void solved(bool isFinished) {
    if(isFinished)  {
        cout << "CONGRATS! You solved the puzzle: ";
        for (int i = 0; i < WORD_SIZE; ++i) {
            cout << hangmanArray[i] << " ";
        }
        cout << endl;
    }
}
