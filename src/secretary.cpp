#include "./../headers/secretary.hpp"

using std::cout;
using std::cin;
using std::string;

void        Secretary::add_person(Person&) {
                
}


Secretary Secretary::operator+(Person p) {

    this->add_person(p);

    return *this;


}


