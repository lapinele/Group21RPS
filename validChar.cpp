/*********************************************************************
 * Author: Samantha Tone
 * Date: 11/1/2017
 * Description: Implementation file for input validation
*********************************************************************/
#include "validChar.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

char validChar(string strIn, char arrIn[], int arrSize) {
    bool loopEnder = true;
    char validatedChar;

    do {
        // resets loopEnder to true, so it will flip to false if not
        // all conditions are met
        loopEnder = true;

        // if the strIn.length is not a single char
        if (strIn.length() > 1) {
            // flip our bool to false to continue loop
            loopEnder = false;
            // ask user for new input
            cout << "String entered is too long. Please try again."
                 << endl;
            getline(cin, strIn);
        } else {
            // set this as false before for loop, so we know if it
            // gets flipped back to true
            loopEnder = false;
            for (int i = 0; i < arrSize; i++) {
                // if the char in strIn is equal to the char at
                // position i of arrIn
                if (strIn[0] == arrIn[i]) {
                    // flips to a true loopEnder bool
                    loopEnder = true;
                    // assigns the matching char to our validatedChar
                    validatedChar = arrIn[i];
                }
            }
            // if the loopEnder is never flipped in the for loop,
            // we know that it does fit the available chars
            if (loopEnder == false) {
                // ask user for new input
                cout << "String entered is not one of the specified char options. Please try again."
                     << endl;
                getline(cin, strIn);
            } else {
                // breaks out of do/while loop
                break;
            }

        }
    } while (loopEnder == false);

    return validatedChar;
}