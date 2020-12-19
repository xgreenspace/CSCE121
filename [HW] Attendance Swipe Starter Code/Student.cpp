#include <iostream>
#include <string>
#include "Student.h"

using std::cout, std::endl;

// constructor
Student::Student(std::string student_id, std::string name) : id(student_id), name(name), course_ids(0) {}

// Getters
std::string Student::get_id() const {
    return id;
}

std::string Student::get_name() const {
    return name;
}

// Add Courses
void Student::addCourse(std::string course_id) {

    // Check if the course_id is already in list
    for (std::string course : course_ids) {
        if (course == course_id) {
            throw std::invalid_argument("Course already added.");
        }
    }

    // Add course to list
    course_ids.push_back(course_id);
}

// List Courses
void Student::listCourses(std::ostream& os) const {

    os << "Courses for " << id << endl;

    if (course_ids.size() == 0) {
        os << "No courses" << endl;
    } else {
        for (std::string course : course_ids) {
            os << course << endl;
        }
    }
}

