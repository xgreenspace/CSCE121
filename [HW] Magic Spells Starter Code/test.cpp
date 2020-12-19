#define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;

#include <iostream>
#include <cmath>
#include "dada.h"
#include "dada.cpp"
using std::cout, std::endl, std::abs, std::sqrt;

int main() {
    double test1_1[] = {4, 6, 3, 1, 2, 9};
    double test1_2[] = {-93, 432, 23423, -784382, 3, 4123};
    double test1_3[] = {0, 1, 1, 1, 0, 0};
    double test1_4[] = {0, 3452, 902, -1, 32, 66};
    double test1_5[] = {1.3, 1.3, -1.5, 1.2, 1.2, 1.4};

    DEBUG(amax(test1_1, 6));
    DEBUG(amax(test1_2, 6));
    DEBUG(amax(test1_3, 6));
    DEBUG(amax(test1_4, 6));
    DEBUG(amax(test1_5, 6));

    cout << endl;




}
