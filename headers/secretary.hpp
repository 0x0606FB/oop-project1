#ifndef __SECRETARY_HPP_INCLUDED__
#define __SECRETARY_HPP_INCLUDED__

#include <iostream>
#include <vector>
#include "./person.hpp"
#include "./student.hpp"
#include "./professor.hpp"
#include "course.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Secretary {

    private:
        vector<Student *>   studentvec;
        vector<Professor *> professorvec;
        vector<Course *>    coursevec;
        
        
    public:
        
        void   add_person();
        void   add_person(Person*);

        void   dump() const;

        string find_person(void);
        string find_person(const int);

        friend bool Student::completed_mandatories();
        
        Secretary& operator+ (Person*);

        Secretary();

        Secretary operator=(const Secretary&);

        Secretary(const Secretary &secr);

        ~Secretary();
};

#endif