#include "./../headers/person.hpp"
#include "./../headers/secretary.hpp"

class Secretary {

    private:
        vector<Person *> personvec;
        
        
    public:
        
        void add_person(Person &p){

            
            personvec.push_back(&p);


        };
        
        

        Secretary();
        
        
        ~Secretary();
};

