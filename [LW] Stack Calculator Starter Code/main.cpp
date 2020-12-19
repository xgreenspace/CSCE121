#define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;

#include <iostream>
#include <cmath>
#include <string>
#include "Stack.cpp"

using std::cin, std::cout, std::endl, std::string;

int main(){
    Stack testStack;

    push(testStack, 2);
    push(testStack, 1);

    DEBUG(peek(testStack));
    
    pop(testStack);

    DEBUG(peek(testStack));


}