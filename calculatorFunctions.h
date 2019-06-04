//
// Created by Jarod Spencer1 on 2019-02-18.
//

#ifndef A4_CALCULATORFUNCTIONS_H
#define A4_CALCULATORFUNCTIONS_H

void menu();
void poundsToKilograms();
double doPoundsToKilograms (double pounds); //could be passed by reference
void feetToMeters();
double doFeetToMeters (double feet); //could be passed by reference
void bodyMassIndex();
double doBodyMassIndex (double kilograms, double meters);
void compoundInterest();
double doCompoundInterest (double principal, double interestRate, double frequency, double time);

#endif //A4_CALCULATORFUNCTIONS_H
