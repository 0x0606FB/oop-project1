#include "./../headers/secretary.hpp"
#include <typeinfo>
#include <algorithm>
#include <iterator>

using std::cout;
using std::cin;
using std::string;


//Basic add person function.
template <typename T>
void        Secretary::add_person() {
    T *p = new T();
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

    if (typeid(T) == typeid(Student)) { 
        this->studentvec.push_back(p);
    } else {
        this->coursevec.push_back(p);
    }

}




//Find person function based on registry number.
template <typename T>
string        Secretary::find_person() {
    cout << "Please give registry number (integer):" << endl;
    int r;
    cin >> r;

    

    if (typeid(T) == typeid(Student)){
        auto this_ = this->studentvec;
    } else {
        auto this_ = this->professorvec;
    }

    for (auto & p : this_) {

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


