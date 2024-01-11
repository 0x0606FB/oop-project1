#include "./../headers/professor.hpp"
#include <memory>

Professor::Professor(){};
Professor::~Professor(){};


void Professor::assign_to_course(std::shared_ptr<Course> c){
    this->courselist.push_front(c);
}

void Professor::drop_course(std::shared_ptr<Course> c){
    this->courselist.remove(c);
}

void Professor::grade_student(std::shared_ptr<Student>, std::shared_ptr<Course>) {


}
