//
// Created by Jarod Spencer1 on 2019-04-16.
//

#include <iostream>
#include <string>

using namespace std;
#include "Godzilla.h"

Godzilla::Godzilla() {
    srand(time(0));
    name = "Godzilla";
    health = (rand() % 51) + 50;
    power = (rand() % 16) + 10;
}

Godzilla::Godzilla(string name, double health, double power) {
    srand(time(0));

    this->name = name;
    this->health = health;
    this->power = power;

    if (health < 0) {
        this->health = (rand() % 51) +50;
    }
    if (power < 0)  {
        this->power = (rand() % 16) + 10;
    }
}