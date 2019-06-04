//
// Created by Jarod Spencer1 on 2019-04-23.
//

#ifndef L8E_GODZILLA_H
#define L8E_GODZILLA_H


class Godzilla {
public:
    Godzilla();
    Godzilla(string name, double health, double power);
    void setName(const string &name);
    void setHealth(const double &health);
    void setPower(const double &power);
    string getName() const;
    double getHealth() const;
    double getPower() const;
    string attack(Godzilla &);
    void greet(const Godzilla &) const;
private:
    void initializeHealth();
    void initializePower();
    string name;
    double health;
    double power;
};


#endif //L8E_GODZILLA_H
