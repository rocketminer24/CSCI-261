//
// Created by Jarod Spencer1 on 2019-04-22.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#include "PlayerStructs.h"
#include "Pulling.h"

//default constructor (never used)
Pulling::Pulling() {
}

//parameterized constructor
Pulling::Pulling(string inputFileName) {
    initializeDataVector(inputFileName);
}

//public getter and setter functions for wind speed, angle, and inclination
void Pulling::setWindSpeed() {
    cin >> windSpeed;
}

void Pulling::setWindAngle() {
    cin >> windAngle;
}

void Pulling::setWindInclination() {
    cin >> windInclination;
}

double Pulling::getWindSpeed() const {
    return windSpeed;
}

double Pulling::getWindAngle() const {
    return windAngle;
}

double Pulling::getWindInclination() const {
    return windInclination;
}

//getter to return whether input file was opened or not
bool Pulling::getOpen() const {
    return open;
}

//function to take in input file from constructor and initialize the playersData vector
bool Pulling::initializeDataVector(const string &inputFileName) {
    string name;
    string hand;
    double desiredDistance;

    ifstream inputData(inputFileName);
    if (inputData.fail()) {
        cerr << "Could not open\"" << inputFileName << "\" to read." << endl << endl;
        open = false;
        return false;
    }
    while (!inputData.eof()) {
        inputData >> name >> hand >> desiredDistance;
        PlayerData newPlayer;
        newPlayer.playerName = name;
        newPlayer.handedness = hand;
        newPlayer.distance = desiredDistance;
        playersData.push_back(newPlayer);
    }

    inputData.close();

    return true;
}


//function writes the playerResults vector by calling the calculate functions and using the playersData vector
void Pulling::writeResultsVector() {
    PlayerResults tempResultsStruct;
    for (int i = 0; i < playersData.size(); ++i) {
        tempResultsStruct.playerName = playersData[i].playerName;
        tempResultsStruct.launchAngle = calculateLaunchAngle();
        tempResultsStruct.velocity = calculateVelocity(i, tempResultsStruct.launchAngle);
        tempResultsStruct.discAngle = calculateDiscAngle();

        this->playersResults.push_back(tempResultsStruct);
    }
}


//calculate functions use the user-entered wind data and the playersData vector to calculate the angle the
//   disc should be angled at, launched at, and the velocity it should be thrown at
double Pulling::calculateLaunchAngle() {
    double templaunchAngle;

    //determines necessary launch angle given wind inclination angle
    if (this->windInclination < -10) {
        templaunchAngle = 15;
    } else if (this->windInclination >= -10 && this->windInclination < 0) {
        templaunchAngle = 10;
    } else {
        templaunchAngle = 5;
    }

    return templaunchAngle;
}

double Pulling::calculateVelocity(int index, double launchAngle) {//avg pull velocity = 38mph
    //determines velocity without wind speed factored in
    double distance = playersData[index].distance / 3;
    double gravity = 32;
    double velocity = sqrt((distance * gravity) / (2 * sin(launchAngle * 3.14 / 180) * cos(launchAngle * 3.14 / 180)));

    //factors in wind speed
    if (cos(windAngle * 3.14 / 180) > 0) {
        velocity -= cos(windSpeed * 3.14 / 180);
    } else {
        velocity += cos(windSpeed * 3.14 / 180);
    }

    return velocity;
}

double Pulling::calculateDiscAngle() {
    int discAngle = 0;

    //determines necessary disc angle given wind angle if wind speed is not 0
    if (windSpeed != 0) {
        if ((windAngle <= 180 && windAngle > 160) || (windAngle > -20 && windAngle < 20) ||
            (windAngle <= -160 && windAngle >= -180)) {
            discAngle = 0;
        } else if ((windAngle <= 160 && windAngle > 130) || (windAngle <= 50 && windAngle >= 20)) {
            discAngle = -20;
        } else if (windAngle <= 130 && windAngle > 50) {
            discAngle = -45;
        } else if ((windAngle <= -20 && windAngle > -50) || (windAngle <= -130 && windAngle > -160)) {
            discAngle = 20;
        } else if (windAngle > -130 && windAngle <= -50)    {
            discAngle = 45;
        } else {
            windAngle = (int)windAngle % 180;
            discAngle = calculateDiscAngle();
        }
    } else {
        discAngle = 0;
    }

    return discAngle;
}


//function writes output file
bool Pulling::writeFile(string outputFileName) {

    //loop writes individual players strings and store them in the playersStrings vector
    for (int i = 0; i < playersResults.size(); ++i) {
        playersStrings.push_back(createString(i));
    }

    //opens output file and checks to see if file is writeable
    ofstream outputData(outputFileName);
    if (outputData.fail()) {
        cerr << "Could not open \"" << outputFileName << "\" to write." << endl;
        return false;
    }

    //writes overarching data to output file
    outputData << "All players should launch the discs at an angle of " <<
               to_string(playersResults[0].launchAngle) << ".0 degrees." << endl << endl;

    if (playersResults[0].discAngle != 0) {
        outputData << "Right-handed players should angle the discs at " <<
                   to_string(playersResults[0].discAngle) <<
                   ".0 degrees, while left-handed players should angle the discs at "
                   << to_string(-1 * playersResults[0].discAngle) << ".0 degrees." << endl << endl;
    } else {
        outputData << "All players should angle the discs at " << to_string(playersResults[0].discAngle)
                   << ".0 degrees." << endl << endl;
    }

    //writes individual player strings in playersStrings vector to output file
    for (int i = 0; i < playersStrings.size(); ++i) {
        outputData << playersStrings[i] << endl;
    }

    outputData.close();

    return true;
}


//function creates and returns an individual player's output string given their location in the playersResults vector
string Pulling::createString(int index) {
    string tempString;
    tempString = playersResults[index].playerName + " should throw the disc at " +
                 to_string(playersResults[index].velocity) + " mph.";
    return tempString;
}