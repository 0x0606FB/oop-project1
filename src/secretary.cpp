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

void        Secretary::add_course(void){

    Course *c = new Course();
    string buffer;




}



//Find person function based on registry number.
template <typename T>
string        Secretary::find_person() {
    cout << "Please give registry number (integer):" << endl;
    int r;
    cin >> r;
    
    if (typeid(T) == typeid(Student)){
        for (auto & p : this->studentvec) {

            if (p->get_regnum() == r) {
                return "Person exists.\n";
            } 
        }
        return "Person does not exist.\n";        
    }

    for (auto & p : this->professorvec) {

        if (p->get_regnum() == r) {
            return "Person exists.\n";
        } 
    }
    return "Person does not exist.\n";

} 




//Dumps all entries of the secretary vector via iterator.
template <typename T>
void        Secretary::dump() const{
    if (typeid(T) == typeid(Student)){
        for (const auto p : this->studentvec) { cout << *p; }
    } else {
        for (const auto p : this->professorvec) { cout << *p; }
    }
}


//Constructor and destructor.
Secretary::Secretary() {}   
Secretary::~Secretary() {   for (auto & p : this->studentvec) {delete p;}
                            for (auto & p : this->professorvec) {delete p;}
                            for (auto & p : this->coursevec) {delete p;}}


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


