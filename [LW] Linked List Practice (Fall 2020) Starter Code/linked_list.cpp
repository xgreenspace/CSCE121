#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

void MyList::add(string name, int score) {
    
    MyNode* node = new MyNode(name, score);
    if (_headPtr == nullptr) {
        this->_headPtr = node;
    } else {
        _tailPtr->setNext(node);
    }

    this->_tailPtr = node;
    this->_size = _size + 1;
}

bool MyList::remove(string name) {
    // TODO
    this->_prevPtr = nullptr;
    this->_marker = _headPtr;

    while (!(_marker == nullptr)) {
        if (_marker->name() == name) {
            break;
        }
        this->_prevPtr = _marker;
        this->_marker = _marker->next();
    }

    if (this->_marker == nullptr) {
        return false;
    }

    if (this->_marker == _headPtr && this->_marker == _tailPtr) {
        this->_headPtr = nullptr;
        this->_tailPtr = nullptr;
    } else if (this->_marker == _headPtr) {
        this->_headPtr = _headPtr->next();
    } else if (this->_marker == _tailPtr) {
        _prevPtr->setNext(nullptr);
        this->_tailPtr = _prevPtr;
    } else {
        _prevPtr->setNext(_marker->next());
        this->_prevPtr = nullptr;
    }
    _marker->setNext(nullptr);
    delete this->_marker;
    this->_marker = nullptr;
    this->_size = this->_size - 1;


    return true;
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO

    if (index > this->_size) {
        return false;
    }
    if (index == this->_size) {
        add(name, score);
        return true;
    }


    this->_marker = this->_headPtr;
    this->_prevPtr = nullptr;

    for (size_t i = 0; i < index; i++) {
        this->_prevPtr = this->_marker;
        this->_marker = _marker->next();
    }

    MyNode* node = new MyNode(name, score);
    if (!(this->_prevPtr == nullptr)) {
        _prevPtr->setNext(node);
    }

    node->setNext(this->_marker);
    if (index == 0) {
        this->_headPtr = node;
    }

    this->_marker = nullptr;
    this->_prevPtr = nullptr;
    this->_size++;

    return true;
    
}

void MyList::clear() {
    while (!(_headPtr == nullptr)) {
        this->_marker = _headPtr;
        this->_headPtr = _headPtr->next();
        _marker->setNext(nullptr);
        delete _marker;
    }

    this->_marker = nullptr;
    this->_headPtr = nullptr;
    this->_tailPtr = nullptr;
    this->_size = 0;
}

MyList::MyList() {
    _size = 0;
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _marker = nullptr;
}

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() {
    return _headPtr;
}

void MyList::printList() {
    _marker = _headPtr;
    if (_marker == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    while (_marker != nullptr) {
        cout << "[ " << _marker->name() << ", " << _marker->score() << " ]" << endl;
        _marker = _marker->next();
    }
}

MyNode::MyNode(std::string name, int score) {
    _name = name;
    _score = score;
    _nextPtr = nullptr;
}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}