/* CSCI 261: L8F: Calender Events
 *
 * Author: Jarod Spencer
 *
 * Description:
 */

#include <iostream>

using namespace std;

#include "Date.h"
#include "Event.h"

int main() {
    //Declares three Date class objects, two parameterized, one not
    Date importantDate1;
    Date importantDate2(8, 1, 1876);
    Date testDate(1, 28, 2000);

    //Tests the userSetDate getDate Date class functions
    importantDate1.userSetDate();
    cout << importantDate1.getDate() << endl << endl;

    //Tests the isEarlier Date class function
    cout << importantDate2.isEarlier(importantDate1) << endl << endl;

    //Declares two Event class objects, one parameterized with importantDate2, one not
    Event importantEvent1;
    Event importantEvent2(importantDate2, "Colorado Gains Statehood", "Washington D.C.");

    //Tests setEvent Event class data functions and getEvent data functions
    importantEvent1.setEventDate(testDate);
    importantEvent1.setEventTitle();
    importantEvent1.setEventLocation();
    cout << importantEvent1.getEventDate() << endl;
    cout << importantEvent1.getEventTitle() << endl;
    cout << importantEvent1.getEventLocation() << endl << endl;

    //Tests print Event class function
    importantEvent2.printEvent();

    return 0;
}
