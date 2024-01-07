#include "./../headers/student.hpp"
#include "./../headers/secretary.hpp"

#define     GRADECTS    240
#define     MSEMESTER   8

using std::cout;
using std::cin;
using std::endl;

void    Student::set_semester(int new_semester)   { Student::semester = new_semester; }
void    Student::set_ects(int new_ects)           { Student::ects = new_ects; }

void    Student::update_ects()                       {
        float ects = 0;
                for (auto & g : this->grades) {
                    if (g.grade >= 5.0) {
                        ects += g.course->get_ects();
                    }
                }
        this->ects = ects;
}

bool    Student::completed_mandatories(void)         {
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

void    Student::get_grades(bool all_semesters)                        {

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

  

bool    Student::can_graduate()                      {return (this->semester >= MSEMESTER && this->ects >= GRADECTS && this->completed_mandatories());}




            // for (auto & g : this->grades) {
            //    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
            //    cout << "---------------------------------"                     << endl; 
            //    cout << "Course ECTS:" << g.course->get_ects()                  << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << "Course Semester:" << g.course->get_semester()          << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << g.course.  
            // }