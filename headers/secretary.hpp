#ifndef __SECRETARY_HPP_INCLUDED__
#define __SECRETARY_HPP_INCLUDED__

#include <iostream>
#include <list>
#include <memory>
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
        list<std::shared_ptr<Student>>   studentlist;
        list<std::shared_ptr<Professor>> professorlist;
        list<std::shared_ptr<Course>>    courselist;
        int               mandatoryno;
        
        
    public:
        
        void                         menu();

        template <typename T> void   add_person();

        void                         add_course();

        template <typename T> void   dump();

        template <typename T> std::shared_ptr<T>     find(string);

        void                         update_mandatoryno();

        int                   get_mandatoryno();

        friend bool Student::completed_mandatories(int) const;
        
        Secretary& operator+ (Person*);

        Secretary();

        Secretary operator=(const Secretary&);

        Secretary(const Secretary &secr);

        ~Secretary();
};

#endif