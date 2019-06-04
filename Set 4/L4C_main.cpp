/* CSCI 261: Fix Function Errors
 *
 * Author: Jarod Spencer
 *
 *Description: This program illustrates a variety of common loop errors. Fix the errors in each section.

Copyright 2018 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// input: integer
// output: none
// adds five to the given parameter
void addFive( int &x ) {
    x += 5;
}

void printSmileyFace () {
    cout << ":)" << endl;
}

// input: none
// output: a random number
int generateRandomNumber() {
    return rand() % 100;
}

// input: three integers
// output: the sum of all three parameters
int sum (int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

// input: two doubles
// output: the product of the two doubles
double multiply (double doub1, double doub2)   {
    return doub1 * doub2;
}

int main() {
    cout << "Welcome to Function World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = added & before x in function parameter so as to properly pass by reference
// TESTS: commented out all other functions and code and ran program expecting numTrees to now equal 9

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int numTrees = 4;
    cout << "There are initially " << numTrees << " trees." << endl;
    addFive( numTrees );
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = function printSmileyFace did not exist, fixed by creating it and having it print a smiley face
// TESTS: commented out all other functions and code and ran program expecting :) to be printed

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    printSmileyFace();

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = rand was reseeded with the same value for every iteration of the for loop, moved srand(time(0));
//        down into main
// TESTS: commented out all other functions and code and ran program expecting 5 different random
//         numbers to be printed

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    cout << "Five different random numbers are: " << endl;
    srand( time(0) );
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generateRandomNumber() << endl;
    }


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = functions was trying to improperly and illogically pass by reference, fixed by passing by values and
//        including all three numbers
// TESTS: commented out all other functions and code and expected 6 as the output for the sum of 1, 2, 3

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum (num1, num2, num3) << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = function call was missing parentheses, fixed by adding parentheses to function call
// TESTS: commented out all other functions and code and ran program expecting a random number output

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "Another random number is " << generateRandomNumber() << endl;

// SECTION VI: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = function was trying to pass by reference with no data, changed to pass by value
// TESTS: ran program expecting 4.4 as output for 1.1 and 4.0

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VI" << endl;
    cout << "******************" << endl;

    double doub1, doub2;
    cout << "Enter two doubles: ";
    cin >> doub1 >> doub2;
    cout << "Their product is: " << multiply (doub1, doub2) << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}
