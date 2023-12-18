#ifndef __STUDENT_HPP_INCLUDED__
#define __STUDENT_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"
#include <vector>

using std::vector;

typedef struct {

    Course *course;
    int     grade;

} grade_per_student;

class Student : public Person {

    private:
        int     semester, ects;
        vector<grade_per_student> grades;
        bool    passed;

    public:

        void        change_semester(int);
        void        change_ects(int);

        bool        can_graduate();
        


};



#endif