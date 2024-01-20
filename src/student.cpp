#include "./../headers/student.hpp"
#include "./../headers/secretary.hpp"
#include <memory>
#include <algorithm>


#define     GRADECTS    240
#define     MSEMESTER   8

using std::cout;
using std::endl;

void    Student::set_semester(int new_semester)         { Student::semester = new_semester; }
void    Student::set_ects(int new_ects)                 { Student::ects = new_ects; }
void    Student::set_passed(bool new_passed)            { Student::passed = new_passed; }

// Updates Student's ECTs for each Course passed.
void    Student::update_ects()                       {
        float ects = 0;
                for (auto & g : this->grades) {
                    if (g.grade >= 5.0) {
                        ects += g.course->get_ects();
                    }
                }
        this->ects = ects;
}

// Calculates how many mandatory Courses have been passed.
// If all mandatory Courses have been passed, 1/3 requirements for the Student to graduate is complete. 
bool    Student::completed_mandatories(int mandatories)   const      {
    auto counter = 0;
    for (auto & c : this->grades) {
        if ((c.course->get_mandatory() && c.grade >= 5.0 ) == true) {
            counter++;
        }
    }
    if (counter == mandatories) {
        return true;
    }
    return false;
}



int     Student::get_semester() const {return this->semester;}

int     Student::get_ects() const {return this->ects;}

bool    Student::get_passed() const {return this->passed;}


// Prints grades for each Course the Student has undertaken. 
// Option to print Courses from all semesters or from current semester.
void    Student::get_grades (bool all_semesters) const                        {

    if(all_semesters == false) {
            for (auto & g : this->grades) {
                if (g.course->get_semester() == this->get_semester()) {      
                    cout << g.course->get_name() << ":" << g.course->get_serialno() << endl;
                    cout << "Semester: " << g.course->get_semester()    << endl;
                    cout << "Grade: " << g.grade << endl; 
                    cout <<        "---------------------------------"              << endl;
                }
            }
    } else {
        for (auto & g : this->grades) {
                    cout << g.course->get_name() << ": " << g.course->get_serialno() << endl;
                    cout << "Semester:" << g.course->get_semester()    << endl;
                    cout << "Grade: " << g.grade << endl; 
                    cout <<        "---------------------------------"              << endl;
                }
            }
    }

// Used to determine whether the Student has passed given Course.
bool    Student::has_passed(std::shared_ptr<Course> c) const {
    for (auto &g : this->grades) {
        if (c == g.course && g.grade >= 5.0) {
            return true;
        }
    }
    return false;
}

// If the Student has completed 8 semester of studies, has passed all mandatory Courses and has collected the necessary amount of ECTs, they are eligible to graduate.
bool    Student::can_graduate(int mandatories) const                     {return (this->semester >= MSEMESTER && this->ects >= GRADECTS && this->completed_mandatories(mandatories));}

// Used for Students to undertake new Courses.
// The Student's Course List is checked to determine whether Student has already undertaken given Course.
// If the Student's current semester is lower than the semester the Course is taught in, an error message is printed.
// If the conditions are met, the Course is added to the Student's Course List with a grade of 0.
void    Student::enroll(std::shared_ptr<Course> c) {

    auto iterator = std::find_if(this->grades.begin(), this->grades.end(), 
                                        [c] (grade_per_student c1) {return c == c1.course;});

    if (iterator != this->grades.end()) {
        cout << "ERROR: Student has already been enrolled to this course." << endl;
        return;
    } else if (c->get_semester() > this->get_semester()) {
        cout << "ERROR: Cannot register for a course with a higher minimum semester requirement." << endl;
    }
    grade_per_student g;
    g.grade = 0;
    g.course = c;
    this->grades.push_front(g);
    c->set_enrolled(c->get_enrolled()+1);
    
}





// Removes a Course from the Student's Course List.
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