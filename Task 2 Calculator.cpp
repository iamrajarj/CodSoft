//Sachal Raja Task02
#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation, option;

    cout << "\t\tSimple Calculator" << endl;
    
    do{
        cout << "Enter first number: ";
        cin >> num1;
    
        cout << "Enter second number: ";
        cin >> num2;
    
        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;
    
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    continue;
                }
                break;
            default:
                cout << "Invalid operation. Please enter +, -, *, or /." << endl;
        }
        cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
        
        cout<<"Do you want to perform another calculation, Y/N? ";
        cin>>option;
    
    } while (option != 'N');

    return 0;
}
