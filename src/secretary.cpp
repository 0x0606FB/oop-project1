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
    int age;

    cout << "Enter name: " << endl;
    cin >> buffer;
    p->set_name(buffer);
    buffer.clear();
    
    cout << "Enter surname: " << endl;
    cin >> buffer;
    p->set_surname(buffer);
    buffer.clear();
    
    cout << "Enter registry number: " << endl;
    cin >> buffer;
    p->set_regnum(buffer);
    buffer.clear();
    
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
void        Secretary::add_person(Person *p) {
    this->personvec.push_back(p);
}


//Find function (???)
// bool        Secretary::find_person(Person& p){
//     if (std::find(this->personvec.begin(), this->personvec.end(), p) != this->personvec.end()) { return true; }
//     return false;
// }

//Dumps all entries of the secretary vector via iterator.
void        Secretary::dump() const{
    for (auto p : this->personvec) { cout << *p; }
}

//Constructor and destructor.
Secretary::Secretary() {}   
Secretary::~Secretary() {
}

//Overloading function for the "+" operator.
Secretary Secretary::operator+(Person *p) {
    this->add_person(p);
    return *this;
}


