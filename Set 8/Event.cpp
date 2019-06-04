//
// Created by Jarod Spencer1 on 2019-04-24.
//

#include <iostream>
#include <string>

using namespace std;

#include "Event.h"

Event::Event() {
    eventTitle = "Bjarne Stroustrup's Birthday";
    eventLocation = "Aarhus, Denmark";
}

Event::Event(Date myDate, string eventTitle, string eventLocation) {
    this->eventDate = myDate;
    this->eventTitle = eventTitle;
    this->eventLocation = eventLocation;
}

void Event::setEventDate(Date &newDate)  {
    this->eventDate = newDate;
}

void Event::setEventTitle() {
    string newTitle;
    getline(cin, newTitle);
    this->eventTitle = newTitle;
}

void Event::setEventLocation()   {
    string newLocation;
    getline(cin, newLocation);
    this->eventLocation = newLocation;
}

string Event::getEventDate()    {
    return eventDate.getDate();
}

string Event::getEventTitle()  {
    return eventTitle;
}

string Event::getEventLocation()   {
    return eventLocation;
}

string Event::printEvent()  {
    cout << eventDate.getDate() << ": " << eventTitle << " (" << eventLocation << ")." << endl;
}