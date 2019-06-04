//
// Created by Jarod Spencer1 on 2019-04-24.
//

#include <iostream>
#include <string>

using namespace std;

#include "Date.h"

Date::Date() {
    month = 12;
    day = 30;
    year = 1950;
    setDate(this->month, this-> day, this->year);
    cout << "Bjarne Stroustrup's birthday!!! Yayy!" << endl;
}

Date::Date(const int &month, const int &day, const int &year) {
    this->month = month;
    this->day = day;
    this->year = year;
    validateDate(this->month, this->day, this->year);
    setDate(this->month, this-> day, this->year);
    cout << "Colorado's birthday!!! Yayy!" << endl;
}

void Date::userSetDate() {
    cin >> month;
    cin >> day;
    cin >> year;
    validateDate(month, day, year);
    setDate(month, day, year);
}

string Date::getDate() const {
    return date;
}

bool Date::isEarlier(const Date &called) const   {
    if (this->year < called.year)   {
        return true;
    } else if (this->year == called.year && this->month < called.month) {
        return true;
    } else if (this->year == called.year && this->month == called.month && this->day < called.day)  {
        return true;
    } else {
        return false;
    }
}

void Date::validateDate(int &month, int &day, int &year) {
    if (month < 1 || month > 12)    {
        month = 12;
    }
    if (day < 1 || day > 31)    {
        day = 30;
    }
    if (year < 0)   {
        year = 1950;
    }
}

void Date::setDate(const int &month, const int &day, const int &year) {
    string slash = "/";
    date = to_string(month);
    date.append(slash);
    date.append(to_string(day));
    date.append(slash);
    date.append(to_string(year));
}

