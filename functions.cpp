//
// Created by Jarod Spencer1 on 2019-04-01.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "functions.h"
#include "wordCountStruct.h"
#include "letterCountStruct.h"

using namespace std;

void getWords(string &sentence, vector<WordCount> &wordVector) {
    getline(cin, sentence);

    //loop calls function to store the next sentence in vector and increment count of duplicate words,
    //  then takes in next sentence
    while (sentence != "I'm done!") {
        storeInWordVector(sentence, wordVector);
        getline(cin, sentence);
    }
}

void printWordsAndCounts(string &sentence, vector<WordCount> &wordVector) {
    if (!wordVector.empty()) {

        //vector is sorted alphabetically using function
        sortWordVector(wordVector);

        printVectorInfo(wordVector);

        printMostFrequentWord(wordVector);

        printLeastFrequentWord(wordVector);
    }


}

//function takes in sentence and stores new words in the word vector or increments count of duplicate words
void storeInWordVector(const string &sentence, vector<WordCount> &wordVector) {
    WordCount word;//struct with word and count for word in vector

    istringstream newWord(sentence);//will allow me to pull words from input string

    while (!newWord.eof()) {
        bool incCount = false;//bool to check if word is already in vector, count should be incremented
        string tempWordHolder;

        newWord >> tempWordHolder;//takes next word in sentence and places it in a temporary holding string

        upperWord(tempWordHolder);

        deletePunctuation(tempWordHolder);

        //loop determines if next word in sentence is a duplicate or not
        for (int k = 0; k < wordVector.size(); ++k) {
            if (tempWordHolder == wordVector.at(k).word) {
                incCount = true;
                wordVector.at(k).count += 1;
                break;
            } else {
                continue;
            }
        }

        //if new word was duplicate, increments count. else uses push_back to insert new word into vector
        if (!incCount) {
            word.word = tempWordHolder;
            word.count = 1;//assigns count for that word to 1 for first occurrence
            wordVector.push_back(word);
        }
    }
}

void upperWord(string &tempWordHolder)  {
    for (int i = 0; i < tempWordHolder.length(); ++i)   {
        tempWordHolder[i] = toupper(tempWordHolder[i]);
    }
}

void deletePunctuation(string &tempWordHolder)  {
    for (int i = 0; i < tempWordHolder.length(); ++i)   {
        if (ispunct(tempWordHolder[i])) {
            tempWordHolder.erase(i, 1);
        }
    }
}

//function sorts words in vector into alphabetical order
void sortWordVector(vector<WordCount> &wordVector) {

    WordCount temp;

    for (int i = 0; i < wordVector.size() - 1; ++i) {
        int indexHighAlph = i;//int used to find index of highest alphabetical word

        //
        for (int j = i + 1; j < wordVector.size(); ++j) {
            if (wordVector[j].word < wordVector[indexHighAlph].word) {
                indexHighAlph = j;
            }
        }

        temp.word = wordVector[i].word;
        temp.count = wordVector[i].count;
        wordVector[i] = wordVector[indexHighAlph];
        wordVector[indexHighAlph].word = temp.word;
        wordVector[indexHighAlph].count = temp.count;
    }
}

//function prints words
void printVectorInfo(const vector<WordCount> &wordVector) {
    cout << "\nWord Counts" << endl;
    cout << "-----------" << endl;

    for (int i = 0; i < wordVector.size(); ++i) {
        cout << "#" << setw(2) << right << i + 1;
        cout << " " << setw(7) << left << wordVector.at(i).word;
        cout << setw(3) << right << wordVector.at(i).count << endl;
    }
}

void printMostFrequentWord(const vector<WordCount> &wordVector)   {
    int mostFrequentIndex = 0;

    for (int i = 1; i < wordVector.size(); ++i) {
        if (wordVector.at(i).count > wordVector.at(mostFrequentIndex).count)    {
            mostFrequentIndex = i;
        }
    }

    cout << "\nMost Frequent:  ";
    cout << setw(9) << left << wordVector.at(mostFrequentIndex).word;
    cout << setw(1) << right << "(" << setw(2) << wordVector.at(mostFrequentIndex).count << ")" << endl;
}

void printLeastFrequentWord(const vector<WordCount> &wordVector)   {
    int leastFrequentIndex = 0;

    for (int i = 1; i < wordVector.size(); ++i) {
        if (wordVector.at(i).count < wordVector.at(leastFrequentIndex).count)    {
            leastFrequentIndex = i;
        }
    }

    cout << "Least Frequent: ";
    cout << setw(9) << left << wordVector.at(leastFrequentIndex).word;
    cout << setw(1) << right << "(" << setw(2) << wordVector.at(leastFrequentIndex).count << ")" << endl;
}

void printLettersAndPercents(const vector<WordCount> &wordVector)  {
    int arraySize = 26;
    LetterCount lettersAndPercents[arraySize];

    //initialized all array letter elements to appropriate letter alphabetically
    int asciiLetter = 65;
    for (int i = 0; i < arraySize; ++i) {
        char englishLetter = static_cast<char> (asciiLetter);
        lettersAndPercents[i].letter = englishLetter;
        ++asciiLetter;
    }

    //initializes all array count elements to be zero
    for (int i = 0; i < arraySize; ++i) {
        lettersAndPercents[i].count = 0;
    }

    //fist for loop iterates through words (strings) in wordVector
    //second for loop causes each word to be checked the number of times it occurs based on its count in wordVector
    //third for loop iterates through individual letters in each word in wordVector
    //fourth for loop iterates through each letter currently in array checking it against the current
    //  letter of the current word in wordVector
    for (int i = 0; i < wordVector.size(); ++i) {
        for (int j = 0; j < wordVector.at(i).count; ++j)    {
            for (int k = 0; k < wordVector.at(i).word.length(); ++k)    {
                for (int l = 0; l < arraySize; ++l) {
                    if (wordVector.at(i).word[k] == lettersAndPercents[l].letter)   {
                        lettersAndPercents[l].count += 1;
                        break;
                    }
                }
            }
        }
    }

    //loop determines sum of all letters in user input (i.e. sums the counts)
    int countsSum = 0;
    for (int i = 0; i < arraySize; ++i) {
        countsSum += lettersAndPercents[i].count;
    }

    cout << "\nLetter Counts" << endl;
    cout << "-------------" << endl;

    //FIXME not aligned properly. probably something to do with the right command
    //for loop calculates percent occurrence of each letter and prints it with the letter
    for (int i = 0; i < arraySize; ++i) {
        double percent = 100.000 * lettersAndPercents[i].count / countsSum;
        cout << lettersAndPercents[i].letter << ": " << right << setw(5) << fixed << setprecision(3) << percent << "%" << endl;
    }

    int mostFrequentIndex = 0;
    int leastFrequentIndex = 0;

    //finds index of most frequent letter
    for (int i = 0; i < arraySize; ++i) {
        if (lettersAndPercents[i].count > lettersAndPercents[mostFrequentIndex].count)    {
            mostFrequentIndex = i;
        }
    }

    //finds index of least frequent letter
    for (int i = 1; i < arraySize; ++i) {
        if (lettersAndPercents[i].count < lettersAndPercents[leastFrequentIndex].count)    {
            leastFrequentIndex = i;
        }
    }

    cout << "\nMost Frequent:  ";
    cout << setw(9) << left << lettersAndPercents[mostFrequentIndex].letter;
    cout << setw(1) << right << "(" << setw(2) << lettersAndPercents[mostFrequentIndex].count << ")" << endl;

    cout << "Least Frequent: ";
    cout << setw(9) << left << lettersAndPercents[leastFrequentIndex].letter;
    cout << setw(1) << right << "(" << setw(2) << lettersAndPercents[leastFrequentIndex].count << ")" << endl;
}