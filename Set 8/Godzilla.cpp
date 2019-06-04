//
// Created by Jarod Spencer1 on 2019-04-22.
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

string Godzilla::attack(Godzilla& attacked)   {
    if (attacked.getHealth() <= this->power)   {
        attacked.setHealth(0);
        cout << attacked.getName() << " has been vanquished." << endl;
        return "vanquished";
    } else {
        double attackedHealth = attacked.getHealth() - this->power;
        cout << this->name << " attacks " << attacked.getName() << "." << endl;
        attacked.setHealth(attackedHealth);
        return "damaged";
    }
}