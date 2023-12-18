#include "./../headers/secretary.hpp"
#include <algorithm>
#include <iterator>

using std::cout;
using std::cin;
using std::string;


//Basic add person function.
void        Secretary::add_person() {
    Person *p = new Person();
    string buffer;
    int reg_num, age;

    cout << "Enter name: " << endl;
    cin >> buffer;
    p->set_name(buffer);
    buffer.clear();
    
    cout << "Enter surname: " << endl;
    cin >> buffer;
    p->set_surname(buffer);
    buffer.clear();
    
    cout << "Enter registry number: " << endl;
    cin >> reg_num;
    p->set_regnum(reg_num);
    
    cout << "Enter email: " << endl;
    cin >> buffer;
    p->set_email(buffer);
    buffer.clear();
    
    cout << "Enter age: " << endl;
    cin >> age;
    p->set_age(age);

    this->personvec.push_back(p);
}


//Oveload function to simply push back a pointer to an already created person.
void          Secretary::add_person(Person *p) { this->personvec.push_back(p); }


//Find person function based on registry number.
string        Secretary::find_person(void) {
    cout << "Please give registry number (integer):" << endl;
    int r;
    cin >> r;
    for (auto & p : this->personvec) {

        if (p->get_regnum() == r) {
            return "Person exists.\n";
        } 
    }
    return "Person does not exist.\n";
} 


//Overload of above function to be called with the reg number as parameter.
string        Secretary::find_person(const int r) {
    for (auto & p : this->personvec) {
        
        if (p->get_regnum() == r) {
            return "Person exists.\n";
        }
    }
    return "Person does not exist.\n";
}


//Dumps all entries of the secretary vector via iterator.
void        Secretary::dump() const{
    for (const auto p : this->personvec) { cout << *p; }
}


//Constructor and destructor.
Secretary::Secretary() {}   
Secretary::~Secretary() { for (auto & p : this->personvec) {delete p;} }


//Copy constructor.
Secretary::Secretary(const Secretary &secr){

    for (Person *p : secr.personvec) { 
        Person *p1 = new Person;
        
        Person::decrease_count();
        p1->set_name(p->get_name());
        p1->set_surname(p->get_surname());
        p1->set_email(p->get_email());
        p1->set_regnum(p->get_regnum());
        p1->set_age(p->get_age());

        this->personvec.push_back(p1);
    }

}


//Overloading function for the "+" operator.
Secretary& Secretary::operator+(Person *p) {
    this->add_person(p);
    return *this;
}


//Overloading function for the "=" operator.
Secretary Secretary::operator=(const Secretary &secr) {
    Secretary secretarycreated(secr);
    return secretarycreated;
}


