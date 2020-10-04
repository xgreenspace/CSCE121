#include <iostream> 
#include <string>
#include <limits>
#include "./string_calculator.h"
#include "string_calculator.cpp"

using std::cout, std::endl, std::cin, std::string;

// This program is meant to run the important functions with test cases

int main() {
    string a;
    string b;

    cout << "Enter 'stop' to end program." << endl;
    
    while(1) {
        std::getline(cin, a);
        if (a == "stop") {
            cout << "Process Ended." << endl;
            break;
        }
        std::getline(cin, b);

        

        

        cout << add(a, b) << endl;
        cout << "=========================" << endl;
    }
    

    
}