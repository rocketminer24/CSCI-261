/* CSCI 261: L8D: Godzilla vs. Mechagodzilla
 *
 * Author: Jarod Spencer
 *
 * Description: Writing an attack function to have one object alter another.
 */

#include <iostream>

using namespace std;

#include "Godzilla.h"

int main() {
    double health = 0;
    double power = 0;

    //declare godzilla object
    Godzilla godzilla;

    cout << "Enter health and power of Mechagodzilla:" << endl;
    cin >> health;
    cin >> power;
    cout << endl;

    //set health and power of godzilla
    godzilla.setHealth(health);
    godzilla.setPower(power);

    //declare mechaGodzilla object
    Godzilla mechaGodzilla("Mechagodzilla", health, power);

    //godzilla attacks mechaGodzilla once
    godzilla.attack(mechaGodzilla);

    cout << endl;
    while (godzilla.getHealth() > 0)    {
        mechaGodzilla.attack(godzilla);
    }

    return 0;
}