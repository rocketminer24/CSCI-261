/* CSCI 261: L8E: Cordial Godzilla vs. Mechagodzilla
 *
 * Author: Jarod Spencer
 *
 * Description: Writing a greet function to have one object greet another.
 */

#include <iostream>

using namespace std;

#include "Godzilla.h"

int main() {
    srand(time(0));
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

    //godzilla greets mechaGodzilla
    godzilla.greet(mechaGodzilla);

    //godzilla attacks mechaGodzilla once
    godzilla.attack(mechaGodzilla);

    //mechaGodzilla attacks godzilla until godzilla is vanquished
    cout << endl;
    while (godzilla.getHealth() > 0)    {
        mechaGodzilla.attack(godzilla);
    }

    return 0;
}