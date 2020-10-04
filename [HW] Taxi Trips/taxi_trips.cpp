#include <stdexcept>
#include <string>
#include <iostream>
using std::string, std::cout, std::endl;
#include "taxi_trips.h"


bool is_payment_valid(string type, string valid_types[], unsigned int size) {
  // Throws an error if size = 0 of if size is greater than array length
  if (size == 0 || size > 4) {
    throw std::invalid_argument("Size cannot be zero.");
  }

  // Iterates through the loop; determines if type is valid
  for (int i = 0; i < size; i++) {
    if (type == valid_types[i]) {
      return true;
    }
  }
  return false;
}

double max(double values[], unsigned int size) {
  double maxNum = INT32_MIN;

  // Throws an error if size = 0
  if (size == 0) {
    throw std::invalid_argument("Invalid size.");
  }

  // Iterates through the loop; finds max number
  for (int i = 0; i < size; i++) {
    if (values[i] > maxNum) {
      maxNum = values[i];
    }
  }

  return maxNum;
}

double min(double values[], unsigned int size) {
  double minNum = INT32_MAX;

  // Throws an error if size = 0
  if (size == 0) {
    throw std::invalid_argument("Invalid size.");
  }

  // Iterates through the loop; finds min number
  for (int i = 0; i < size; i++) {
    if (values[i] < minNum) {
      minNum = values[i];
    }
  }

  return minNum;
}

double average(double values[], unsigned int size) {
  double sum = 0;
  double average = 0;

  // Throws an error if size = 0 
  if (size == 0) {
    throw std::invalid_argument("Invalid size.");
  }

  // Iterates through the loop; adds the numbers up
  for (int i = 0; i < size; i++) {
    sum += values[i];
  }

  average = static_cast<double>(sum) / static_cast<double>(size);

  return average;
}

double mode(double values[], unsigned int size) {
  string stringedValues = "++";
  double mode = values[0];
  int numCount = 0;
  int numCountBest = 0;

  // Throws an error if size = 0 
  if (size == 0) {
    throw std::invalid_argument("Invalid size.");
  }

  // Iterates through the loop; finds the 
  for (int i = 0; i < size; i++) {
    stringedValues.append(std::to_string(values[i]));
    stringedValues.append("++");
  }

  for (int i = 0; i < size; i++) {
    int found = stringedValues.find("+" + std::to_string(values[i]) + "+");
    numCount = 0;
    while (found != std::string::npos) {
      stringedValues.erase(found, std::to_string(values[i]).size());
      found = stringedValues.find("+" + std::to_string(values[i]) + "+");
      numCount++;
    }
    if (numCount > numCountBest) {
      mode = values[i];
      numCountBest = numCount;
    }
  }
  
  return mode;
}

unsigned int length_longest_seq_zeros(double values[], unsigned int size) {
  int numZeros = 0;
  int maxZeros = 0;

  if (size == 0) {
    throw std::invalid_argument("Invalid size.");
  }

  for (int i = 0; i <= size; i++) {
    if (values[i] == 0) {
      numZeros++;
    } else {
      if (numZeros > maxZeros) {
        maxZeros = numZeros;
      }
      numZeros = 0;
    }
  }

  return maxZeros;
}