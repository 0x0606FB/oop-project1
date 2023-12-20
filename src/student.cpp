#include "./../headers/student.hpp"


void Student::change_semester(int new_semester)   { Student::semester = new_semester; }
void Student::change_ects(int new_ects)           { Student::ects = new_ects; }
// bool Student::can_graduate() {//If student meets criteria return true, else return false//}