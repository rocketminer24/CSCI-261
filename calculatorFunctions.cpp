//
// Created by Jarod Spencer1 on 2019-02-18.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "calculatorFunctions.h"

using namespace std;

//menu function
void menu() {
    int choice = 0;

    //menu function repeats as long as previous user choice was not to quit the program
    do {
        //user chooses which calculation to perform
        cout << "\nChoose which of the following calculations you want to preform or quit." << endl;
        cout << "1) Convert pounds to kilograms" << endl;
        cout << "2) Convert feet to meters" << endl;
        cout << "3) Calculate your BMI" << endl;
        cout << "4) Calculate compound interest" << endl;
        cout << "5) Quit" << endl << endl;

        cout << "Choice (enter 1, 2, 3, 4, or 5): ";
        cin >> choice;

        //if choice is not 1, 2, 3, 4, or 5, user is asked to re-enter their choice
        while (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please choose again: ";
            cin >> choice;
        }

        //function decides which calculation to perform based on user choice and calls appropriate
        //calculation function
        switch (choice) {
            case 1:
                poundsToKilograms();
                break;

            case 2:
                feetToMeters();
                break;

            case 3:
                bodyMassIndex();
                break;

            case 4:
                compoundInterest();
                break;

            case 5:
                cout << "You chose to quit. Come back soon!" << endl;
                break;

            default:
                break;
        }
    } while (choice != 5);
}

//function asks user to input the number of pounds they wish to convert to kilograms and calls the
//actual conversion function
void poundsToKilograms() {
    int pounds = 0;

    cout << "\nEnter number of pounds: ";
    cin >> pounds;

    cout << pounds << " pounds is approximately " << doPoundsToKilograms(pounds) << " kilograms." << endl;
}

//actual pounds to kilograms conversion function
double doPoundsToKilograms(double pounds) {
    return (pounds * 0.454);
}

//function asks user to input the number of feet they wish to convert to meters and calls the
//actual conversion function
void feetToMeters() {
    double feet = 0;

    cout << "\nEnter number of feet: ";
    cin >> feet;

    cout << feet << " feet is approximately " << doFeetToMeters(feet) << " meters." << endl;
}

//actual feet to meters conversion function
double doFeetToMeters(double feet) {
    return (feet * 0.3048);
}

//function asks user to input their height and weight so as to calculate their BMI and calls the
//actual BMI calculation function
void bodyMassIndex() {
    double height = 0;
    double weight = 0;

    cout << "\nEnter your height (in feet) and weight (in pounds): ";
    cin >> height;
    cin >> weight;

    cout << "Your BMI is " << doBodyMassIndex(height, weight) << endl;
}

//actual BMI calculation function
double doBodyMassIndex(double height, double weight) {
    return (doPoundsToKilograms(weight) / pow(doFeetToMeters(height), 2));
}

//function asks user to input necessary data to calculate the effect of compound interest on an
//account and calls the actual calculation function
void compoundInterest() {
    double principal = 0;
    double interestRate = 0;
    double frequency = 0;
    double time = 0;

    cout << "\nEnter pricipal amount: ";
    cin >> principal;
    cout << "Enter interest rate (percent): ";
    cin >> interestRate;
    cout << "Enter number of times per year interest is compounded: ";
    cin >> frequency;
    cout << "Enter number of years to be calculated for: ";
    cin >> time;

    cout << "\nAfter " << time << " years, with a principal of $" << principal << ", an interest ";
    cout << "rate of " << interestRate << " percent, and\ncompounded " << frequency << " times per year,";
    cout << " you will have $" << doCompoundInterest (principal, interestRate, frequency, time);
    cout << " in your account." << endl;
}

//actual compound interest calculation function
double doCompoundInterest (double principal, double interestRate, double frequency, double time)  {
    return (principal * pow((1 + ((interestRate / 100) / frequency)), (frequency * time)));
}