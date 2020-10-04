#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
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
    // TODO(student): implement
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
    return '\0'; // Null character.
}

string trim_leading_zeros(string num) {
    bool isNegative = false;
    // Iterate through the string until the end is reached, leading zeros are removed, or a non-zero integer is encountered. Ignores minus signs.
    for (int i = 0; i < num.size(); i++) {
        if (num.at(i) == '-') {
            isNegative = true;
            continue;
        } else if (num.at(i) == '0') {
            // Breaks the loop if string is "0" or "-0"
            if (num.size() == 2 && isNegative) {
                num.erase(i-1, 1);
                break;
            } else if (num.size() == 1) {
                break;
            }
            num.erase(i, 1);
            i--;
        } else {
            break;
        }
    }
    return num;
}

string add(string lhs, string rhs) {
    bool lhsIsLarger = false;
    bool rhsIsLarger = false;
    bool lhsIsNegative = false;
    bool rhsIsNegative = false;
    bool carryOver = false;
    bool equalValues = false;

    char charDigit;

    int numDigits;
    int rhsIntDigit;
    int lhsIntDigit;
    int intermediateSum;

    string finalSum = "";
    string zeros = "";
    string rhsTest;
    string lhsTest;
    string largerAbsValue;
    string smallerAbsValue;

    // Should probably strip all extra zeros before I do anything, just in case.
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    // Handles negative numbers and dictates the approach the program will take
    if (lhs.at(0) == '-') {
        lhsIsNegative = true;
    }
    if (rhs.at(0) == '-') {
        rhsIsNegative = true;
    }
    
    // I should figure out which number is larger in absolute value in cases where the strings are the same length.
    if (rhsIsNegative) {
        rhsTest = rhs.substr(1);
    } else {
        rhsTest = rhs;
    }
    if (lhsIsNegative) {
        lhsTest = lhs.substr(1);
    } else {
        lhsTest = lhs;
    }
    
    if (rhsTest.size() == lhsTest.size()) {
        for (int i = 0; i < rhsTest.size(); i++) {
            if (rhsTest.at(i) > lhsTest.at(i)) {
                rhsIsLarger = true;
                break;
            } else if (lhsTest.at(i) > rhsTest.at(i)) {
                lhsIsLarger = true;
                break;
            }
            if (i == rhsTest.size() - 1) {
                equalValues = true;
            }
        }
    } else {
        if (rhsTest.size() > lhsTest.size()) {
            rhsIsLarger = true;
            largerAbsValue = rhs;
            smallerAbsValue = lhs;
        } else {
            lhsIsLarger = true;
            largerAbsValue = lhs;
            smallerAbsValue = lhs;
        }
    }
    // Gets rid of the negative sign
    if (rhsIsNegative) {
        rhs = rhs.substr(1);
    } 
    if (lhsIsNegative) {
        lhs = lhs.substr(1);
    }
    
    //cout << "(0) LHS: " << lhs << " " << "RHS: " << rhs << endl;
    //cout << "LHS Larger: " << lhsIsLarger << " " << "RHS Larger: " << rhsIsLarger << endl;
    // If both numbers are negative, might as well remove the negative sign and treat them as normal. I'll add them back later.
    // If only one of the numbers are negative, I'll send it to the subtract function. It's probably better at handling that.
    if (rhsIsNegative && lhsIsNegative) {
        
    } else if (rhsIsNegative && lhsIsLarger) {
        cout << "I ran (1)" << endl;
        finalSum = subtract(lhs, rhs);
        return finalSum;
    } else if (rhsIsNegative && rhsIsLarger) {
        cout << "I ran (2)" << endl;
        finalSum = subtract(rhs, lhs);
        if (finalSum == "0") {
            return finalSum;
        }
        return finalSum.insert(0, 1, '-');
    } else if (lhsIsNegative && rhsIsLarger) {
        cout << "I ran (3)" << endl;
        finalSum = subtract(rhs, lhs);
        return finalSum;
    } else if (lhsIsNegative && lhsIsLarger) {
        cout << "I ran (4)" << endl;
        finalSum = subtract(lhs, rhs);
        if (finalSum == "0") {
            return finalSum;
        }
        return finalSum.insert(0, 1, '-');
    } else if ((lhsIsNegative ^ rhsIsNegative) && equalValues) {
            return "0";
    }

    // Just need to make sure it subtracts the right number by calling the function in the correct order. 
    // if (lhsIsNegative && !rhsIsNegative) {
    //     subtract(rhs, lhs);
    // } else if (!lhsIsNegative && rhsIsNegative) { // Unused Code
    //     subtract(lhs, rhs);
    // }
    // Adds zeros to both numbers to get them to be the same length, and makes working with them easier
    if (lhs.size() < rhs.size()) {
        for (int i = 0; i < rhs.size() - lhs.size(); i++) {
            zeros.push_back('0');
        }
        lhs.insert(0, zeros);
    } else if (rhs.size() < lhs.size()) {
        for (int i = 0; i < lhs.size() - rhs.size(); i++) {
            zeros.push_back('0');
        }
        rhs.insert(0, zeros);
    }

    rhs.insert(0, "0");
    lhs.insert(0, "0");

    // Sweet, hopefully we can start the actual adding. The plan is to do this coloum by coloum like actual addition. And we're going to handle carryovers.
    numDigits = rhs.size();
    for (int i = numDigits - 1; i >= 0; i--) {
        rhsIntDigit = digit_to_decimal(rhs.at(i));
        lhsIntDigit = digit_to_decimal(lhs.at(i));

        if (carryOver) {
            intermediateSum = rhsIntDigit + lhsIntDigit + 1;
            carryOver = false;
        } else {
            intermediateSum = rhsIntDigit + lhsIntDigit;
        }
        
        charDigit = decimal_to_digit(intermediateSum % 10);

        finalSum.insert(0, 1, charDigit);
        if (intermediateSum >= 10) {
            carryOver = true;
        }
    }
    // Make sure that any excess 0s are trimmed off. If the number should be negative, the negative sign is returned.
    finalSum = trim_leading_zeros(finalSum);
    if (lhsIsNegative && rhsIsNegative) {
        finalSum.insert(0, 1, '-');
    }

    // Debug Output
    // cout << "LHS: " << lhs << " " << "RHS: " << rhs << " " << "Final Sum: " << finalSum << endl;
    return finalSum;
}

string subtract(string lhs, string rhs) {
    bool lhsIsLarger = false;
    bool rhsIsLarger = false;
    bool lhsIsNegative = false;
    bool rhsIsNegative = false;
    bool takeawayOne = false;
    bool takeawaySeries = false;
    bool takeFromZero = false;
    bool equalValues = false;

    char charDigit;

    int numDigits;
    int rhsIntDigit;
    int lhsIntDigit;
    int intermediateDifference;

    string finalDifference = "";
    string zeros = "";
    string rhsTest;
    string lhsTest;

    //cout << "(1) LHS: " << lhs << " " << "RHS: " << rhs << endl;

    // Should probably strip all extra zeros before I do anything, just in case.
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    // Defines negative numbers and dictates the approach the program will take
    if (lhs.at(0) == '-') {
        lhsIsNegative = true;
    }
    if (rhs.at(0) == '-') {
        rhsIsNegative = true;
    }
    // If it equals to zero, then I dont even want it to touch my code
    if (lhsIsNegative && rhsIsNegative && rhs == lhs) {
        return "0";
    }
    // I should figure out which number is larger in absolute value in cases where the strings are the same length.
    if (rhsIsNegative) {
        rhsTest = rhs.substr(1);
    } else {
        rhsTest = rhs;
    }
    if (lhsIsNegative) {
        lhsTest = lhs.substr(1);
    } else {
        lhsTest = lhs;
    }
    
    if (rhs.size() == lhs.size()) {
        int rhsDigit;
        int lhsDigit;
        for (int i = 0; i < rhs.size(); i++) {
            rhsDigit = digit_to_decimal(rhsTest.at(i));
            lhsDigit = digit_to_decimal(lhsTest.at(i));
            //cout << rhsDigit << endl;
            //cout << lhsDigit << endl;
            if (rhsDigit > lhsDigit) {
                rhsIsLarger = true;
                break;
            } else if (lhsDigit > rhsDigit) {
                lhsIsLarger = true;
                break;
            }
            if (i == rhs.size() - 1) {
                equalValues = true;
            }
        }
    } else {
        if (rhsTest.size() > lhsTest.size()) {
            rhsIsLarger = true;
        } else if (rhsTest.size() < lhsTest.size()) {
            lhsIsLarger = true;
        }
    }
    //cout << "Number size: " << lhsTest.size() << " " << rhsTest.size() << endl;
    //cout << "LHS Larger: " << lhsIsLarger << " " << "RHS Larger: " << rhsIsLarger << endl;
    // Removes that pesky minus sign
    if (rhsIsNegative) {
        rhs = rhs.substr(1);
    } 
    if (lhsIsNegative) {
        lhs = lhs.substr(1);
    }
    // If the subtraction results in a number like -x - (-y) it is best to change it to y - 
    //cout << "(2) LHS: " << lhs << " " << "RHS: " << rhs << endl;
    if (lhsIsNegative && !rhsIsNegative) {
        cout << "Check me (1)" << endl;
        return add(rhs.insert(0, 1, '-'), lhs.insert(0, 1, '-'));
    } else if (!lhsIsNegative && rhsIsNegative) {
        cout << "Check me (2)" << endl;
        return add(lhs, rhs);
    } else if (lhsIsNegative && rhsIsNegative && rhsIsLarger) {
        cout << "Check me (3)" << endl;
        return subtract(rhs, lhs);
    } else if (lhsIsNegative && rhsIsNegative && lhsIsLarger){
        cout << "Check me (4)" << endl;
        return subtract(lhs, rhs).insert(0, 1, '-');
    } else if (lhsIsNegative && rhsIsNegative && lhsIsLarger) {
        cout << "Check me (5)" << endl;
        return subtract(lhs, rhs).insert(0, 1, '-');
    } else if (!lhsIsNegative && !rhsIsNegative && rhsIsLarger) {
        cout << "Check me (6)" << endl;
        return subtract(rhs, lhs).insert(0, 1, '-');
    }

    // Adds zeros to both numbers to get them to be the same length, and makes working with them easier
    if (lhs.size() < rhs.size()) {
        for (int i = 0; i < rhs.size() - lhs.size(); i++) {
            zeros.push_back('0');
        }
        lhs.insert(0, zeros);
    } else if (rhs.size() < lhs.size()) {
        for (int i = 0; i < lhs.size() - rhs.size(); i++) {
            zeros.push_back('0');
        }
        rhs.insert(0, zeros);
    }

    rhs.insert(0, "0");
    lhs.insert(0, "0");

    // This is the heartbeat of the function in terms of subtracting. Made from the adding part.
    numDigits = rhs.size();
    for (int i = numDigits - 1; i >= 0; i--) {
        rhsIntDigit = digit_to_decimal(rhs.at(i));
        lhsIntDigit = digit_to_decimal(lhs.at(i));

        if (takeawaySeries) {
            lhsIntDigit--;
        }

        if (lhsIntDigit - rhsIntDigit < 0) {
            takeawayOne = true;
        } else {
            takeawayOne = false;
        }
        // takewayOne tells the program to add 10 to the current because it take a 1 from the next. takeawaySeries tells the program that 1 has been taken away from the current column
        if (takeawayOne || takeawaySeries) {
            if (!takeawaySeries && takeawayOne) {
                intermediateDifference = (10 + lhsIntDigit) - rhsIntDigit;
                takeawaySeries = true;
            } else if (takeawaySeries && takeawayOne) {
                intermediateDifference = (10 + lhsIntDigit) - rhsIntDigit;
                takeawaySeries = true;
            } else if (!takeawayOne) {
                intermediateDifference = lhsIntDigit - rhsIntDigit;
                takeawaySeries = false;
            }
            
        } else {
            intermediateDifference = lhsIntDigit - rhsIntDigit;
        }
        
        charDigit = decimal_to_digit(intermediateDifference);

        finalDifference.insert(0, 1, charDigit);
    }
    // Make sure that any excess 0s are trimmed off. If the number should be negative, the negative sign is returned.
    finalDifference = trim_leading_zeros(finalDifference);
    if (lhsIsNegative && rhsIsNegative) {
        finalDifference.insert(0, 1, '-');
    }

    // Debug Output
    //cout << "LHS: " << lhs << " " << "RHS: " << rhs << " " << "Final Difference: " << finalDifference << endl;
    return finalDifference;
    
    return "";
}

string multiply(string lhs, string rhs) {
    bool lhsIsLarger = false;
    bool rhsIsLarger = false;
    bool lhsIsNegative = false;
    bool rhsIsNegative = false;
    bool equalValues = false;

    char charDigit;

    int numDigits;
    int rhsIntDigit;
    int lhsIntDigit;
    int intermediateProduct;
    int CarryOverMult;
    int CarryOverAdd;

    string rhsTest;
    string lhsTest;
    string largerValue;
    string smallerValue;
    string intermediateSum;

    string intermediateProductString = "";
    string finalProduct = "";
    string zeros = "";

    //cout << "(1) LHS: " << lhs << " " << "RHS: " << rhs << endl;

    // Should probably strip all extra zeros before I do anything, just in case.
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    // Defines negative numbers and dictates the approach the program will take
    if (lhs.at(0) == '-') {
        lhsIsNegative = true;
    }
    if (rhs.at(0) == '-') {
        rhsIsNegative = true;
    }
    // If it equals to zero, then I dont even want it to touch my code
    if (lhsIsNegative && rhsIsNegative && rhs == lhs) {
        return "0";
    }
    // I should figure out which number is larger in absolute value in cases where the strings are the same length.
    if (rhsIsNegative) {
        rhsTest = rhs.substr(1);
    } else {
        rhsTest = rhs;
    }
    if (lhsIsNegative) {
        lhsTest = lhs.substr(1);
    } else {
        lhsTest = lhs;
    }
    
    if (rhs.size() == lhs.size()) {
        int rhsDigit;
        int lhsDigit;
        for (int i = 0; i < rhs.size(); i++) {
            rhsDigit = digit_to_decimal(rhsTest.at(i));
            lhsDigit = digit_to_decimal(lhsTest.at(i));
            //cout << rhsDigit << endl;
            //cout << lhsDigit << endl;
            if (rhsDigit > lhsDigit) {
                rhsIsLarger = true;
                break;
            } else if (lhsDigit > rhsDigit) {
                lhsIsLarger = true;
                break;
            }
            if (i == rhs.size() - 1) {
                equalValues = true;
            }
        }
    } else {
        if (rhsTest.size() > lhsTest.size()) {
            rhsIsLarger = true;
            largerValue = rhsTest;
            smallerValue = lhsTest;
        } else if (rhsTest.size() < lhsTest.size()) {
            lhsIsLarger = true;
            largerValue = lhsTest;
            smallerValue = rhsTest;
        }
    }
    
    // Removes that pesky minus sign
    if (rhsIsNegative) {
        rhs = rhs.substr(1);
    } 
    if (lhsIsNegative) {
        lhs = lhs.substr(1);
    }

    // Adds zeros to both numbers to get them to be the same length, and makes working with them easier
    if (lhs.size() < rhs.size()) {
        for (int i = 0; i < rhs.size() - lhs.size(); i++) {
            zeros.push_back('0');
        }
        lhs.insert(0, zeros);
    } else if (rhs.size() < lhs.size()) {
        for (int i = 0; i < lhs.size() - rhs.size(); i++) {
            zeros.push_back('0');
        }
        rhs.insert(0, zeros);
    }

    rhs.insert(0, "0");
    lhs.insert(0, "0");

    if (rhsIsLarger) {
        largerValue = rhs;
        smallerValue = lhs;
    } else {
        largerValue = lhs;
        smallerValue = rhs;
    }
    //Heartbeat of Function
    int multiTen = 1;
    string stringIntermediateStringSum = "0";
    intermediateProductString = "0";

    for (int i = largerValue.size() - 1; i >= 0; i--) {
        for (int multiple = digit_to_decimal(smallerValue.at(i) * multiTen); i > 0; i--) {
            intermediateProductString = add(intermediateProductString, largerValue);
        }
        stringIntermediateStringSum = add(stringIntermediateStringSum, intermediateProductString);
        multiTen++;
    }

    return stringIntermediateStringSum;

    




}
