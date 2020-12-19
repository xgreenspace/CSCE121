/*
DADA function definitions
*/

#include <iostream>
#include <cmath>
#include "dada.h"
using std::cout, std::endl, std::abs, std::sqrt;

int amax(const double x[], const unsigned int len) {
    //TODO: student implement code here
    double largest = -1.79769e+308;
    unsigned int firstIndex = 0;

    if (len == 0) {
        return -1;
    }

    for (unsigned i = 0; i < len; i++) {
        if (abs(x[i]) > largest) {
            largest = abs(x[i]);
            firstIndex = i;
        }
    }
    return firstIndex;
}

double asum(const double x[], const unsigned int len) {
    //TODO: student implement code here
    double sum = 0;
    for (unsigned i = 0; i < len; i++) {
        sum += abs(x[i]);
    }
    return sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
    //TODO: student implement code here
    double yInit;
    for (unsigned i = 0; i < len; i++) {
        yInit = y[i];
        y[i] = a * x[i] + yInit; 
    }
}

void copy(const double src[], double dest[], const unsigned int len) {
    //TODO: student implement code here
    for (unsigned i = 0; i < len; i++) {
        dest[i] = src[i];
    }

}

double dot(const double x[], const double y[], const unsigned int len) {
    //TODO: student implement code here
    double productSum = 0;
    for (unsigned i = 0; i < len; i++) {
        productSum += x[i] * y[i];
    }

    return productSum;
}

double norm2(const double x[], const unsigned int len) {
    //TODO: student implement code here
    double sum = 0;
    for (unsigned i = 0; i < len; i++) {
        sum += pow(abs(x[i]), 2);
    }
    return sqrt(sum);

}

void scale(const double a, double x[], const unsigned int len) {
    //TODO: student implement code here
    for (unsigned i = 0; i < len; i++) {
        x[i] = x[i] * a;
    }
}

void swap(double x[], double y[], const unsigned int len) {
    //TODO: student implement code here
    double a;
    double b;
    for (unsigned i = 0; i < len; i++) {
        a = x[i];
        b = y[i];
        x[i] = b;
        y[i] = a;
    }
}
