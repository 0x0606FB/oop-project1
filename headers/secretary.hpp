#ifndef __SECRETARY_HPP_INCLUDED__
#define __SECRETARY_HPP_INCLUDED__

#include <iostream>
#include <vector>
#include <list>
#include "./person.hpp"
#include "./student.hpp"
#include "./professor.hpp"
#include "course.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;

class Secretary {

    private:
        list<Student *>   studentlist;
        list<Professor *> professorlist;
        list<Course *>    courselist;
        int               mandatoryno;
        
        
    public:
        
        template <typename T> void   add_person();

        void                         add_course();

        template <typename T> void   dump() const;

        template <typename T> T*     find(string);

        void                         update_mandatoryno();

        static int                          get_mandatoryno();                        
        // string find_person(const int);

        friend bool Student::completed_mandatories();
        
        Secretary& operator+ (Person*);

        Secretary();

        Secretary operator=(const Secretary&);

        Secretary(const Secretary &secr);

        ~Secretary();
};

#endif