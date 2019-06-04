/* CSCI 261: Fix Loop Errors
 *
 * Author: Jarod Spencer and Jordan Turnquest
 *
 *    This program illustrates a variety of common loop errors.
 *    Fix the errors in each section.

Copyright 2017 Dr. Jeffrey Paone

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

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Loop only sums numbers 1 to 4. Fixed by changing i < 5 to i <=5.
// TESTS: Commented out all other code and ran program expecting 15 as output.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    short sum;  // Accumulates the total
    short i;    // Used as loop control variable
    for (i = 1; i <= 5; ++i) {
        sum += i;
    }
    cout << "The sum of the numbers from 1 to 5 (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
/* FIX = For each iteration of the while loop, total is initialized with 0.
 * Results in an infinite loop. Fixed by moving initialization of total variable
 * outside of the while loop.
 *
 * TESTS: Commented out other sections and ran program expecting 10 as the output
 * due to 4 items worth 1, 2, 3, and 4, respectively.
 */

    cout << endl;
	cout << "******************" << endl;
	cout << "Section II" << endl;
	cout << "******************" << endl;

    double total = 0;     // Accumulates total
    double price;    // Gets next price from user
    short num_items;     // Number of items
    short counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> num_items;
    cout << endl;

    while (counter <= num_items) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        cout << endl;
        total += price;
        counter++;
    }
    cout << "The total price is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
/* FIX = Counter was never incremented and condition used counter <= sum instead of
 * counter <=4, resulting in an infinite loop. Fixed by incrementing counter after
 * each iteration and by switching the condition to counter <= 4.
*/
// TESTS: Commented out other sections and ran program expecting 10 as the output.

    cout << endl;
	cout << "******************" << endl;
	cout << "Section III" << endl;
	cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of numbers from 1 to 4 (inclusive)" << endl;

    sum = 0;
    counter = 1;

    do {
        sum += counter;
        cout << "Sum so far: " << sum << endl;
        counter++;
    } while (counter <= 4);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to 4 (inclusive) as " << sum << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
/* FIX = for loop initialized i with 4 instead of zero such that summation of squares
 * will not begin with 1. Also looping condition i > 0 creates an infinite loop. Fixed
 * by initializing i with 1 and changing condition to i <= 4.
*/
// TESTS: Commented out other sections and ran program expecting 30 as the output.

    cout << endl;
	cout << "******************" << endl;
	cout << "Section IV" << endl;
	cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of squares from 1 to 4 (inclusive)" << endl;

    sum = 0;
    for (i = 1; i <= 4; i++) {
        sum += i * i;
    }

    cout << "The sum of squares from 1 to 4 is: " << sum << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
/* FIX = Because incrementation of counter variable occurs outside of while loop,
 * loop is infinite. Loop also tries to calculate sum of cubes from 1 to 10 because
 * condition is counter < 10 not counter < 5. Fixed by placing incrementation command
 * at the end of the loop and changing looping condition to counter <= 4.
 */
// TESTS: Ran program expecting 100 as the output.

    cout << endl;
	cout << "******************" << endl;
	cout << "Section V" << endl;
	cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of cubes from 1 to 4 (inclusive)" << endl;

    sum = 0;
    counter = 1;

    while (counter <= 4) {
        sum += (counter * counter * counter);
        counter++;
    }

    cout << "The sum of cubes from 1 to 4 is: " << sum << endl;

    cout << endl;
	cout << "******************" << endl;
	cout << "Section Done" << endl;
	cout << "******************" << endl;

	cout << endl << "Congrats!  You fixed them all (hopefully correctly!)";
	cout << endl << endl << "Goodbye" << endl << endl;

    return 0;
}