#ifndef __STUDENT_HPP_INCLUDED__
#define __STUDENT_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"
#include <vector>

using std::vector;

typedef struct {

    Course   *course;
    float     grade;

} grade_per_student;

class Student : public Person {

    private:
        int     semester, ects;
        vector<grade_per_student> grades;
        bool    passed;

    public:

        void        set_semester(int);
        void        set_ects(int);
        void        set_passed(bool);

        int         compute_ects();
        bool        completed_mandatories();
        void        get_grades(bool);
        void        update_ects();
        bool        can_graduate();
        int         get_semester();
        


};



#endif