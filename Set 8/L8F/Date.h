//
// Created by Jarod Spencer1 on 2019-04-24.
//

#ifndef L8F_DATE_H
#define L8F_DATE_H


class Date {
    public:
        Date();
        Date(const int &month, const int &day, const int &year);
        void userSetDate();
        string getDate() const;
        bool isEarlier(const Date&) const;
    private:
        void validateDate(int &month, int &day, int &year);
        void setDate(const int &month, const int &day, const int &year);
        int month;
        int day;
        int year;
        string date;
};


#endif //L8F_DATE_H
