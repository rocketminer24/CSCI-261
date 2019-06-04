//
// Created by Jarod Spencer1 on 2019-04-15.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include "starDataStruct.h"

using namespace sf;

//converts given x position to SFML x position
void convertXPos(int i, const int &WIDTH, vector<StarData> &starData)   {
    starData.at(i).starX = (int)((starData.at(i).starX + 1) * WIDTH / 2 );
}

//converts given y position to SFML y position
void convertYPos(int i, const int &HEIGHT, vector<StarData> &starData)  {
    starData.at(i).starY = (int)((-starData.at(i).starY + 1 ) * HEIGHT / 2 );
}

//writes data in starData vector to output file
void writeStarData(vector<StarData> &starData, ofstream &dataOut)   {
    for (int i = 0; i < starData.size(); ++i)   {
        if (starData[i].brightness >= 0.0 && starData[i].brightness <= 8.0) {
            dataOut << starData[i].starX << "\t" << starData[i].starY << "\t" << starData[i].brightness << endl;
        }
    }
}

//draws stars in appropriate location with given radius and with appropriate brightness
void drawStars(RenderWindow &window, const int &radius, vector<StarData> &starData, const int &BRIGHTEST_STAR_LOCATION) {
    CircleShape star;
    int shadeOfGray = 0;

    //sets star values and draws them
    for (int i = 0; i < starData.size(); ++i) {
        star.setRadius(radius);
        star.setPosition(Vector2f(starData.at(i).starX, starData.at(i).starY));

        //calculates appropriate shade of gray and sets star's fill color to that
        shadeOfGray = (int)((255.0 * starData[i].brightness) / starData[BRIGHTEST_STAR_LOCATION].brightness);
        star.setFillColor(Color(shadeOfGray, shadeOfGray, shadeOfGray));

        window.draw(star);
    }
}