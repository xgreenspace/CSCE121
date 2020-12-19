#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::ostringstream;
using std::endl;
using std::istringstream;

int main() {
    // Test code to determine if a value is an integer or not
    string line;
    getline(cin, line);
    istringstream ss(line);

    int a = 0;
    int b = 0;


    if (!(ss >> a)) {
        cout << "(a) This is not an integer" << endl;
    }

    if (!(ss >> b)) {
        cout << "(b) This is not an integer" << endl;
    }

    cout << "a = " << a << " b = " << b << endl; 

}