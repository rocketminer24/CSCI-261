/* CSCI 261: L5C: Matrix Transposition
 *
 * Author: Jarod Spencer
 *
 * Description: Uses arrays and for loops to build and transpose a matrix
 */

#include <iostream>

using namespace std;

int main() {
    //Declares size of 2-dimensional array
    const int ROWS = 4;
    const int COLUMNS = 3;

    //Declares 2-dimensional array
    int matrix [ROWS][COLUMNS];

    cout << "Welcome to the Matrix Calculator!" << endl << endl;

    //Takes in and assigns values for each array slot
    cout << "Please enter a " << ROWS << "x" << COLUMNS << " matrix:" << endl;
    for (int i = 0; i < ROWS; ++i)  {
        for (int j = 0; j < COLUMNS; ++j)   {
            cout << "Enter Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> matrix [i][j];
        }
    }
    cout << endl;

    //Prints standard matrix
    cout << "The matrix you entered is:" << endl;
    for (int i = 0; i < ROWS; ++i)  {
        cout << "[ ";
        for (int j = 0; j < COLUMNS; ++j)   {
            cout << "  " << matrix [i][j];
        }
        cout << " ]" << endl;
    }
    cout << endl;

    //Prints transposed matrix
    cout << "The transpose of the matrix is:" << endl;
    for (int i = 0; i < COLUMNS; ++i)  {
        cout << "[ ";
        for (int j = 0; j < ROWS; ++j)   {
            cout << "  " << matrix [j][i];
        }
        cout << " ]" << endl;
    }
    cout << endl;

    cout << "Have a nice day!" << endl;

    return 0;
}