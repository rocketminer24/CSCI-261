/* CSCI 261: A5: Hangman
 *
 * Author: Jarod Spencer
 *
 *Description: A playable hangman game using arrays, functions, loops, and conditionals.
 */

#ifndef A5_FUNCTIONS_H
#define A5_FUNCTIONS_H

void hangman();
void printBoard(int);
bool duplicateCheck(int, char, bool &);
bool isCorrectGuess(int, bool &);
void correctGuess(int);
void wrongGuess(int, int &, bool &, bool &);
bool solvedCheck(int, bool &);
void solved(bool);

#endif //A5_FUNCTIONS_H

