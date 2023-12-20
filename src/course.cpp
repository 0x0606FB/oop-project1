#include "./../headers/course.hpp"

void  Course::change_semester(int new_semester)     { Course::semester = new_semester; }
void  Course::change_name(string new_name)          { Course::name = new_name; }
void  Course::change_ects(int new_ects)             { Course::ects = new_ects; }
void  Course::change_serialno(string new_serialno)  { Course::serialno = new_serialno; }
void  Course::change_mandatory(bool new_mandatory)  { Course::mandatory = new_mandatory; }
