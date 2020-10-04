# include "functions.h"
# include "functions.cpp"
# include <iostream>

using std::cout, std::cin, std::endl;


int main() {
    int number, digit, count;
    bool test;

    //Testing count_digital_occurances
    
    cout << "Enter test value: ";
    cin >> number;

    for (int i = 0; i < 10; i++) {
        count = count_digit_occurrences(number, i);

        cout << endl << count << endl;
    }

    cout << "This is odd since 8675309 as one 9. -> " << count_digit_occurrences(8675309, 9) << endl;   

    //Testing has_repeated_digits

    // cout << "Enter test value: ";
    // cin >> number;

    // test = has_repeated_digits(number);

    // cout << endl << test << endl;
}