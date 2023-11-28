#include <iostream>
#include <ostream>
#include <string>

using std::string;

#define NO_NAME "DEFAULT" 
#define NO_SUR "DEFAULT"
#define NO_MAIL "DEFAULT"   
#define NO_REG 0
#define NO_AGE 0 


class Person{

    private:
        static int count;        
        string name, surname, email;
        int age, reg_num;

    public:
        
        string      get_name() const;
        void        set_name(string);

        string      get_surname() const;
        void        set_surname(string);
        
        int         get_regnum() const;
        void        set_regnum(int);
        
        string      get_email() const; 
        void        set_email(string);
        
        int         get_age() const;
        void        set_age(int);
        
        static int  get_total_counter();

        friend      std::ostream& operator<< (std::ostream&, const Person);  

        

        Person (string name= NO_NAME, 
                string surname = NO_SUR, 
                int    reg_num = NO_REG, 
                string email = NO_MAIL,
                int age = NO_AGE);

        ~Person();

        
                
};