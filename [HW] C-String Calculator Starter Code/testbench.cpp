#include <iostream>
#include "my_string.h"
#include "my_sstream.h"

using std::cout, std::cin, std::endl; 

int main() {
    my_string test1 = "hi";
    my_string test2 = "Where";

    test1 = test2;

    cout << test1.erase(1, 2) << endl;
    if (test1 == "Wre") {
        cout << "Yes!" << endl;
    }

    
}