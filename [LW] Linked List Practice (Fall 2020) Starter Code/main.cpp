#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

int main(){

    MyList A;

    A.add("BBQ", 9);
    A.add("Turkey", 5);

    A.printList();

}