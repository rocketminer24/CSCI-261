//
// Created by Jarod Spencer1 on 2019-04-23.
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

void Godzilla::setName(const string &name)   {
    this->name = name;
}

void Godzilla::setHealth(const double &health)   {
    if (health < 0) {
        initializeHealth();
    } else {
        this->health = health;
    }
}

void Godzilla::setPower(const double &power)    {
    if (power < 0)  {
        initializePower();
    } else {
        this->power = power;
    }
}

string Godzilla::getName() const   {
    return name;
}

double Godzilla::getHealth() const   {
    return health;
}

double Godzilla::getPower() const   {
    return power;
}

string Godzilla::attack(Godzilla &attacked)   {
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

void Godzilla::greet(const Godzilla &greeted) const {
    cout << name << " bows to " << greeted.getName() << "." << endl << endl;
}