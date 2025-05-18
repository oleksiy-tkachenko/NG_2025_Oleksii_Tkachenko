#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a text and the program will output the consonants/vowels ratio in said text!" << endl;
    string userSentence = "";
    getline(cin, userSentence, '\n');
    int consonantsCount = 0, vowelsCount = 0;
    for (unsigned int symbolIndex = 0; symbolIndex < userSentence.length(); symbolIndex++)
    {
        char symbol = tolower(userSentence[symbolIndex]);
        if ( isalpha(symbol) ){
            if (symbol == 'a' || symbol == 'o' || symbol == 'u'
                || symbol == 'i' || symbol == 'e'){
                vowelsCount++;
            } else if (symbol == 'y'){
                if (symbolIndex == 0){
                    consonantsCount++;
                } else if (!isalpha(userSentence[symbolIndex-1])){
                    consonantsCount++;
                } else {
                    vowelsCount++;
                }
            } else {
                consonantsCount++;
            }
        }
    }
    int total = consonantsCount + vowelsCount;
    if(total == 0){
        cout << "No vowels or consonants in the text!";
        return 0;
    }
    double consonantsPercentage = consonantsCount/(double)total*100;
    double vowelsPercentage = vowelsCount/(double)total*100;
    cout << "Consonants/vowels ration in the text: " << setprecision(4)
         << consonantsPercentage << "%/" << vowelsPercentage << "%" << endl;
    return 0;
}
