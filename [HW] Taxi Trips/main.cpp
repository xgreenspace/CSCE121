#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl, std::istringstream;

int main() {

  string taxi_id;
  string trip_seconds;
  string trip_miles;
  string trip_fare;
  string trip_tip;
  string payment_type;

  string line;

  double listDistance[MAX_TRIPS];
  double listDuration[MAX_TRIPS];
  double listFare[MAX_TRIPS];
  double listTip[MAX_TRIPS];

  int invalidTrips = 0;
  int totalTrips = 0;
  int secondsInDay = 86400;
  int mileLimit = 1500;
  int moneyLimit = 5000;

  double seconds;
  double miles;
  double fare;
  double tip;
  
  // Get filename from user
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  ifstream file(filename);

  // Check if the file exists.
  if (!file.is_open()) {
    cout << "Can't open " << filename << endl;
    return 0;
  }


  // Extract all of the data
  int counter = 0;
  int index = 0;
  while(!file.eof()) {
    
    file >> taxi_id;
    file >> trip_seconds;
    file >> trip_miles;
    file >> trip_fare;
    file >> trip_tip;
    file >> payment_type;

    // cout << taxi_id <<" "<< trip_seconds <<" "<< trip_miles << " " << trip_fare << " " << trip_tip << " " << payment_type << " " << endl;

    // Checks if trip_seconds is valid
    seconds = stod(trip_seconds);
    if (seconds > secondsInDay || seconds < 0) {
      invalidTrips++;
      // counter--;
      continue;
    }

    // Checks if trip_miles is valid
    miles = stod(trip_miles);
    if (miles > mileLimit || miles < 0) {
      invalidTrips++;
      // counter--;
      continue;
    }

    // Checks if money recived is invalid
    fare = stod(trip_fare);
    tip = stod(trip_tip);
    if (fare + tip > moneyLimit) {
      invalidTrips++;
      // counter--;
      continue;
    }

    // Checks if payment method is valid
    if (!(payment_type == "CreditCard" || payment_type == "Cash" || payment_type == "NoCharge" || payment_type == "Unknown")) {
      invalidTrips++;
      // counter--;
      continue;
    }

    // Checks if fare is not zero when miles and time is
    if (seconds == 0 && miles == 0 && fare != 0) {
      invalidTrips++;
      // counter--;
      continue;
    }

    // Assign data to an array
    listDistance[index] = miles;
    listDuration[index] = seconds;
    listFare[index] = fare;
    listTip[index] = tip;

    // cout << listDuration[counter] << endl;

    counter++;
    index++;
  }

  totalTrips = counter;


  // cout << "========================================" << endl;

  cout << "Number of trips: " << counter << endl;
  cout << "Number of trips with invalid data: " << invalidTrips << endl;
  cout << "Duration: max " << max(listDuration, totalTrips) << " min " << min(listDuration, totalTrips) << " avg " << average(listDuration, totalTrips) << " mode " << mode(listDuration, totalTrips) << endl;
  cout << "Distance: max " << max(listDistance, totalTrips) << " min " << min(listDistance, totalTrips) << " avg " << average(listDistance, totalTrips) << " mode " << mode(listDistance, totalTrips) << endl;
  cout << "Fare: max " << max(listFare, totalTrips) << " min " << min(listFare, counter) << " avg " << average(listFare, totalTrips) << " mode " << mode(listFare, totalTrips) << endl;
  cout << "Tip: max " << max(listTip, totalTrips) << " min " << min(listTip, totalTrips) << " avg " << average(listTip, totalTrips) << " mode " << mode(listTip, totalTrips) << endl;
  cout << "Length of longest sequence without tips: " << length_longest_seq_zeros(listTip, totalTrips);

  return 0;
}