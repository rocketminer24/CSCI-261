/* CSCI 261: L7C: Translate the Moosage
 *
 * Author: Jarod Spencer
 *
 * Description: Reading a ciphered text file and writing a deciphered text file
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream cipher("secretMessage.txt");
    char c = 'a';
    int switchNum = 0;

    if (cipher.fail())  {
        cerr << "Error opening input file";
        return 1;
    }

    ofstream deciphered("decipheredMessage.txt");

    while (!cipher.eof())   {
        cipher.get(c);
        if (c == '~')   {
            switchNum = 0;
        } else if (c == '\n')   {
            switchNum = 1;
        } else {
            switchNum = 2;
        }

        switch (switchNum)  {
            case 0:
                c = ' ';
                break;
            case 1:
                break;
            case 2:
                c++;
                break;
        }

        if (deciphered.fail())  {
            cout << "Error opening output file" << endl;
            return 1;
        }

        deciphered << char(c);
    }

    cipher.close();
    deciphered.close();

    return 0;
}
