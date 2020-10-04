#include <iostream>
#include <limits>
#include "functions.h"
#include "functions.cpp"

using std::cout, std::cin, std::endl;

// call this function to reset cin to a good state
void reset_cin();

int main() {
    // TODO(student): print prompt for input
    cout << "Enter numbers 0 < a <= b <= 10000: ";

    // TODO(student): read the numbers from standard input
    int a, b;
    cin >> a >> b;
    // TODO(student): validate input (and reprompt on invalid input)
    while (!is_valid_range(a, b)) {
        reset_cin();
        cout << "Invalid input" << endl;
        cout << "Enter numbers 0 < a <= b <= 10000: ";
        cin >> a >> b;
    }
    // TODO(student): compute and display solution
    cout << "There are " << count_valid_numbers(a, b) << " valid numbers between " << a << " and " << b << endl;
    return 0;
}

void reset_cin() {
    // clear the stream state flags
    cin.clear();
    // clear the stream buffer up to the first newline character
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
