#include "./../headers/professor.hpp"
#include <memory>
using std::cout;
using std::endl;


Professor::Professor(){};
Professor::~Professor(){};


void Professor::assign_to_course(std::shared_ptr<Course> c){

    
    if(this->courselist->find_if()                              ){
        this->courselist.push_front(c);
    }
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

void     Professor::cleanup(std::shared_ptr<Course> c) {
    this->courselist.remove_if([c] (std::shared_ptr<Course> g) {return g == c;});
}