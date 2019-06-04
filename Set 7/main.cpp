/* CSCI 261: L7B: Starcraft
 *
 * Author: Jarod Spencer
 *
 * Description: Using file input to draw a star map
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"
#include "starDataStruct.h"

using namespace std;

int main() {
    const int WIDTH = 640;
    const int HEIGHT = 640;
    vector<StarData> starData;
    StarData set1;

    //check for error
    ifstream dataIn("stars.txt");
    if (dataIn.fail())  {
        cerr << "Could not open \"stars.txt\"" << endl;
        return -1;
    }

    //read data into vector until end of txt file
    while (!dataIn.eof())   {
        dataIn >> set1.starX >> set1.starY >> set1.junk1 >> set1.brightness >> set1.junk2 >> set1.junk3;
        starData.push_back(set1);
    }

    //convert x and y coordinates for each star
    for (int i = 0; i < starData.size(); ++i) {
        convertXPos(i, WIDTH, starData);
    }
    for (int i = 0; i < starData.size(); ++i) {
        convertYPos(i, HEIGHT, starData);
    }

    //print stars data if brightness is 0.0 to 8.0
    for (int i = 0; i < starData.size(); ++i)   {
        if (starData[i].brightness >= 0.0 && starData[i].brightness <= 8.0) {
            cout << starData[i].starX << "\t" << starData[i].starY << "\t" << starData[i].brightness << endl;
        }
    }

    dataIn.close();

    return 0;
}