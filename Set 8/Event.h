//
// Created by Jarod Spencer1 on 2019-04-24.
//

#ifndef L8F_EVENT_H
#define L8F_EVENT_H

#include "Date.h";

class Event {
public:
    Event();
    Event(Date myDate, string eventTitle, string eventLocation);
    void setEventDate(Date &myDate);
    void setEventTitle();
    void setEventLocation();
    string getEventDate();
    string getEventTitle();
    string getEventLocation();
    string printEvent();
private:
    Date eventDate;
    string eventTitle;
    string eventLocation;
};


#endif //L8F_EVENT_H
