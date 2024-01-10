#include <algorithm>
#include <exception>
#include <iterator>
#include <memory>
#include <type_traits>
#include <typeinfo>

#include "./../headers/secretary.hpp"

using std::cin;
using std::cout;
using std::shared_ptr;
using std::string;

// Basic add person function.
template <typename T>
void Secretary::add_person() {
  shared_ptr<T> p(new T());
  string buffer, reg_num;
  int age;

  cout << "Enter name: " << endl;
  cin >> buffer;
  p->set_name(buffer);
  buffer.clear();

  cout << "Enter surname: " << endl;
  cin >> buffer;
  p->set_surname(buffer);
  buffer.clear();

  cout << "Enter registry number: " << endl;
  cin >> reg_num;
  p->set_regnum(reg_num);

  cout << "Enter email: " << endl;
  cin >> buffer;
  p->set_email(buffer);
  buffer.clear();

  cout << "Enter age: " << endl;
  cin >> age;
  p->set_age(age);

  if constexpr (std::is_same_v<T, Student>) {
    cout << "Enter Semester: " << endl;
    cin >> age;
    p->set_semester(age);
    buffer.clear();

    p->set_ects(0);
    p->set_passed(false);

    this->studentlist.push_front(p);
  } else {
    // to add professor specifics
    this->professorlist.push_front(p);
  }
}

void Secretary::add_course(void) {
  shared_ptr<Course> c(new Course());
  string buffer;
  int buffer1;
  bool buffer2;

  cout << "Enter Course Name: " << endl;
  cin >> buffer;
  c->set_name(buffer);
  buffer.clear();

  cout << "Enter Course Serial Number: " << endl;
  cin >> buffer;
  c->set_serialno(buffer);
  buffer.clear();

  cout << "Enter Course ECTS: " << endl;
  cin >> buffer1;
  c->set_ects(buffer1);

  cout << "Enter Course Semester: " << endl;
  cin >> buffer1;
  c->set_semester(buffer1);

  cout << "Enter Course Mandatory Status (0 false, 1 true): " << endl;
  cin >> buffer2;
  c->set_mandatory(buffer2);

  c->set_enrolled(0);

  this->courselist.push_front(c);
}

// Find person function based on registry number.
template <typename T>
shared_ptr<T> Secretary::find(string s) {
  if constexpr (std::is_same_v<T, Student>) {
    for (auto &p : this->studentlist) {
      if (!s.compare(p->get_regnum())) {
        return p;
      }
    }
    return NULL;
  } else if constexpr (std::is_same_v<T, Professor>) {
    for (auto &p : this->professorlist) {
      if (!s.compare(p->get_regnum())) {
        return p;
      }
    }
    return NULL;
  } else if constexpr (std::is_same_v<T, Course>) {
    for (auto &p : this->courselist) {
      if (!s.compare(p->get_serialno())) {
        return p;
      }
    }
    return NULL;
  }
}

// // Dumps all entries of the secretary vector via iterator.
// template <typename T> void Secretary::dump() {
//   if constexpr (std::is_same_v<T, Student>) {
//     for (const auto p : this->studentlist) {
//       cout << *p;
//     }
//   } else {
//     for (const auto p : this->professorlist) {
//       cout << *p;
//     }
//   }
// }

int Secretary::get_mandatoryno() { return 1; }

// Constructor and destructor.
Secretary::Secretary() {}
Secretary::~Secretary() {
  // for (auto &p : this->studentlist) {
  //   delete p;
  // }
  // for (auto &p : this->professorlist) {
  //   delete p;
  // }
  // for (auto &p : this->courselist) {
  //   delete p;
  // }
}

// Copy constructor.
//  Secretary::Secretary(const Secretary &secr){

//     for (Person *p : secr.personvec) {
//         Person *p1 = new Person;

//         Person::decrease_count();
//         p1->set_name(p->get_name());
//         p1->set_surname(p->get_surname());
//         p1->set_email(p->get_email());
//         p1->set_regnum(p->get_regnum());
//         p1->set_age(p->get_age());

//         this->personvec.push_back(p1);
//     }

// }

// //Overloading function for the "+" operator.
// Secretary& Secretary::operator+(Person *p) {
//     this->add_person(p);
//     return *this;
// }

// Overloading function for the "=" operator.
// Secretary Secretary::operator=(const Secretary &secr) {
//     Secretary secretarycreated(secr);
//     return secretarycreated;
// }

bool continueop(void) {
  cout << "Do you want to continue with the operation? (Y/N)" << endl;
  string input;
  cin >> input;
  if (!input.compare("y") || !input.compare("Y")) {
    return true;
  } else {
    return false;
  }
}

void Secretary::menu() {
  while (1) {
    string userInput1, buffer;
    bool check = false;
    cin.clear();
    userInput1.clear();
    while (!check) {
      try {
        cout << "Press 1 for Professor options, 2 for Student options, 3 for Course options, 0 to quit menu" << endl;
        cin >> userInput1;
        if (userInput1.compare("1") && userInput1.compare("2") && userInput1.compare("3") && userInput1.compare("0")) {
          throw "False Value.\n";
        } else if (!userInput1.compare("0")) {
          throw 0;
        }
        check = true;
      } catch (const char s[]) {
        cout << s;
      } catch (const int quit) {
        cout << "Are you sure you want to quit? (Y/N)" << endl;
        cin >> userInput1;
        if (!userInput1.compare("y") || !userInput1.compare("Y")) {
          return;
        }
      }
    }

    if (!userInput1.compare("1")) {
      check = false;
      userInput1.clear();

      while (!check) {
        try {
          cout << "PROFESSOR OPTIONS: Enter 'add', 'change' or 'remove', 'stats' or 'back' to go back (case sensitive)" << endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") && userInput1.compare("remove") && userInput1.compare("stats") && userInput1.compare("back")) {
            throw "False Expression.\n";
          }
          check = true;
        } catch (const char s[]) {
          cout << s;
        }
      }

      if (userInput1.compare("back")) {
        if (continueop()) {
          if (!userInput1.compare("add")) {
            cout << "// ADD PROFESSOR TO UNIVERSITY ///////" << endl;
            this->add_person<Professor>();
            cin.clear();
            for (auto &p : this->professorlist) {
              cout << p->get_age() << endl;
              cout << p->get_name() << endl;
              cout << p->get_email() << endl;
              cout << p->get_surname() << endl;
              cout << "----------------" << endl;
            }
          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE STUDENT DETAILS: Enter 'name', 'surname', 'age', 'email', 'registry' (case sensitive)" << endl;
                cin >> userInput1;
                if (userInput1.compare("name") && userInput1.compare("surname") && userInput1.compare("age") && userInput1.compare("email") && userInput1.compare("registry")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }

            cout << "Enter professor's registration number:" << endl;
            cin >> buffer;
            shared_ptr<Professor> professor = this->find<Professor>(buffer);

            if (!userInput1.compare("name")) {
              cout << "// CHANGE PROFESSOR NAME //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Name:" << professor->get_name() << "     Change Name To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              professor->set_name(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("surname")) {
              cout << "// CHANGE PROFESSOR SURNAME //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Surname:" << professor->get_name() << "     Change Surname To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              professor->set_surname(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("age")) {
              int buffer1;
              cout << "// CHANGE PROFESSOR AGE //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Age:" << professor->get_age() << "     Change Age To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer1;
              professor->set_age(buffer1);
            }
            if (!userInput1.compare("email")) {
              cout << "// CHANGE PROFESSOR EMAIL //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Email:" << professor->get_email() << "     Change Email To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              professor->set_email(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("registry")) {
              cout << "// CHANGE PROFESSOR REGISTRY NUMBER //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Registry Number:" << professor->get_regnum() << "     Change Registry Number To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              professor->set_regnum(buffer);
              buffer.clear();
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE PROFESSOR  ///////" << endl;
          } else if (!userInput1.compare(("stats"))) {
            cout << "// PRINT PROFESSOR STATS FOR EACH COURSE UNDERTAKEN //////" << endl;
          }
        }
      }
    }

    else if (!userInput1.compare("2")) {
      check = false;
      userInput1.clear();

      while (!check) {
        try {
          cout << "STUDENT OPTIONS: Enter 'add', 'change', 'remove', 'register', 'stats', 'graduate' or 'back' to go back (case sensitive)" << endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") && userInput1.compare("remove") && userInput1.compare("register") && userInput1.compare("graduate") &&
              userInput1.compare("back")) {
            throw "False Expression.\n";
          }
          check = true;
        } catch (const char s[]) {
          cout << s;
        }
      }

      if (userInput1.compare("back")) {
        if (continueop()) {
          if (!userInput1.compare("add")) {
            cout << "// ADD STUDENT TO UNIVERSITY ///////" << endl;
            this->add_person<Student>();
            cin.clear();
            for (auto &p : this->studentlist) {
              cout << p->get_age() << endl;
              cout << p->get_semester() << endl;
              cout << p->get_name() << endl;
              cout << p->get_email() << endl;
              cout << p->get_surname() << endl;
              cout << p->get_ects() << endl;
              cout << p->get_semester() << endl;
              cout << "----------------" << endl;
            }
          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE STUDENT DETAILS: Enter 'name', 'surname', 'age', 'email', 'registry', 'semester', 'ects', 'passed' (case sensitive)" << endl;
                cin >> userInput1;
                if (userInput1.compare("name") && userInput1.compare("surname") && userInput1.compare("age") && userInput1.compare("email") && userInput1.compare("registry") &&
                    userInput1.compare("semester") && userInput1.compare("ects") && userInput1.compare("passed")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }

            ////// ADD EXCEPTION HANDLING //////

            cout << "Enter student's registration number:" << endl;
            cin >> buffer;
            shared_ptr<Student> student = this->find<Student>(buffer);

            if (!userInput1.compare("name")) {
              cout << "// CHANGE STUDENT NAME //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Name:" << student->get_name() << "     Change Name To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              student->set_name(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("surname")) {
              cout << "// CHANGE STUDENT SURNAME //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Surname:" << student->get_surname() << "     Change Surname To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              student->set_surname(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("age")) {
              int buffer1;
              cout << "// CHANGE STUDENT AGE //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Age:" << student->get_age() << "     Change Age To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer1;
              student->set_age(buffer1);
            }
            if (!userInput1.compare("email")) {
              cout << "// CHANGE STUDENT EMAIL //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Email:" << student->get_email() << "     Change Email To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              student->set_email(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("registry")) {
              cout << "// CHANGE STUDENT REGISTRY NUMBER //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Registry Number:" << student->get_regnum() << "     Change Registry Number To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer;
              student->set_regnum(buffer);
              buffer.clear();
            }
            if (!userInput1.compare("ects")) {
              int buffer1;
              cout << "// CHANGE STUDENT ECTS //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current ECTS:" << student->get_ects() << "     Change ECTS To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> buffer1;
              student->set_ects(buffer1);
            }
            if (!userInput1.compare("passed")) {
              string pstatus = "FALSE";
              bool boolbuffer;
              if (student->get_passed() == true) {
                pstatus = "TRUE";
              }

              cout << "// CHANGE STUDENT PASSED STATUS //////" << endl;
              cout << "-------------------------" << endl;
              cout << "Current Passed Status:" << pstatus << "     Change Passed Status To ..... " << endl;
              cout << "-------------------------" << endl;
              cin >> boolbuffer;
              student->set_passed(boolbuffer);
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE STUDENT  ///////" << endl;

            cout << "Enter student's registration number:" << endl;
            cin >> buffer;

            this->studentlist.remove_if([&buffer](shared_ptr<Student> s) { return !s->get_regnum().compare(buffer); });

          } else if (!userInput1.compare("register")) {
            cout << "// REGISTER STUDENT TO COURSE //////" << endl;
            cout << "Give Student's register number:" << endl;
            cin >> buffer;
            shared_ptr<Student> s = this->find<Student>(buffer);

            cout << "Give Course's serial number:" << endl;
            cin >> buffer;
            shared_ptr<Course> c = this->find<Course>(buffer);

            s->enroll(c);
            buffer.clear();

          } else if (!userInput1.compare("stats")) {
            cout << "// PRINT A STUDENTS' STATS ///////" << endl;
            cout << "Give Student's register number:" << endl;
            cin >> buffer;

            shared_ptr<Student> s = this->find<Student>(buffer);

            buffer.clear();

            cout << "'current' for current semester, 'any' for any semester (case sensitive)" << endl;
            cin >> buffer;

            if (buffer == "current") {s->get_grades(false);} else {s->get_grades(true);}

            buffer.clear();

          } else if (!userInput1.compare("graduate")) {
            cout << "PRINT LIST OF STUDENTS WHO CAN GRADUATE ///////" << endl;
            for (auto &p : this->studentlist) {
              if (p->can_graduate()) {
                cout << "Graduated :    "  << p->get_name() << "" << p->get_surname() << endl;
                cout << "Registered as:"   << p->get_regnum() << endl;
                cout << "Congratulations!" << endl; 
              }
            }
          }
        }
      }
    }

    else if (!userInput1.compare("3")) {
      check = false;
      userInput1.clear();

      while (!check) {
        try {
          cout << "COURSE OPTIONS: Enter 'add', 'change' or 'remove', 'assign', 'export' or 'back' to go back (case sensitive)" << endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") && userInput1.compare("remove") && userInput1.compare("assign") && userInput1.compare("export") && userInput1.compare("back")) {
            throw "False Expression.\n";
          }
          check = true;
        } catch (const char s[]) {
          cout << s;
        }
      }

      if (userInput1.compare("back")) {
        if (continueop()) {
          if (!userInput1.compare("add")) {
            cout << "// ADD COURSE TO UNIVERSITY ///////" << endl;
            this->add_course();
            cin.clear();
            for (auto &p : this->courselist) {
              cout << p->get_name() << endl;
              cout << p->get_serialno() << endl;
              cout << p->get_ects() << endl;
              cout << p->get_semester() << endl;
              cout << p->get_enrolled() << endl;
              cout << "----------------" << endl;
            }
          
          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE COURSE DETAILS: Enter 'name', 'serialno', 'ects', 'semester', 'mandatory' (case sensitive)" << endl;
                cin >> userInput1;
                if (userInput1.compare("name") && userInput1.compare("serialno") && userInput1.compare("ects") && userInput1.compare("semester") && userInput1.compare("mandatory")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }
            if (!userInput1.compare("name")) {
              cout << "// CHANGE COURSE NAME //////" << endl;
            }
            if (!userInput1.compare("serialno")) {
              cout << "// CHANGE COURSE SERIALNO //////" << endl;
            }
            if (!userInput1.compare("ects")) {
              cout << "// CHANGE COURSE ECTS //////" << endl;
            }
            if (!userInput1.compare("semester")) {
              cout << "// CHANGE COURSE PASSED SEMESTER //////" << endl;
            }
            if (!userInput1.compare("mandatory")) {
              cout << "// CHANGE COURSE MANDATORY STATUS //////" << endl;
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE COURSE  ///////" << endl;
          } else if (!userInput1.compare("assign")) {
            cout << "// ASSIGN PROFESSOR TO COURSE  ///////" << endl;
          } else if (!userInput1.compare("export")) {
            cout << "// EXPORT A LIST OF STUDENTS WHO HAVE COMPLETED A COURSE  ///////" << endl;
          }
        }
      }
    }
  }
}