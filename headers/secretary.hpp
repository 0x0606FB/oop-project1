#ifndef __SECRETARY_HPP_INCLUDED__
#define __SECRETARY_HPP_INCLUDED__

#include <iostream>
#include <vector>
#include "./person.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Secretary {

    private:
        vector<Person *> personvec;
        
        
    public:
        
        void   add_person();
        void   add_person(Person*);

        void   dump() const;

        string find_person(void);
        string find_person(const int);
        
        Secretary& operator+ (Person*);

        Secretary();

        Secretary operator=(const Secretary&);

        Secretary(const Secretary &secr);

        ~Secretary();
};

#endif