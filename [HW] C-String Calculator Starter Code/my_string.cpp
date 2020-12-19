#define DEBUG(X) std::cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;
#define INFO(X) std::cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << X << std::endl;

// my_string.cpp
#include <iostream>
#include "my_string.h"
#include "my_sstream.h"

using std::cin, std::cout, std::endl;

// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods

// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {}

//   rule of "3"

//     my_string copy constructor
my_string::my_string(const my_string& other) : _data(), _capacity(other._capacity), _size(other._size) {

    cout << "My string Copy Constructor Called" << endl;

    _data = new char[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _data[i] = other._data[i];
    }

}

//     my_string copy assignment
my_string& my_string::operator=(const my_string& other) {

    cout << "Copy Assignment Called" << endl;
    
    if (this != &other) {
        _capacity = other._capacity;
        delete[] _data;
        _data = new char[_capacity];
        _size = other._size;

        for (size_t i = 0; i < _capacity; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

//     destructor
my_string::~my_string() {

    cout << "Destructor Called" << endl;
    delete[] _data;
}

//   c-string copy constructor
my_string::my_string(const char* other) : _data(), _capacity(), _size() {

    cout << "C-string copy contructor called" << endl;

    _capacity = 1;
    _size = 0;

    for (size_t i = 0; other[i] != '\0'; i++) { // Use for loop to interate through all values
        _capacity++;
        _size++;
    }

    _data = new char[_capacity];
    for (size_t i = 0; i < _capacity; i++) { // Create new array
        _data[i] = other[i];
    }
}

// element access
//   at
const char& my_string::at(size_type index) const {
    if (index >= _size) {
        throw std::invalid_argument("[Error] Invalid Range");
    }

    return _data[index];
}

char& my_string::at(size_type index) {
    if (index >= _size) {
        throw std::invalid_argument("[Error] Invalid Range");
    }

    return _data[index];
}

//   front
//   operator[]
const char& my_string::operator[](size_type index) const {
    if (index >= _size) {
        throw std::invalid_argument("[Error] Invalid Range");
    }

    return _data[index];
}

char& my_string::operator[](size_type index) {
    if (index >= _size) {
        throw std::invalid_argument("[Error] Invalid Range");
    }

    return _data[index];
}

// capacity
//   empty
bool my_string::empty() const {
    if (_size == 0) {
        return true;
    }
    
    return false;
}
//   size
size_t my_string::size() const {
    return _size;
}
//   erase
size_t my_string::erase(size_type A, size_type len) {
    size_t a;
    for (size_t i = 0; i < len; i++) {
        a = A;
        _size--;
        while (_data[a] != '\0') {
            _data[a] = _data[a + 1];
            a++;
        }
    }
    

    return _size;
}
//   insert

// operations
//   concatenation
//     my_string + my_string (non-member, friend)
//     my_string + c-string (non-member, friend)
//     my_string + char (non-member, friend)
//     c-string + my_string (non-member, friend)
//     char + my_string (non-member, friend)
//     my_string += my_string
friend my_string operator+(my_string lhs, const my_string& rhs) {

}
friend my_string operator+(my_string lhs, const char* rhs) {

}
friend my_string operator+(my_string lhs, char rhs) {
    
}
friend my_string operator+(const char* lhs, const my_string& rhs);
friend my_string operator+(char lhs, my_string rhs);

my_string& my_string::operator+=(const my_string& rhs) {
    DEBUG(rhs);
    return *this;
}
//     my_string += c-string
my_string& my_string::operator+=(const char* rhs) {
    DEBUG(rhs);
    return *this;
}
//     my_string += char
my_string& my_string::operator+=(char rhs) {
    DEBUG(rhs);
    return *this;
}

// search
//   find


// non-member functions
//   relational operators
//     my_string == my_string
bool operator==(const my_string& lhs, const my_string& rhs) {

    size_t i = 0;
    while (i < lhs.size()) {
        if (lhs[i] == rhs[i]) {
            i++;
        } else {return false;}
    }
    

    return true;
}
//     my_string == c-string
bool operator==(const my_string& lhs, const char* rhs) {

    size_t i = 0;
    while (i < lhs.size()) {
        if (lhs[i] == rhs[i]) {
            i++;
        } else {return false;}
    }
    
    return true;

}
//   stream operators
//     ostream instertion operator
std::ostream& operator<<(std::ostream& os, const my_string& str) {
    
    size_t i = 0;
    while(i < str.size()) {
        os << str[i];
        i++;
    }
    return os;
}
//     istream extraction operator
std::istream& operator>>(std::istream& os, my_string& str) {
    
    size_t i = 0;
    while(i < str.size()) { //FIXME: Finish implementing this string
        os >> str[i];
        i++;
    }
    return os;
}
//     getline
std::istream& getline(std::istream& is, my_string& str, char delim) {
    DEBUG(str);
    DEBUG(delim);
    return is;
}
//   numeric conversions
//     to_string


// my_istringstream methods

my_istringstream::my_istringstream(const my_string& str) : _str(str), idx(0), state_fail(false), state_eof(str.empty()) {}

void my_istringstream::eat_whitespaces() {
    while (idx < _str.size() && isspace(_str[idx])) {
        idx++;
    }
}

my_istringstream& my_istringstream::operator>>(my_string& str) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    my_string s;
    while (idx < _str.size() && !isspace(_str[idx])) {
        s += _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    str = s;
    return *this;
}

my_istringstream& my_istringstream::operator>>(char& c) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    if (idx < _str.size()) {
        c = _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    return *this;
}

bool my_istringstream::good() const { return !(state_fail || state_eof); }
bool my_istringstream::fail() const { return state_fail; }
bool my_istringstream::eof() const { return state_eof; }

// TODO(student): define other my_istringstream methods, if any
