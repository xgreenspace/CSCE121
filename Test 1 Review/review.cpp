/*
    The purpose of this program is to help me prepare for the upcoming CSCE 121 Exam. 
    This program contains serveral practice problems. 
*/

#include <string>
#include <iostream>
#include <cstring>
#include <cmath>

using std::cout, std::cin, std::endl;

int multiples(int n, int k, int l);
bool triangular_numbers(int n);
bool isNumericPalindrome(int n);

int main() {
    // multiples(6, 5, 2);
    // triangular_numbers(121);
    isNumericPalindrome(123);

    return 0;
}

int multiples(int n, int k, int l) {
    
    int index = 0;
    int number = 1;
    while (index < n) {
        if (number % l == 0) {
            cout << number << " ";
            index++;
            number++;
        } else if (number % k == 0) {
            cout << number << " ";
            index++;
            number++;
        } else {
            number++;
        }
    }

    cout << endl;

    return 0;
}

bool triangular_numbers(int n) {
    if (n < 0) {
        throw std::invalid_argument("Number must be greater than zero.");
    }

    int a = 1;
    int b = 2;
    int c = 3;

    while (a < n / b) {
        if (a * b * c == n) {
            cout << "The number is triangular." << endl;
            return true;
        } else {
            a++;
            b++;
            c++;
        }
    }
    cout << "The number is not triangular." << endl;
    return false;
}


bool isNumericPalindrome(int n) {
    // Using mathematics in code to create a backwards number. If the backwards number is equal in value to the abs of the given interger, then this function will return true.
    n = fabs(n);
    int backwardsNum = 0;

    int multiOfTen = 10;
    int multiOfTen2 = 1;
    while (multiOfTen < n) {
        multiOfTen *= 10;
    }

    while(multiOfTen > 1){
        backwardsNum += ((n % multiOfTen) / multiOfTen2);
        cout << backwardsNum << endl;
        multiOfTen *= 10;
        multiOfTen2 *= 10;
    }
    cout << backwardsNum << endl;
    return false;
}