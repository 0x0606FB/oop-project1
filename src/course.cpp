#include "./../headers/course.hpp"

void                Course::set_semester(int new_semester)     {Course::semester = new_semester;}
void                Course::set_name(string new_name)          {Course::name = new_name;}
void                Course::set_ects(int new_ects)             {Course::ects = new_ects;}
void                Course::set_serialno(string new_serialno)  {Course::serialno = new_serialno;}
void                Course::set_mandatory(bool new_mandatory)  {Course::mandatory = new_mandatory;}


int                 Course::get_semester()                      {return this->semester;}
string              Course::get_name()                          {return this->name;}
int                 Course::get_ects()                          {return this->ects;}
string              Course::get_serialno()                      {return this->serialno;}
bool                Course::get_mandatory()                     {return this->mandatory;}