// #define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;


#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

using std::cout, std::endl;

void push(Stack& s, double element) {
    double* B;

    if (s.length == s.capacity) {
        B = new double[s.capacity * 2]{NAN};
        s.capacity *= 2;
    } else {
        B = new double[s.capacity]{NAN};
    }

    for (int i = 0; i < s.capacity; i++) {
        B[i] = s.A[i];
    }

    delete[] s.A;

    B[s.length] = element;

    s.A = B;

    s.length++;
}

double pop(Stack& s) {

    double element;

    if (s.length == 0) {
        return NAN; 
    }

    double* B = new double[s.capacity]{NAN};

    for (int i = 0; i < s.capacity; i++) {
        B[i] = s.A[i];
        if (i == s.length - 1) {
            element = B[i];
            B[i] = NAN;
        }
    }

    delete[] s.A;

    s.A = B; 

    s.length--;

    return element;

}

double peek(const Stack s) {
    return s.A[s.length - 1];
}

