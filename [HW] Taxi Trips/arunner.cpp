#include <iostream>
#include <string>
#include "taxi_trips.h"
#include "taxi_trips.cpp"

using namespace std;

int main() {
    double array[] = {10, 16, 10, 16, 16};

    cout << mode(array, 5) << endl; 
}