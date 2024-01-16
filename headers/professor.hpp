#ifndef __PROFESSOR_HPP_INCLUDED__
#define __PROFESSOR_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"
#include "./student.hpp"

#include <list>
#include <memory>

using std::list;

class   Professor : public Person {

    private:
        list<std::shared_ptr<Course>> courselist;


    public:

        void            assign_to_course(std::shared_ptr<Course>);
        void            drop_course(std::shared_ptr<Course>);
        void            print_stats(void) const;
        void            grade_student(std::shared_ptr<Student>, std::shared_ptr<Course>);
        void            dump_courses() const;
        void            cleanup(std::shared_ptr<Course>);
        
        Professor();
        ~Professor();

};


#endif