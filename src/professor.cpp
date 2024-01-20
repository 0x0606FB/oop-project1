#include "./../headers/professor.hpp"
#include "./../headers/student.hpp"
#include <algorithm>
#include <memory>
#include <list>
using std::cin;
using std::cout;
using std::endl;


Professor::Professor(){};
Professor::~Professor(){};

// Searches the Professor's Course List for Course 'c'.
// If the Professor isn't already assigned to Course 'c', it is added to the Professor's Course List.
// If the Professor is assigned to it, an error message is printed. 

void Professor::assign_to_course(std::shared_ptr<Course> c){
    
    auto iterator = std::find_if(this->courselist.begin(), this->courselist.end(), 
                                        [c] (std::shared_ptr<Course> c1) {return c == c1;});
    
    if (iterator != this->courselist.end()) {
        cout << "ERROR: Professor has already been assigned to this course." << endl;
        return;
    }
    
    this->courselist.push_front(c);
}

// Function for a Professor to "drop" a Course.
void Professor::drop_course(std::shared_ptr<Course> c){
    this->courselist.remove(c);
}

// Prints statistics of each Course the Professor is assigned to.
void Professor::print_stats() const{
    for(auto &p: this->courselist){
        
        cout << "Course Name: " << p->get_name() << endl;
        cout << "Course ID: " << p->get_serialno() << endl;
        cout << "Students Enrolled: " << p->get_enrolled() << endl;
        cout << "-----------------------------------" << endl;
    }
}

// Used to grade given Student on given Course that the Professor is assigned to.
void Professor::grade_student(std::shared_ptr<Student> s, std::shared_ptr<Course> c){
    int grade;
    cout << "Enter grade: ";
    cin >> grade;
    // s->grade_entry(grade, c);

    auto iterator = std::find_if(s->grades.begin(), s->grades.end(), 
                                        [c] (grade_per_student c1) {return c == c1.course;});

    if (iterator != s->grades.end()) {
        iterator->grade = grade;
        cout << "Grade assigned successfully." << endl;
    } else {
        cout << "Student has not enrolled in this course." << endl;
    }

}

// Prints all courses the Professor is assigned to.
void     Professor::dump_courses () const {
    for (auto &c : this->courselist) {
        cout << c->get_name() << "  :  " << c->get_serialno() << endl;
        cout << "Semester " << c->get_semester() << endl;
        cout << "-----------------------------------" << endl;
    }
}

// Removes a Course from the Professor's Course List.
void     Professor::cleanup(std::shared_ptr<Course> c) {
    this->courselist.remove_if([c] (std::shared_ptr<Course> g) {return g == c;});
}

