#include "./../headers/student.hpp"
#include "./../headers/secretary.hpp"
#include <memory>

#define     GRADECTS    240
#define     MSEMESTER   8

using std::cout;
using std::endl;

void    Student::set_semester(int new_semester)         { Student::semester = new_semester; }
void    Student::set_ects(int new_ects)                 { Student::ects = new_ects; }
void    Student::set_passed(bool new_passed)            { Student::passed = new_passed; }

void    Student::update_ects()                       {
        float ects = 0;
                for (auto & g : this->grades) {
                    if (g.grade >= 5.0) {
                        ects += g.course->get_ects();
                    }
                }
        this->ects = ects;
}

bool    Student::completed_mandatories(void)   const      {
    auto counter = 0;
    for (auto & c : this->grades) {
        if (c.course->get_mandatory() == true) {
            counter++;
        }
    }
    if (counter == Secretary::get_mandatoryno()) {
        return true;
    }
    return false;
}



int     Student::get_semester() const {return this->semester;}

int     Student::get_ects() const {return this->ects;}

bool    Student::get_passed() const {return this->passed;}

void    Student::get_grades (bool all_semesters) const                        {

    if(all_semesters == false) {
            for (auto & g : this->grades) {
                if (g.course->get_semester() == this->get_semester()) {      
                    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
                    cout << g.course->get_semester()    << endl;
                    cout <<        "---------------------------------"              << endl;
                    cout << g.grade << endl; 
                }
            }
    } else {
        for (auto & g : this->grades) {
                    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
                    cout << g.course->get_semester()    << endl;
                    cout <<        "---------------------------------"              << endl;
                    cout << g.grade << endl; 
                }
            }
    }



bool    Student::can_graduate() const                     {return (this->semester >= MSEMESTER && this->ects >= GRADECTS && this->completed_mandatories());}

void    Student::enroll(std::shared_ptr<Course> c) {

    grade_per_student g;
    g.grade = 0;
    g.course = c;
    this->grades.push_front(g);
    c->set_enrolled(c->get_enrolled()+1);
    
}

void     Student::cleanup(std::shared_ptr<Course> c) {
    this->grades.remove_if([c] (grade_per_student g) {return g.course == c;});
}

Student::Student(int semester_, int ects_, bool passed_) : semester(semester_), ects(ects_), passed(passed_){};
Student::~Student(){};

            // for (auto & g : this->grades) {
            //    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
            //    cout << "---------------------------------"                     << endl; 
            //    cout << "Course ECTS:" << g.course->get_ects()                  << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << "Course Semester:" << g.course->get_semester()          << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << g.course.  
            // }