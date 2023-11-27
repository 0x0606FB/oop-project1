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
        
        void add_person();
        void add_person(Person*);

        void dump() const;

        bool find_person(Person&);
        
        Secretary operator+ (Person*);
        // Secretary operator= (Secretary);


        Secretary();
        
        Secretary(const Secretary &secr);

        ~Secretary();
};