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
        int                 ects, semester, enrolled;
        bool                mandatory;

    public:

        
        int                 get_semester();
        string              get_name();
        int                 get_ects();
        string              get_serialno();
        bool                get_mandatory();
        int                 get_enrolled();
        int                 get_passed();           

        void                set_semester(int);
        void                set_name(string);
        void                set_ects(int);
        void                set_serialno(string);
        void                set_mandatory(bool);
        void                set_enrolled(int);

        Course(string name= NO_NAME, string serialno= NO_SERIAL,
                int ects= NO_ECTS, int semester= NO_SEMESTER, bool mandatory= NO_MANDATORY);

        ~Course();

};


#endif