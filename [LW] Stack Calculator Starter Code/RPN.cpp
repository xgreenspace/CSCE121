#define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;

#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

using std::cin, std::cout, std::endl, std::string;

int main() {
    Stack numbers;
    string input;
    double number = 0;
    double result = 0;

    double num1 = 0;
    double num2 = 0;

    bool quit = false;

    //Get initial string
    cin >> input;

    //Use while loop to check if there is a valid input
   while(input != "=") {
       // Check if first character is '.' or digit
       if (isdigit(input.front()) || input.front() == '.') {
           number = stod(input);
           push(numbers, number);

       } else {
           num1 = pop(numbers);
           // DEBUG(num1);
           num2 = pop(numbers);
           // DEBUG(num2);

           switch (input.front()) {
                case '+':
                    // cout << "Add" << endl;
                    number = num2 + num1;
                    break;
                case '-':
                    // cout << "Sub" << endl;
                    number = num2 - num1;
                    break;
                case '/':
                    // cout << "Divide" << endl;
                    number = num2 / num1;
                    break;
                case '*':
                    // cout << "Multiply" << endl;
                    number = num2 * num1;
                    break;
                default:
                    cout << "[ERROR] invalid operator: " << input << endl;
                    input = "=";
                    quit = true;
                    break;

           }
           push(numbers, number);
        }

        if (input != "=") {
            cin >> input;
        }
        
    }

    if (!quit) {
        result = pop(numbers);
        cout << result << endl;
    }

    delete[] numbers.A;
    
}