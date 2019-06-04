//
// Created by Jarod Spencer1 on 2019-04-22.
//

#ifndef FINAL_PROJECT_PLAYERSTRUCTS_H
#define FINAL_PROJECT_PLAYERSTRUCTS_H

#include <string>
using namespace std;

struct PlayerData   {
    string playerName;
    string handedness;
    double distance;
};

struct PlayerResults    {
    string playerName;
    double velocity;
    int discAngle;
    int launchAngle;
};

#endif //FINAL_PROJECT_PLAYERSTRUCTS_H
