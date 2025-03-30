#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Welcome to the calculator!\n"
            "Write down a desired operation to proceed, or help to see available options\n"
            "Available operations: +, -, *, /, ^, sqrt\n\n" << endl;

    while(true){
        string option = "";
        cin >> option;
        if (option != "+" && option != "-" && option != "*" && option != "/" && option != "^" && option != "sqrt" && option != "help"){
            cout << "Exiting the calculator...\n";
            return 0;
        }
        else if (option == "help"){
            cout << "Available options: +, -, *, /, ^, sqrt\n\n";
            continue;
        }

        float numberA = 0;
        cout << "Enter the first number: ";
        cin >> numberA;

        float numberB = 0;
        cout << "Enter the second number(behaves differently on '^' and 'sqrt' options): ";
        cin >> numberB;

        float result = 0;
        if (option == "+"){
            result = numberA + numberB;
        }
        else if (option == "-"){
            result = numberA - numberB;
        }
        else if (option == "*"){
            result = numberA * numberB;
        }
        else if (option == "/"){
            if (numberB == 0){
                cout << "Result: infinity woOoOoOoOoo...\n";
                continue;
            }
            result = numberA / numberB;
        }
        else if (option == "^"){
            result = pow(numberA, numberB);
        }
        else if (option == "sqrt"){
            result = sqrt(numberA);
        }

        cout << "Result: " << result << endl;
    }
}
