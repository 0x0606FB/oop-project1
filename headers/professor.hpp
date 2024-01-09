#ifndef __PROFESSOR_HPP_INCLUDED__
#define __PROFESSOR_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"

#include <list>

using std::list;

class   Professor : public Person {

    private:
        list<Course *> courselist;


    public:

        void            assign_to_course(Course *);
        void            print_stats(void) const;
        // void         grade

        Professor();
        ~Professor();

};


#endif