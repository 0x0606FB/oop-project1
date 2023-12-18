#ifndef __COURSE_HPP_INCLUDED__
#define __COURSE_HPP_INCLUDED__

#include <string>
#include <vector>
#include "./professor.hpp"

using std::string;
using std::vector;

class   Course {

    private:
        string              name;
        int                 ects, term;
        vector<Professor *> assigned; 

    public:


};


#endif