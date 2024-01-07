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
        cout << "Enter Semester: " << endl;
        cin >> buffer;
        p->set_semester(buffer);
        buffer.clear();

        p->set_ects(0);
        p->set_passed(false);

        this->studentlist.push_front(p);
    } else {
        // to add professor specifics
        this->professorlist.push_front(p);
    }
}

void        Secretary::add_course(void){

    Course *c = new Course();
    string buffer;
    int    buffer1;
    bool   buffer2;

    cout << "Enter Course Name: " << endl;
    cin >> buffer;
    c->set_name(buffer);
    buffer.clear();

    cout << "Enter Course Serial Number: " << endl;
    cin >> buffer;
    c->set_serialno(buffer);
    buffer.clear();

    cout << "Enter Course ECTS: " << endl;
    cin >> buffer1;
    c->set_ects(buffer1);

    cout << "Enter Course Semester: " << endl;
    cin >> buffer1;
    c->set_semester(buffer1);

    cout << "Enter Course Mandatory Status (0 false, 1 true): " << endl;
    cin >> buffer2;
    c->set_mandatory(buffer2);
    
    this->courselist.push_front(c);
}



//Find person function based on registry number.
template <typename T>
T*        Secretary::find(string s) {


    if (typeid(T) == typeid(Student)){
        for (auto & p : this->studentlist) {

            if (!s.compare(p->get_regnum())) {
                return p;            
            } 
        }
        return NULL;        
    }

    if (typeid(T) == typeid(Professor)) {
        for (auto & p : this->professorlist) {

            if (!s.compare(p->get_regnum())) {
                return p;
            } 
        }
    return NULL;
    }

    
    for (auto & p : this->courselist) {

        if (!s.compare(p->get_serialno())) {
                return p;
            } 
        }
    return NULL;
} 




// //Dumps all entries of the secretary vector via iterator.
// template <typename T>
// void        Secretary::dump() const{
//     if (typeid(T) == typeid(Student)){
//         for (const auto p : this->studentvec) { cout << *p; }
//     } else {
//         for (const auto p : this->professorvec) { cout << *p; }
//     }
// }


//Constructor and destructor.
Secretary::Secretary() {}   
Secretary::~Secretary() {   for (auto & p : this->studentlist) {delete p;}
                            for (auto & p : this->professorlist) {delete p;}
                            for (auto & p : this->courselist) {delete p;}}


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


