#include "./../headers/student.hpp"

#define     GRADECTS 240

using std::cout;
using std::cin;
using std::endl;

void    Student::change_semester(int new_semester)   { Student::semester = new_semester; }
void    Student::change_ects(int new_ects)           { Student::ects = new_ects; }

void    Student::update_ects()                       {
        float ects = 0;
                for (auto & g : this->grades) {
                    if (g.grade >= 5.0) {
                        ects += g.course->get_ects();
                    }
                }
        this->ects = ects;
}

bool    Student::completed_mandatories(void)         {return true;}

void    Student::get_grades()                        {
            for (auto & g : this->grades) {
               cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
               cout << "---------------------------------"                     << endl;
               cout << g.grade << endl; 
            }
}   

bool    Student::can_graduate()                      {return (this->semester > 8 && this->ects >= GRADECTS && this->completed_mandatories());}




            // for (auto & g : this->grades) {
            //    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
            //    cout << "---------------------------------"                     << endl; 
            //    cout << "Course ECTS:" << g.course->get_ects()                  << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << "Course Semester:" << g.course->get_semester()          << endl; 
            //    cout << "---------------------------------"                     << endl;
            //    cout << g.course.  
            // }