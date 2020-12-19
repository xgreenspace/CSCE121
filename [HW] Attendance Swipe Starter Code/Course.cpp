#define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;


#include <iostream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::endl, std::cout;

Course::Course(std::string id, std::string title, Date startTime, Date endTime) : id(id), title(title), startTime(startTime), endTime(endTime) {}

std::string Course::getID() const {
    return id;
}

std::string Course::getTitle() const {
    return title;
}

Date Course::getStartTime() const  {
    return startTime;
}

Date Course::getEndTime() const {
    return endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {

    if (!(ar.getDate() >= this->startTime && ar.getDate() <= this->endTime)) {
        throw std::invalid_argument("addAttendanceRecord: Time is invalid.");
    }

    attendanceRecords.push_back(ar);
}

void Course::outputAttendance(std::ostream& os) const {
    unsigned count = 0;

    for (AttendanceRecord attendance : this->attendanceRecords) {
        os << attendance << endl;
        count++;
    }

    if (count == 0) {
        os << "No records" << endl;
    }
}

void Course::outputAttendance(std::ostream& os, std::string student_id) const {
    unsigned count = 0;
    for (AttendanceRecord attendance : this->attendanceRecords) {
        if (student_id == attendance.getStudentID()) {
            os << attendance << endl;
            count++;
        }
    }

    if (count == 0) {
        os << "No records" << endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Course& c) {
    os << c.getID() << "," << c.getStartTime().getTime(false) << "," << c.getEndTime().getTime(false) << "," << c.getTitle();

    return os;
}