#include "./../headers/secretary.hpp"

using std::cout;
using std::cin;
using std::string;

void        Secretary::add_person(Person& p) {
    this->personvec.push_back(&p);
}

bool Secretary::find_person(Person p){
    this->personvec. //psaxnw tis methodous pou exei to personvec alla den vriskw tipota tou typou find
}


Secretary Secretary::operator+(Person p) {

    this->add_person(p);

    return *this;


}


