#define DEBUG(X) std::cout << "[DEBUG] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "School.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::ifstream, std::istringstream, std::endl, std::cout;

void School::addCourses(std::string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addCourses: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    if (line.find_first_not_of(' ') == std::string::npos) {
      break;
    }
    istringstream ss(line);
    string course_id;
    getline(ss, course_id, ',');
    string startTimeHours;
    getline(ss, startTimeHours, ':');
    string startTimeMinutes;
    getline(ss, startTimeMinutes, ',');
    Date startTime(stoi(startTimeHours), stoi(startTimeMinutes), 0);
    string endTimeHours;
    getline(ss, endTimeHours, ':');
    string endTimeMinutes;
    getline(ss, endTimeMinutes, ',');
    Date endTime(stoi(endTimeHours), stoi(endTimeMinutes), 0);
    string title;
    getline(ss, title);
    if (!ss.fail()) {
      Course course(course_id, title, startTime, endTime);
      bool exists = false;
      for (Course c : courses) {
        if (c == course) {
          exists = true;
          break;
        }
      }
      if (!exists) {
        courses.push_back(course);
      }
    }
  }
}

// one method is provided to students; students implement all other methods
void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addStudents: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
        Student student(uin, name);
        bool exists = false;
        for (Student s : students) {
            if (s == student) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            students.push_back(student);
        }
    }
  }
}

bool School::isEnrolled(std::string student_id) const {
  for (Student student : students) {
    if (student.get_id() == student_id) {
      return true;
    }
  }
  return false;
}

unsigned int School::addAttendanceData(std::string filename) {
  bool valid = false;
  unsigned int counter = 0;

  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addAttendenceData: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    if (line.find_first_not_of(' ') == std::string::npos) {
      return counter;
    }
    istringstream ss(line);
    string year;
    getline(ss, year, '-');
    // DEBUG(year);
    string month;
    getline(ss, month, '-');
    // DEBUG(month);
    string day;
    getline(ss, day, ' ');
    // DEBUG(day);
    string hour;
    getline(ss, hour, ':');
    // DEBUG(hour);
    string minute;
    getline(ss, minute, ':');
    // DEBUG(minute);
    string second;
    getline(ss, second, ',');
    // DEBUG(second);
    Date date(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minute), stoi(second));
    string course_id;
    getline(ss, course_id, ',');
    // DEBUG(course_id);
    string student_id;
    getline(ss, student_id);
    // DEBUG(student_id);

    if (!ss.fail()) {
      
      for (Student s : students) {
        if (s.get_id() == student_id) {
          valid = true;
        }
      }

      for (Course &c : courses) {
        if (c.getID() == course_id && valid) {
          valid = true;
        } else {
          valid = true;
        }
      }

        if (date.isValid()) {
          try
          {
            AttendanceRecord ar(course_id, student_id, date);
            for (Course &c : courses) {
              if (c.getID() == course_id && valid) {
                c.addAttendanceRecord(ar);
                valid = true;
              }
            }
          }
          catch(const std::invalid_argument& e)
          {
            std::cerr << e.what() << '\n';
            valid = false;
            counter++;


          }
        
        } else {
          valid = false;
          counter += 2;
        } 

        if (!valid) {
          counter++;
        } 
      }
    }
    return counter;
  }


void School::listCourses(std::ostream& os) const {
  if (this->courses.size() == 0) {
    os << "No courses" << endl;
    return;
  }

  for (Course course : this->courses) {
    os << course.getID() << "," << course.getStartTime().getTime(false) << "," << course.getEndTime().getTime(false) << "," << course.getTitle() << endl;
  }
}

void School::listStudents(std::ostream& os) const {
  if (students.size() == 0) {
    os << "No students" << endl;
    return; 
  }

  for (Student student : students) {
    os << student.get_id() << "," << student.get_name() << endl;
  }
}

void School::outputCourseAttendance(std::ostream& os, std::string course_id) const {
  unsigned counter = 0;

  for (Course course : this->courses) {
    if (course.getID() == course_id) {
      course.outputAttendance(os);
      counter++;
    }
  }

  if (counter == 0) {
    throw std::invalid_argument("No records");
  }
}

void School::outputStudentAttendance(std::ostream& os, std::string student_id, std::string course_id) const {
  unsigned counter = 0;

  if (!(isEnrolled(student_id))) {
    throw std::invalid_argument("Student not found");
  }

  for (Course course : this->courses) {
    if (course.getID() == course_id) {
      course.outputAttendance(os, student_id);
      counter++;
    }
  }

  if (counter == 0) {
    throw std::invalid_argument("No records");
  }
}


