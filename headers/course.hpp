#ifndef __COURSE_HPP_INCLUDED__
#define __COURSE_HPP_INCLUDED__

#include <string>

#define NO_NAME "DEFAULT" 
#define NO_SERIAL "DEFAULT"
#define NO_ECTS 0   
#define NO_SEMESTER 0
#define NO_MANDATORY false 


using std::string;

class   Course {

    private:
        string              name, serialno;
        int                 ects, semester;
        bool                mandatory;

    public:

        void                change_semester(int);
        void                change_name(string);
        void                change_ects(int);
        void                change_serialno(string);
        void                change_mandatory(bool);

        Course(string name= NO_NAME, string serialno= NO_SERIAL,
                int ects= NO_ECTS, int semester= NO_SEMESTER, bool mandatory= NO_MANDATORY);

        ~Course();

};


#endif