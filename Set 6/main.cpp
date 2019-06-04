/* CSCI 261: L6B: Vector of Words
 *
 * Author: Jarod Spencer
 *
 * Description: Splitting a user-entered string into a vector of its words
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string userInput;
    vector<string> words;

    cout << "Hey! Witness my first vector mojo!" << endl;
    cout << "Enter a sentence: ";
    getline(cin, userInput);

    istringstream sentence(userInput);

    while (!sentence.eof()){
        string word;
        sentence >> word;
        words.push_back(word);
    }

    cout << "\n\nSo awesome! You entered " << words.size() << " words. They are:" << endl;

    int counter = 1;
    for(string word: words){
        cout << counter << ": " << word << endl;
        ++counter;
    }

    cout << "The first word is: " << words[0] << endl;
    cout << "The last word is: " << words[words.size() - 1] << endl;

    cout << "Gaze at my awesome." << endl;

    return 0;
}