//
// Created by Jarod Spencer1 on 2019-04-01.
//

#ifndef A6_FUNCTIONS_H
#define A6_FUNCTIONS_H

#include "wordCountStruct.h"
#include "letterCountStruct.h"

using namespace std;

void getWords(string&, vector<WordCount>&);
void printWordsAndCounts(string&, vector<WordCount>&);
void storeInWordVector(const string&, vector<WordCount>&);
void upperWord(string&);
void deletePunctuation(string&);
void sortWordVector(vector<WordCount>&);
void printVectorInfo(const vector<WordCount>&);
void printMostFrequentWord(const vector<WordCount>&);
void printLeastFrequentWord(const vector<WordCount>&);
void printLettersAndPercents(const vector<WordCount>&);

#endif //A6_FUNCTIONS_H
