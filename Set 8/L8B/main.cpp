/* CSCI 261: L8B: Protected Godzilla
 *
 * Author: Jarod Spencer
 *
 * Description: Writing getter and setter functions for the godzilla class
 */

#include <iostream>

using namespace std;

#include "Godzilla.h"

int main() {
    double health = 0;
    double power = 0;

    Godzilla godzilla;

    cout << "Enter health and power of Mechagodzilla:" << endl;
    cin >> health;
    cin >> power;

    godzilla.setHealth(health);
    godzilla.setPower(power);

    Godzilla mechaGodzilla("Mechagodzilla", health, power);

    return 0;
}
