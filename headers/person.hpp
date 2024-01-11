#ifndef __PERSON_HPP_DEFINED__
#define __PERSON_HPP_DEFINED__

#include <iostream>
#include <ostream>
#include <string>

using std::string;

#define NO_NAME "DEFAULT" 
#define NO_SUR "DEFAULT"
#define NO_MAIL "DEFAULT"   
#define NO_REG "DEFAULT"
#define NO_BIRTHYEAR 0 


class Person{

    private:
        static int count;        
        string name, surname, email, reg_num;
        int birthyear;

    public:
        
        string      get_name() const;
        void        set_name(string);

        string      get_surname() const;
        void        set_surname(string);
        
        string      get_regnum() const;
        void        set_regnum(string);
        
        string      get_email() const; 
        void        set_email(string);
        
        int         get_birthyear() const;
        void        set_birthyear(int);
        
        static int  get_total_counter();
        static void decrease_count();

        friend      std::ostream& operator<< (std::ostream&, const Person &);  

        

        Person (string name= NO_NAME, 
                string surname = NO_SUR, 
                string reg_num = NO_REG, 
                string email = NO_MAIL,
                int birthyear = NO_BIRTHYEAR);

        ~Person();

        
                
};

#endif