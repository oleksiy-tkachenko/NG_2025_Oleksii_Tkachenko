#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a sentence and the program will count the number of words!" << endl;
    string userSentence = "";
    getline(cin, userSentence, '\n');
    char previousLetter = ' ';
    int wordCount = 0;
    for (char letter: userSentence){
        bool isCurrentLetterInAlphabet = (((int)letter >= (int)'a' && (int)letter <= (int)'z') || ((int)letter >= (int)'A' && (int)letter <= (int)'Z'));
        bool isPreviousLetterNotInAlphabet = ((int)previousLetter < (int)'A' || ((int)previousLetter > (int)'Z' && (int)previousLetter < (int)'a') || (int)previousLetter > (int)'z');
        if( isCurrentLetterInAlphabet && isPreviousLetterNotInAlphabet ){
            wordCount++;
        }
        previousLetter = letter;
    }
    cout << "Words in a sentence: " << wordCount << endl;
    return 0;
}
