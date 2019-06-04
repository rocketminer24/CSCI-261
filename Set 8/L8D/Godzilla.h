//
// Created by Jarod Spencer1 on 2019-04-22.
//

#ifndef L8D_GODZILLA_H
#define L8D_GODZILLA_H


class Godzilla {
public:
    Godzilla();
    Godzilla(string name, double health, double power);
    void setName(string name);
    void setHealth(double health);
    void setPower(double power);
    string getName();
    double getHealth();
    double getPower();
    string attack(Godzilla&);
private:
    void initializeHealth();
    void initializePower();
    string name;
    double health;
    double power;
};


#endif //L8D_GODZILLA_H
