/* CSCI 261: A6: Word and Letter Counts
 *
 * Author: Jarod Spencer
 *
 * Description: Count unique words and determine letter frequencies given
 *              user inputted sentances using vectors, arrays, strings, and structs.
 */

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    cout << "Enter as many sentences as you would like. Then enter \"I'm done!\" "
            "to indicate you are finished." << endl;

    string sentence;
    vector<WordCount> wordVector;

    getWords(sentence, wordVector);

    printWordsAndCounts(sentence, wordVector);

    printLettersAndPercents(wordVector);

    return 0;
}
