#ifndef __STUDENT_HPP_INCLUDED__
#define __STUDENT_HPP_INCLUDED__

#include "./person.hpp"
#include "./course.hpp"
#include "./professor.hpp"
#include <future>
#include <memory>
#include <vector>
#include <list>


using std::vector;
using std::list;

typedef struct {

    std::shared_ptr<Course>     course;
    float                       grade;
    bool                        counted;
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
        bool        completed_mandatories(int) const;
        void        get_grades(bool) const;
        bool        get_passed() const;
        void        update_ects();
        bool        can_graduate(int) const;
        int         get_semester() const;
        int         get_ects() const;
        void        enroll(std::shared_ptr<Course>);
        void        cleanup(std::shared_ptr<Course>);
        bool        has_passed(std::shared_ptr<Course>) const;


        friend void Professor::grade_student(std::shared_ptr<Student>, std::shared_ptr<Course>);
        
        Student(int semester= 0, int ects= 0, bool passed= false);
        ~Student();



       


};



#endif