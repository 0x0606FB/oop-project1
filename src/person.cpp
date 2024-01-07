#include "./../headers/person.hpp"
#include <iostream>

using std::endl;
using std::string;


//Accessor functions for the Person class
string  Person::get_name()       const { return name; } 
string  Person::get_surname()    const { return surname; } 
string  Person::get_email()      const { return email; } 
string  Person::get_regnum()     const { return reg_num; } 
int     Person::get_age()        const { return age; }
int     Person::get_total_counter()    { return count; } 


//Mutator functions for the Person class
void    Person::set_name(string new_name)       { Person::name = new_name; }
void    Person::set_surname(string new_surname) { Person::surname = new_surname; }
void    Person::set_regnum(string new_regnum)   { Person::reg_num = new_regnum; }
void    Person::set_email(string new_email)     { Person::email = new_email; }
void    Person::set_age(int new_age)            { age = new_age; }

void    Person::decrease_count()                { Person::count--;}

    
//Overloading the "<<" operator
std::ostream& operator<< (std::ostream& stream, const Person &p){

    stream << "Name:                  " << p.get_name()       << endl 
           << "Surname:               " << p.get_surname()    << endl
           << "Registration Number:   " << p.get_regnum()     << endl
           << "Email:                 " << p.get_email()      << endl
           << "Age:                   " << p.get_age()        << endl
           << "____________________   " <<                       endl;

    return stream;
}


//Defining constructor and destructor 
Person::Person(string name_, 
                string surname_, 
                string    reg_num_, 
                string email_, int age_) : name(name_), surname(surname_), reg_num(reg_num_), email(email_), age(age_) { this->count++;}

int Person::count = 0;

Person::~Person(){this->count--;}