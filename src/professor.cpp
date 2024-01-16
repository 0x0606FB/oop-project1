#include "./../headers/professor.hpp"
#include <algorithm>
#include <memory>
#include <list>
using std::cin;
using std::cout;
using std::endl;


Professor::Professor(){};
Professor::~Professor(){};


void Professor::assign_to_course(std::shared_ptr<Course> c){
    
    auto iterator = std::find_if(this->courselist.begin(), this->courselist.end(), 
                                        [c] (std::shared_ptr<Course> c1) {return c == c1;});
    
    if (iterator != this->courselist.end()) {
        cout << "ERROR: Professor has already been assigned to this course." << endl;
        return;
    }
    
    this->courselist.push_front(c);
}

void Professor::drop_course(std::shared_ptr<Course> c){
    this->courselist.remove(c);
}

void Professor::print_stats() const{
    for(auto &p: this->courselist){
        
        cout << "Course Name: " << p->get_name() << endl;
        cout << "Course ID: " << p->get_serialno() << endl;
        cout << "Students Enrolled:" << p->get_enrolled() << endl;

    }
}

void grade_student(std::shared_ptr<Student> s, std::shared_ptr<Course> c){
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

void     Professor::dump_courses () const {
    for (auto &c : this->courselist) {
        cout << c->get_name() << "  :  " << c->get_serialno() << endl;
        cout << "______________________________" << endl;
        cout << "Semester " << c->get_semester() << endl;
    }
}


void     Professor::cleanup(std::shared_ptr<Course> c) {
    this->courselist.remove_if([c] (std::shared_ptr<Course> g) {return g == c;});
}

