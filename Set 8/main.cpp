/* CSCI 261: Final Project: Pulling Optimization
 *
 * Author: Jarod Spencer
 *
 * Description: Using data of an Ultimate Frisbee team to calculate and output necessary pulling stats
 */

#include <iostream>
#include "Pulling.h"

using namespace std;

int main() {
    //takes in user's input file
    cout << "Enter input file name: ";
    string inputFileName;
    getline(cin, inputFileName);
    cout << endl;

    //tells program the user wants to calculate pulling data for their Ultimate frisbee team given an input
    //    file with their data
    Pulling pulling(inputFileName);

    if (pulling.getOpen())  {
        //user sets the day's wind data
        cout << "Enter the current day's data (speed, directional angle, and angle of inclination): ";
        pulling.setWindSpeed();
        pulling.setWindAngle();
        pulling.setWindInclination();
        cout << endl;

        //user calls the writeResultsVector function to calculate and store the desired data
        pulling.writeResultsVector();

        string junk;
        getline(cin, junk);

        //takes in user's desired output file name
        cout << "Enter the desired name of your output file: ";
        string outputFileName;
        getline(cin, outputFileName);
        cout << endl;

        //if-else statement checks to see if output file was able to be written and ends program
        if (pulling.writeFile(outputFileName))    {
            cout << outputFileName << " written." << endl;
            return 0;
        } else {
            cout << "Error writing output file." << endl;
            return -1;
        }
    } else {
        return -1;
    }
}