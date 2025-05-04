#include <iostream>

using namespace std;

int main()
{
    // Accounts initialization
    int bankAccounts[10];
    for (int account=0;account<10;account++){
        bankAccounts[account] = 500*account;
    }

    cout << "Welcome to the bank system application." << endl
         << "Available commands: 'help', 'select', 'accounts', 'moneysum', 'exit'." << endl;
    string userInput = "";
    while (true){
        cout << "Input a command: ";
        cin >> userInput;
        if (userInput == "help"){
            cout << "Available commands: 'help', 'select', 'accounts', 'moneysum', 'exit'." << endl
                 << "select - input which bank account you wish to select and program shows" << endl
                 << "\tbalance of said account, then gives the option to deposit or withdraw money." << endl
                 << "accounts - shows balance of every owned bank account" << endl
                 << "moneysum - shows the sum of money from all owned bank accounts" << endl
                 << "exit - closes the program" << endl << endl;
        } else if (userInput == "select"){
            cout << "Enter which bank account you want to select (1 - 10)" << endl;
            int selectedAccount = 0;
            int moneyAmount = 0;
            cin >> selectedAccount;
            if (selectedAccount < 1 || selectedAccount > 10){
                cout << "Selected account does not exist!";
                continue;
            }
            cout << "Selected account's balance: $" << bankAccounts[selectedAccount-1] << endl
                 << "Would you like to withdraw or deposit the money?" << endl
                 << "Type 'withdraw' or 'deposit': " ;
            cin >> userInput;
            if (userInput == "withdraw"){
                cout << "Enter how much money do you want to withdraw: ";
                cin >> moneyAmount;
                if (moneyAmount > bankAccounts[selectedAccount - 1]){
                    cout << "Not enough money in the account! Returning to the main command select." << endl;
                    continue;
                }
                bankAccounts[selectedAccount - 1] -= moneyAmount;
            }
            else if (userInput == "deposit"){
                cout << "Enter how much money do you want to deposit: ";
                cin >> moneyAmount;
                if (moneyAmount < 1){
                    cout <<  "Cannot deposit that amount of money! Returning to the main command select." << endl;
                    continue;
                }
                bankAccounts[selectedAccount - 1] += moneyAmount;
            }
            else {
                cout << "No such command! Returning to the main command select." << endl;
            }
        } else if (userInput == "accounts") {
            cout << "Money amount in each of the accounts:" << endl;
            for (int accountNumber = 1; accountNumber < 11; accountNumber++){
                cout << "Account #" << accountNumber << ": $" << bankAccounts[accountNumber-1] << endl;
            }
        } else if (userInput == "moneysum") {
            int moneySum = 0;
            for (int moneyAmount: bankAccounts) {
                moneySum += moneyAmount;
            }
            cout << "Money sum from all of the owned accounts: $" << moneySum << endl;
        } else if (userInput == "exit") {
            break;
        } else {
            cout << "Invalid command! Try 'help' to see the list of available commands" << endl;
        }
    }
}
