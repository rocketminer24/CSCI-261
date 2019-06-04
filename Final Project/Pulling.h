//
// Created by Jarod Spencer1 on 2019-04-22.
//

#ifndef FINAL_PROJECT_PULLING_H
#define FINAL_PROJECT_PULLING_H

#include <vector>
#include "PlayerStructs.h"

class Pulling {
public:
    Pulling();
    Pulling(string inputFileName);

    //public member functions
    void setWindSpeed();
    void setWindAngle();
    void setWindInclination();
    double getWindSpeed() const;
    double getWindAngle() const;
    double getWindInclination() const;
    bool getOpen() const;
    bool initializeDataVector(const string &file);
    void writeResultsVector();
    bool writeFile(string outputFileName);

private:
    //vector of each player's input data through use of a struct
    vector<struct PlayerData> playersData;

    //vector of each player's calculated data through use of a struct
    vector<struct PlayerResults> playersResults;

    //vector of each player's individual output data as a string
    vector<string> playersStrings;

    //private data members
    bool open = true;
    double windSpeed;
    double windAngle;
    double windInclination;

    //private member functions
    double calculateLaunchAngle();
    double calculateVelocity(int index, double);
    double calculateDiscAngle();
    string createString(int index);
};

#endif //FINAL_PROJECT_PULLING_H
