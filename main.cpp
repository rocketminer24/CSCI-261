/* CSCI 261 Lab 4A: Yahtzee
 *
 * Author: Jarod Spencer
 *
 * Description: Writing functions for 2 yahtzee play categories.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

//determines if threes can be scored
bool isThrees (int die1, int die2, int die3, int die4, int die5) {
    if (die1 == 3 || die2 == 3 || die3 == 3 || die4 == 3 || die5 == 3) {
        return true;
    } else {
        return false;
    }
}

//determines if four of a kind can be scored
bool isFourKind (int die1, int die2, int die3, int die4, int die5)  {
    bool isFourKind = false;

    if (die1 == die2 && die1 == die3 && die1 == die4)   {
        isFourKind = true;
    }
    if (die1 == die2 && die1 == die3 && die1 == die5)   {
        isFourKind = true;
    }
    if (die1 == die2 && die1 == die4 && die1 == die5)   {
        isFourKind = true;
    }
    if (die1 == die3 && die1 == die4 && die1 == die5)   {
        isFourKind = true;
    }
    if (die2 == die3 && die2 == die4 && die2 == die5)   {
        isFourKind = true;
    }

    return isFourKind;
}