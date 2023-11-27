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

//Copy constructor.
Secretary::Secretary(const Secretary &secr){


    for (Person *p : secr.personvec) { 
        Person *p1 = new Person;
        p1->set_name(p->get_name());
        p1->set_surname(p->get_surname());
        p1->set_email(p->get_email());
        p1->set_regnum(p->get_regnum());
        p1->set_age(p->get_age());

        this->personvec.push_back(p1);
    }


    // for(int i = 0; i < secr.personvec.size(); i++){ 
    //     this->personvec.push_back(secr.personvec.at(i));
    // }
    cout << "Custom copy constructor" << '\n';

}


//Overloading function for the "+" operator.
Secretary Secretary::operator+(Person *p) {
    this->add_person(p);
    return *this;
}

// //Overloading function for the "=" operator.
// Secretary Secretary::operator=(Secretary secr) {
//     Secretary secretarycreated(secr);
//     return secretarycreated;
// }


