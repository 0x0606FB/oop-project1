#ifndef __STUDENT_HPP_INCLUDED__
#define __STUDENT_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"
#include <vector>
#include <list>

using std::vector;
using std::list;

typedef struct {

    Course   *course;
    float     grade;

} grade_per_student;

class Student : public Person {

    private:
        int     semester, ects;
        list<grade_per_student> grades;
        bool    passed;

    public:

        void        set_semester(int);
        void        set_ects(int);
        void        set_passed(bool);

        int         compute_ects();
        bool        completed_mandatories() const;
        void        get_grades(bool) const;
        void        update_ects();
        bool        can_graduate() const;
        int         get_semester() const;
        void        enroll(Course *);
        


};



#endif