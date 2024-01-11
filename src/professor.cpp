#include "./../headers/professor.hpp"

Professor::Professor(){};
Professor::~Professor(){};


void Professor::assign_to_course(std::shared_ptr<Course> c){
    this->courselist.push_front(c);
}

void Professor::drop_course(std::shared_ptr<Course> c){
    this->courselist.remove(c);
}
