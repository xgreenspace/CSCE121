#include "functions.h"

bool is_valid_range(int a, int b) {
    // TODO(student): validate input range
    if (0 < a && a <= b && b <= 10000) {
        return true;
    }
    return false;
}

int count_digit_occurrences(int number, int digit) {
  // TODO(student): return how many times digit occurs in number

  int testDigit; //testDigit will caputure the remainder of the number divided by increasing powers of 10
  int multiOfTen = 10; //variable will increase by a factor of 10 with each iteration
  int counter = 0; //counter tracks the number of times the digit appears in the number

  // Gets the absolute value of the number  
  if (number < 0) {
      number *= -1;
  }

  while (digit >= 0 && digit <= 9) {
      testDigit = number % (multiOfTen); //Checks if the one's place matches the desired digit using mod operator
      if (digit == testDigit && !(multiOfTen > 10)) {
          counter++;
      } else {
          testDigit = testDigit / (multiOfTen / 10); //Checks if other digits matches the desired digit using integer division
          if (digit == testDigit) {
              counter++;
          }
      }
      if (multiOfTen > number) {
          return counter;
      }
      multiOfTen *= 10;
  }
  return 0;
}

bool has_repeated_digits(int number) {
    // TODO(student): return true if number has repeated digits
    int repeatDigits; //Tracks repeated digits

    for (int i = 0; i < 10; i++) {
        repeatDigits = count_digit_occurrences(number, i);
        if (repeatDigits > 1) {
            return true;
        }
    }
    return false;
}

int count_valid_numbers(int a, int b) {
    // TODO(student): return count of valid numbers in range
    int validNumbers = 0; //Tracks the number of valid numbers in a range

    for (int i = a; i <= b; i++) {
        if (has_repeated_digits(i)) {
            validNumbers++;
        }
    }
    return validNumbers;
}


