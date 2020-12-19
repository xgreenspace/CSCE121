// string_calculator.cpp
#include <iostream>
#include "my_string.h"
#include "./string_calculator.h"

using std::cout, std::endl;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): put your existing implementation here
    // Implimenting a switch case statment. char digit will be converted to its ASCII value
    switch (digit) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            throw std::invalid_argument("Char must be an integer between 0 and 9");
    }
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): put your existing implementation here
    // Same thing as digit_to_decimal but reversed
    switch (decimal) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            throw std::invalid_argument("Integer must be an integer between 0 and 9");
    }
}

my_string trim_leading_zeros(const my_string& num) {
    // TODO(student): put your existing implementation here
    bool isNegative = false;
    my_string str = num;
    // Iterate through the string until the end is reached, leading zeros are removed, or a non-zero integer is encountered. Ignores minus signs.
    for (size_t i = 0; i < str.size(); i++) {
        if (str.at(i) == '-') {
            isNegative = true;
            continue;
        } else if (str.at(i) == '0') {
            // Breaks the loop if string is "0" or "-0"
            if (str.size() == 2 && isNegative) {
                str.erase(i-1, 1);
                break;
            } else if (str.size() == 1) {
                break;
            }
            str.erase(i, 1);
            i--;
        } else {
            break;
        }
    }
    return str;
}

my_string add(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation here
    trim_leading_zeros(lhs);
    trim_leading_zeros(rhs);
    return "";
}

my_string subtract(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation 
    trim_leading_zeros(lhs);
    trim_leading_zeros(rhs);
    return "";
}

my_string multiply(const my_string& lhs, const my_string& rhs) {
    // TODO(student): put your existing implementation here
    trim_leading_zeros(lhs);
    trim_leading_zeros(rhs);
    return "";
}
