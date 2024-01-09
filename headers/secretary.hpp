#ifndef __SECRETARY_HPP_INCLUDED__
#define __SECRETARY_HPP_INCLUDED__

#include <iostream>
#include <list>
#include "./person.hpp"
#include "./student.hpp"
#include "./professor.hpp"
#include "./course.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::list;

class Secretary {

    private:
        list<Student *>   studentlist;
        list<Professor *> professorlist;
        list<Course *>    courselist;
        int               mandatoryno;
        
        
    public:
        
        void                         menu();

        template <typename T> void   add_person();

        void                         add_course();

        template <typename T> void   dump();

        template <typename T> T*     find(string);

        void                         update_mandatoryno();

        static int                   get_mandatoryno();                        
        // string find_person(const int);

        friend bool Student::completed_mandatories() const;
        
        Secretary& operator+ (Person*);

        Secretary();

        Secretary operator=(const Secretary&);

        Secretary(const Secretary &secr);

        ~Secretary();
};

#endif