/* CSCI 261: A7: Stargate
 *
 * Author: Jarod Spencer
 *
 * Description: Using file input to draw a star map
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include "starDataStruct.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

    //declare constants, struct, and vector
    const int WIDTH = 640;
    const int HEIGHT = 640;
    vector<StarData> starData;
    StarData set1;

    //open input file and check for errors
    ifstream dataIn("stars.txt");
    if (dataIn.fail())  {
        cerr << "Could not open \"stars.txt\"" << endl;
        return -1;
    }

    //open output file and check for errors
    ofstream dataOut("ModifiedStars.txt");
    if (dataOut.fail())  {
        cerr << "Could not open \"ModifiedStars.txt\"" << endl;
        return -1;
    }

    //read input data into vector until end of txt file
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

    //prints star data if brightness is 0.0 to 8.0
    writeStarData(starData, dataOut);

    //close input file
    dataIn.close();

    //find the brightest star
    int BRIGHTEST_STAR = 0;
    int BRIGHTEST_STAR_LOCATION = 0;
    for (int i = 0; i < starData.size(); ++i)   {
        if (starData[i].brightness > BRIGHTEST_STAR)    {
            BRIGHTEST_STAR_LOCATION = i;
        }
    }

    //draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );

        int radius = 2;

        //draws stars in the window
        drawStars(window, radius, starData, BRIGHTEST_STAR_LOCATION);

        window.display();

        Event event;
        while( window.pollEvent(event) ) {
            if( event.type == Event::Closed ) {
                window.close();
            }
        }
    }

    //close output file
    dataOut.close();

    return 0;
}