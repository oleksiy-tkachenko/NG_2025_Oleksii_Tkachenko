#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int userInputs[5] = {0, 0, 0, 0, 0};
    cout << "Enter five positive numbers, separating them by pressing enter or space." << endl;
    cin >> userInputs[0] >> userInputs[1] >> userInputs[2] >> userInputs[3] >> userInputs[4];
    for(int row = 0; row < max({userInputs[0], userInputs[1], userInputs[2], userInputs[3], userInputs[4]}); row++){
        for (int column = 0; column < 5; column ++){
            if (userInputs[column] > row){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
