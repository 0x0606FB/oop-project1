#include <iostream>
#include <ostream>
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
        
        void add_person(Person&);

        bool find_person(Person);
        
        Secretary operator+ (Person);

        Secretary();
        
        
        ~Secretary();
};