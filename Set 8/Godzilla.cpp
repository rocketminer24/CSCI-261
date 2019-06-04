//
// Created by Jarod Spencer1 on 2019-04-17.
//

#include <iostream>
#include <string>

using namespace std;

#include "Godzilla.h"

Godzilla::Godzilla() {
    name = "Godzilla";
    initializeHealth();
    initializePower();
}

Godzilla::Godzilla(string name, double health, double power) {
    this->name = name;
    setHealth(health);
    setPower(power);
}

void Godzilla::initializeHealth() {
    health = (rand() % 51) + 50;
}

void Godzilla::initializePower()  {
    power = (rand() % 16) + 10;
}

void Godzilla::setName(string name)   {
    this->name = name;
}

void Godzilla::setHealth(double health)   {
    if (health < 0) {
        initializeHealth();
    } else {
        this->health = health;
    }
}

void Godzilla::setPower(double power)    {
    if (power < 0)  {
        initializePower();
    } else {
        this->power = power;
    }
}

string Godzilla::getName()    {
    return name;
}

double Godzilla::getHealth()    {
    return health;
}

double Godzilla::getPower()    {
    return power;
}