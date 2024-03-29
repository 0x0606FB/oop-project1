#include <algorithm>

#include <cstdio>

#include <exception>

#include <iterator>

#include <memory>

#include <sstream>

#include <string>

#include <type_traits>

#include <typeinfo>

#include <fstream>

#include "./../headers/secretary.hpp"

using std::cin;
using std::cout;
using std::shared_ptr;
using std::string;

int current_semester = 1;

// Basic add person function.
template < typename T > void Secretary::add_person() {
  shared_ptr < T > p(new T());
  string buffer, reg_num;
  int birthyear;

  cout << "Enter name: " << endl;
  cin >> buffer;
  p -> set_name(buffer);
  buffer.clear();

  cout << "Enter surname: " << endl;
  cin >> buffer;
  p -> set_surname(buffer);
  buffer.clear();

  cout << "Enter registry number: " << endl;
  cin >> reg_num;
  p -> set_regnum(reg_num);

  cout << "Enter email: " << endl;
  cin >> buffer;
  p -> set_email(buffer);
  buffer.clear();

  cout << "Enter birthyear: " << endl;
  cin >> birthyear;
  p -> set_birthyear(birthyear);

  if constexpr(std::is_same_v < T, Student > ) {
    cout << "Enter Semester: " << endl;
    cin >> birthyear;
    p -> set_semester(birthyear);
    buffer.clear();

    p -> set_ects(0);
    p -> set_passed(false);

    this -> studentlist.push_front(p);
  } else {
    // to add professor specifics
    this -> professorlist.push_front(p);
  }
}

void Secretary::add_course(void) {
  shared_ptr < Course > c(new Course());
  // Maybe EH //
  string buffer;
  int buffer1;
  bool buffer2;

  cout << "Enter Course Name: " << endl;
  cin >> buffer;
  c -> set_name(buffer);
  buffer.clear();

  cout << "Enter Course Serial Number: " << endl;
  cin >> buffer;
  c -> set_serialno(buffer);
  buffer.clear();

  cout << "Enter Course ECTS: " << endl;
  cin >> buffer1;
  c -> set_ects(buffer1);

  cout << "Enter Course Semester: " << endl;
  cin >> buffer1;
  c -> set_semester(buffer1);

  cout << "Enter Course Mandatory Status (0 false, 1 true): " << endl;
  cin >> buffer2;
  c -> set_mandatory(buffer2);

  c -> set_enrolled(0);

  this -> courselist.push_front(c);
}

// Find person function based on registry number.
template < typename T > shared_ptr < T > Secretary::find(string s) {
  if constexpr(std::is_same_v < T, Student > ) {
    for (auto & p: this -> studentlist) {
      if (!s.compare(p -> get_regnum())) {
        return p;
      }
    }
    return NULL;
  } else if constexpr(std::is_same_v < T, Professor > ) {
    for (auto & p: this -> professorlist) {
      if (!s.compare(p -> get_regnum())) {
        return p;
      }
    }
    return NULL;
  } else if constexpr(std::is_same_v < T, Course > ) {
    for (auto & p: this -> courselist) {
      if (!s.compare(p -> get_serialno())) {
        return p;
      }
    }
    return NULL;
  }
}

// Updates number of mandatory Courses (used to calculate whether a Student has passed all mandatory Courses).
void Secretary::update_mandatoryno(void) {
  int count = 0;
  for (auto & c: this -> courselist) {
    if (c -> get_mandatory() == true) {
      count++;
    }
  }
  this -> mandatoryno = count;
}

// Returns number of mandatory Courses.
int Secretary::get_mandatoryno() {
  this -> update_mandatoryno();
  return this -> mandatoryno;
}

// Constructor and destructor.
Secretary::Secretary() {}
Secretary::~Secretary() {}

// Used to confirm actions throughout the menu.
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

// File import function
// NOTE: Files should be in the following format:
// Course: name serialno ects semester enrolled mandatory
// Student: name surname email reg_num birthyear semester ects passed 
// Professor: name surname email reg_num birthyear
// Files should also be named "icourse.txt", "istudent.txt" and "iprofessor.txt" respectively.
// File path from secretary.cpp should be "./../import".
template < typename T > void Secretary::import(string im) {

  std::ifstream fin;
  fin.open(im, std::ios::in);

  if constexpr(std::is_same_v < T, Course > ) {

    while (fin) {

      string word;

      string name, serialno, mandatory, dummy;
      int ects, semester, enrolled;
      while (std::getline(fin, word)) {

        std::istringstream iss(word);

        iss >> name >> serialno >> ects >> semester >> enrolled >> mandatory;

        shared_ptr < T > t(new T());

        t -> set_name(name);
        t -> set_serialno(serialno);
        t -> set_ects(ects);
        t -> set_semester(semester);
        t -> set_enrolled(enrolled);
        if (mandatory == "true") {
          t -> set_mandatory(true);
        } else {
          t -> set_mandatory(false);
        }
        this -> courselist.push_back(t);
      }
    }
  } else if constexpr(std::is_same_v < T, Student > ) {

    while (fin) {

      string word;

      string name, surname, email, reg_num, passed;
      int birthyear, semester, ects;

      while (std::getline(fin, word)) {

        std::istringstream iss(word);

        iss >> name >> surname >> email >> reg_num >> birthyear >> semester >>
          ects >> passed;

        shared_ptr < T > t(new T());

        t -> set_name(name);
        t -> set_surname(surname);
        t -> set_email(email);
        t -> set_regnum(reg_num);
        t -> set_birthyear(birthyear);
        t -> set_semester(semester);
        t -> set_ects(ects);
        if (passed == "true") {
          t -> set_passed(true);
        } else {
          t -> set_passed(false);
        }
        this -> studentlist.push_back(t);
      }
    }
  } else {

    while (fin) {

      string word;

      string name, surname, email, reg_num;
      int birthyear;

      while (std::getline(fin, word)) {

        std::istringstream iss(word);

        iss >> name >> surname >> email >> reg_num >> birthyear;

        shared_ptr < T > t(new T());

        t -> set_name(name);
        t -> set_surname(surname);
        t -> set_email(email);
        t -> set_regnum(reg_num);
        t -> set_birthyear(birthyear);

        this -> professorlist.push_back(t);
      }
    }
  }
}

// DOCUMENTATION TBA !!!!!!!!!!!!!!! ////////////////////////////////////
void Secretary::menu() {

  string importbuf;
  string studentimportfile = "./../import/istudent.txt";
  string professorimportfile = "./../import/iprofessor.txt";
  string courseimportfile = "./../import/icourse.txt";

  cout << "Import Student Files? (Y/N)" << endl;
  cin >> importbuf;
  if (importbuf == "Y" || importbuf == "y") {
    cout << "Importing student files from" << studentimportfile << "..." <<
      endl;
    import < Student > (studentimportfile);
  }

  cout << "Import Professor Files? (Y/N)" << endl;
  cin >> importbuf;
  if (importbuf == "Y" || importbuf == "y") {
    cout << "Importing professor files from" << professorimportfile << "..." <<
      endl;
    import < Professor > (professorimportfile);
  }

  cout << "Import Course Files? (Y/N)" << endl;
  cin >> importbuf;
  if (importbuf == "Y" || importbuf == "y") {
    cout << "Importing course files from" << courseimportfile << "..." << endl;
    import < Course > (courseimportfile);
  }

  while (1) {
    string userInput1, buffer;
    bool check = false;
    cin.clear();
    userInput1.clear();
    cout << "Current Semester: " <<
      (current_semester == 1 ? "Winter" : "Summer") << endl;
    while (!check) {
      try { // Exception Handling for menu options
        cout << "Press 1 for Professor options, 2 for Student options, 3 for "
        "Course options, 4 to move to next semester, 0 to quit menu" <<
        endl;
        cin >> userInput1;
        if (userInput1.compare("1") && userInput1.compare("2") &&
          userInput1.compare("3") && userInput1.compare("4") &&
          userInput1.compare("0")) {
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
          cout << "PROFESSOR OPTIONS: Enter 'add', 'change' or 'remove', "
          "'grade' ,'stats' , 'assign' or 'back' to go back (case "
          "sensitive)" <<
          endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") &&
            userInput1.compare("remove") && userInput1.compare("stats") &&
            userInput1.compare("grade") && userInput1.compare("assign") &&
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
            cout << "// ADD PROFESSOR TO UNIVERSITY ///////" << endl;
            this -> add_person < Professor > ();
            cin.clear();
          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE PROFESSOR DETAILS: Enter 'name', 'surname', "
                "'birthyear', 'email', 'registry' (case sensitive)" <<
                endl;
                cin >> userInput1;
                if (userInput1.compare("name") &&
                  userInput1.compare("surname") &&
                  userInput1.compare("birthyear") &&
                  userInput1.compare("email") &&
                  userInput1.compare("registry")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }

            cout << "Enter professor's registration number:" << endl;
            cin >> buffer;
            shared_ptr < Professor > professor = this -> find < Professor > (buffer);
            while (professor == NULL) {
              buffer.clear();
              cout << "Professor not found. Do you want to try again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Professor's registration number:" << endl;
                cin >> buffer;
                professor = this -> find < Professor > (buffer);
              }
            }

            if (professor != NULL) {
              if (!userInput1.compare("name")) {
                cout << "// CHANGE PROFESSOR NAME //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Name:" << professor -> get_name() <<
                  "     Change Name To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                professor -> set_name(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("surname")) {
                cout << "// CHANGE PROFESSOR SURNAME //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Surname:" << professor -> get_name() <<
                  "     Change Surname To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                professor -> set_surname(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("birthyear")) {
                int buffer1;
                cout << "// CHANGE PROFESSOR BIRTHYEAR //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Birthyear:" << professor -> get_birthyear() <<
                  "     Change birthyear To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer1;
                professor -> set_birthyear(buffer1);
              }
              if (!userInput1.compare("email")) {
                cout << "// CHANGE PROFESSOR EMAIL //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Email:" << professor -> get_email() <<
                  "     Change Email To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                professor -> set_email(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("registry")) {
                cout << "// CHANGE PROFESSOR REGISTRY NUMBER //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Registry Number:" << professor -> get_regnum() <<
                  "     Change Registry Number To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                professor -> set_regnum(buffer);
                buffer.clear();
              }
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE PROFESSOR  ///////" << endl;

            cout << "Enter professor's registration number:" << endl;
            cin >> buffer;
            this -> professorlist.remove_if([ & buffer](shared_ptr < Professor > p) {
              return !p -> get_regnum().compare(buffer);
            });

          } else if (!userInput1.compare(("stats"))) {
            cout << "// PRINT PROFESSOR STATS FOR EACH COURSE UNDERTAKEN //////" <<
              endl;

            cout << "Enter professor's registration number:" << endl;
            cin >> buffer;
            shared_ptr < Professor > professor = this -> find < Professor > (buffer);
            while (professor == NULL) {
              buffer.clear();
              cout << "Professor not found. Do you want to try again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Professor's registration number:" << endl;
                cin >> buffer;
                professor = this -> find < Professor > (buffer);
              }
            }

            if (professor != NULL) {
              professor -> print_stats();
            }

          } else if (!userInput1.compare("assign")) {
            cout << "// ASSIGN PROFESSOR TO COURSE  ///////" << endl;

            cout << "Do you want to see a list of all the courses? (Y/N)?";
            cin >> buffer;
            if (buffer == "Y" || buffer == "y") {
              for (auto & p: this -> courselist) {
                cout << p -> get_name() << ":" <<
                  "  " << p -> get_serialno() << endl;
                cout << "Semester :" <<
                  "  " << p -> get_semester() << endl;
                cout << "----------------------------------" << endl;
              }
            }

            buffer.clear();

            cout << "Enter Course ID:" << endl;
            cin >> buffer;
            shared_ptr < Course > c = this -> find < Course > (buffer);

            while (c == NULL ||
              (c -> get_semester() % 2 == 0 && current_semester == 1 ||
                c -> get_semester() % 2 == 1 && current_semester == 2)) {
              buffer.clear();
              if (c == NULL) {
                cout << "Course ID not found. Do you want to try again? (Y/N)";
                cin >> buffer;
              } else {
                cout << "Course does not belong to the current semester. Do "
                "you want to try again? (Y/N)";
                cin >> buffer;
              }
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Course ID:" << endl;
                cin >> buffer;
                c = this -> find < Course > (buffer);
              }
            }

            if (c != NULL) {
              cout << "Enter Professor Registration:" << endl;
              cin >> buffer;
              shared_ptr < Professor > p = this -> find < Professor > (buffer);

              while (p == NULL) {
                buffer.clear();
                cout << "Professor ID not found. Do you want to try again? "
                "(Y/N) ";
                cin >> buffer;
                if (buffer != "Y" && buffer != "y") {
                  break;
                } else {
                  buffer.clear();
                  cout << "Enter Professor ID:" << endl;
                  cin >> buffer;
                  p = this -> find < Professor > (buffer);
                }
              }
              if (p != NULL) {
                p -> assign_to_course(c);
              }
            }

          } else if (!userInput1.compare("grade")) {
            cout << "// GRADE A STUDENT //////" << endl;

            cout << "Enter Professor Registration:" << endl;
            cin >> buffer;
            shared_ptr < Professor > p = this -> find < Professor > (buffer);

            while (p == NULL) {
              buffer.clear();
              cout
                <<
                "Professor ID not found. Do you want to try again? (Y/N) ";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Professor ID:" << endl;
                cin >> buffer;
                p = this -> find < Professor > (buffer);
              }
            }

            if (p != NULL) {
              cout << "Do you want to print a list of the courses you have "
              "been assigned to? (Y/N) ";
              cin >> buffer;
              if (buffer == "y" || buffer == "Y") {
                p -> dump_courses();
              }

              cout << "Enter Course Serial Number: ";
              cin >> buffer;

              shared_ptr < Course > c = this -> find < Course > (buffer);

              while (c == NULL) {
                cout << "Course not found. Do you want to try again? (Y/N)" <<
                  endl;
                cin >> buffer;
                if (buffer != "Y" && buffer != "y") {
                  break;
                } else {
                  cout << "Enter Course Serial Number: ";
                  cin >> buffer;
                }
              }

              if (c != NULL) {
                cout << "Enter Student's register number: ";
                cin >> buffer;

                shared_ptr < Student > s = this -> find < Student > (buffer);

                while (s == NULL) {
                  cout << "Student not found. Do you want to try again? (Y/N)" <<
                    endl;
                  cin >> buffer;
                  if (buffer != "Y" && buffer != "y") {
                    break;
                  } else {
                    buffer.clear();
                    cout << "Enter Student register number: ";
                    cin >> buffer;
                  }
                }

                if (s != NULL) {
                  p -> grade_student(s, c);
                }
              }
            }
          }
        }
      }
    } else if (!userInput1.compare("2")) {
      check = false;
      userInput1.clear();

      while (!check) {
        try {
          cout << "STUDENT OPTIONS: Enter 'add', 'change', 'remove', "
          "'register', 'stats', 'graduate' or 'back' to go back (case "
          "sensitive)" <<
          endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") &&
            userInput1.compare("remove") && userInput1.compare("register") &&
            userInput1.compare("stats") && userInput1.compare("graduate") && userInput1.compare("back")) {
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
            this -> add_person < Student > ();
            cin.clear();
            for (auto & p: this -> studentlist) {
              cout << p -> get_birthyear() << endl;
              cout << p -> get_semester() << endl;
              cout << p -> get_name() << endl;
              cout << p -> get_email() << endl;
              cout << p -> get_surname() << endl;
              cout << p -> get_ects() << endl;
              cout << p -> get_semester() << endl;
              cout << "----------------" << endl;
            }
          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE STUDENT DETAILS: Enter 'name', 'surname', "
                "'birthyear', 'email', 'registry', 'semester', 'ects', "
                "'passed' (case sensitive)" <<
                endl;
                cin >> userInput1;
                if (userInput1.compare("name") &&
                  userInput1.compare("surname") &&
                  userInput1.compare("birthyear") &&
                  userInput1.compare("email") &&
                  userInput1.compare("registry") &&
                  userInput1.compare("semester") &&
                  userInput1.compare("ects") &&
                  userInput1.compare("passed")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }

            cout << "Enter student's registration number:" << endl;
            cin >> buffer;
            shared_ptr < Student > student = this -> find < Student > (buffer);
            while (student == NULL) {
              buffer.clear();
              cout << "Student not found. Do you want to try again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Student's registration number:" << endl;
                cin >> buffer;
                student = this -> find < Student > (buffer);
              }
            }

            if (student != NULL) {
              if (!userInput1.compare("name")) {
                cout << "// CHANGE STUDENT NAME //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Name:" << student -> get_name() <<
                  "     Change Name To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                student -> set_name(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("surname")) {
                cout << "// CHANGE STUDENT SURNAME //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Surname:" << student -> get_surname() <<
                  "     Change Surname To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                student -> set_surname(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("birthyear")) {
                int buffer1;
                cout << "// CHANGE STUDENT BIRTHYEAR //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Birthyear:" << student -> get_birthyear() <<
                  "     Change birthyear To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer1;
                student -> set_birthyear(buffer1);
              }
              if (!userInput1.compare("email")) {
                cout << "// CHANGE STUDENT EMAIL //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Email:" << student -> get_email() <<
                  "     Change Email To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                student -> set_email(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("registry")) {
                cout << "// CHANGE STUDENT REGISTRY NUMBER //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Registry Number:" << student -> get_regnum() <<
                  "     Change Registry Number To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                student -> set_regnum(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("ects")) {
                int buffer1;
                cout << "// CHANGE STUDENT ECTS //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current ECTS:" << student -> get_ects() <<
                  "     Change ECTS To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer1;
                student -> set_ects(buffer1);
              }
              if (!userInput1.compare("passed")) {
                string pstatus = "FALSE";
                bool boolbuffer;
                if (student -> get_passed() == true) {
                  pstatus = "TRUE";
                }

                cout << "// CHANGE STUDENT PASSED STATUS //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Passed Status:" << pstatus <<
                  "     Change Passed Status To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> boolbuffer;
                student -> set_passed(boolbuffer);
              }
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE STUDENT  ///////" << endl;

            cout << "Enter student's registration number:" << endl;
            cin >> buffer;

            this -> studentlist.remove_if([ & buffer](shared_ptr < Student > s) {
              return !s -> get_regnum().compare(buffer);
            });

          } else if (!userInput1.compare("register")) {

            cout << "// REGISTER STUDENT TO COURSE //////" << endl;
            cout << "Enter Student's register number:" << endl;
            cin >> buffer;
            shared_ptr < Student > s = this -> find < Student > (buffer);

            while (s == NULL) {
              buffer.clear();
              cout << "Student's register number not found. Do you want to try "
              "again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Student's register number:" << endl;
                cin >> buffer;
                s = this -> find < Student > (buffer);
              }
            }

            if (s != NULL) {
              cout << "Enter Course ID:" << endl;
              cin >> buffer;
              shared_ptr < Course > c = this -> find < Course > (buffer);

              while (c == NULL) {
                buffer.clear();
                cout << "Course ID not found. Do you want to try again? (Y/N)";
                cin >> buffer;
                if (buffer != "Y" && buffer != "y") {
                  break;
                } else {
                  buffer.clear();
                  cout << "Enter Course ID:" << endl;
                  cin >> buffer;
                  c = this -> find < Course > (buffer);
                }
              }

              if (c != NULL) {
                s -> enroll(c);
                buffer.clear();
              }
            }
          } else if (!userInput1.compare("stats")) {
            cout << "// PRINT A STUDENT'S STATS ///////" << endl;
            cout << "Enter Student's register number:" << endl;
            cin >> buffer;
            shared_ptr < Student > s = this -> find < Student > (buffer);
            buffer.clear();

            while (s == NULL) {
              buffer.clear();
              cout << "Student's register number not found. Do you want to try "
              "again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Student's register number:" << endl;
                cin >> buffer;
                s = this -> find < Student > (buffer);
              }
            }

            if (s != NULL) {
              cout << "Enter 'current' for current semester, 'all' for all "
              "semesters (case sensitive)" <<
              endl;
              cin >> buffer;

              bool flag = false;

              while (flag == false) {
                if (buffer == "current") {
                  flag = true;
                  s -> get_grades(false);
                } else if (buffer == "all") {
                  flag = true;
                  s -> get_grades(true);
                } else {
                  cout << "Wrong input. Do you want to try again?(Y/N) ";
                  cin >> buffer;
                  if (buffer != "Y" && buffer != "y") {
                    break;
                  } else {
                    buffer.clear();
                    cout << "Enter 'current' for current semester, 'all' for all "
                    "semesters (case sensitive)" <<
                    endl;
                    cin >> buffer;
                  }
                }
              }
              buffer.clear();
            }
          } else if (!userInput1.compare("graduate")) {
            cout << "PRINT LIST OF STUDENTS WHO CAN GRADUATE ///////" << endl;
            for (auto & p: this -> studentlist) {
              if (p -> can_graduate(this -> get_mandatoryno())) {
                cout << "Graduated :    " << p -> get_name() << "" <<
                  p -> get_surname() << endl;
                cout << "Registered as:" << p -> get_regnum() << endl;
                cout << "Congratulations!" << endl;
              }
            }
          }
        }
      }
    } else if (!userInput1.compare("3")) {
      check = false;
      userInput1.clear();

      while (!check) {
        try {
          cout << "COURSE OPTIONS: Enter 'add', 'change' or 'remove', 'export' or 'back' to go back (case sensitive)" <<
            endl;
          cin >> userInput1;
          if (userInput1.compare("add") && userInput1.compare("change") &&
            userInput1.compare("remove") && userInput1.compare("export") &&
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
            cout << "// ADD COURSE TO UNIVERSITY ///////" << endl;
            this -> add_course();
            cin.clear();

          } else if (!userInput1.compare("change")) {
            check = false;
            userInput1.clear();

            while (!check) {
              try {
                cout << "CHANGE COURSE DETAILS: Enter 'name', 'serialno', "
                "'ects', 'semester', 'mandatory' (case sensitive)" <<
                endl;
                cin >> userInput1;
                if (userInput1.compare("name") &&
                  userInput1.compare("serialno") &&
                  userInput1.compare("ects") &&
                  userInput1.compare("semester") &&
                  userInput1.compare("mandatory")) {
                  throw "False Expression.\n";
                }
                check = true;
              } catch (const char s[]) {
                cout << s;
              }
            }

            cout << "Enter Course ID:" << endl;
            cin >> buffer;
            shared_ptr < Course > course = this -> find < Course > (buffer);

            while (course == NULL) {
              buffer.clear();
              cout << "Course ID not found. Do you want to try again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Course ID:" << endl;
                cin >> buffer;
                course = this -> find < Course > (buffer);
              }
            }

            if (course != NULL) {
              if (!userInput1.compare("name")) {
                cout << "// CHANGE COURSE NAME //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Name:" << course -> get_name() <<
                  "     Change Name To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                course -> set_name(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("serialno")) {
                cout << "// CHANGE COURSE ID //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Course ID:" << course -> get_serialno() <<
                  "     Change Course ID To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer;
                course -> set_serialno(buffer);
                buffer.clear();
              }
              if (!userInput1.compare("ects")) {
                int buffer2;
                cout << "// CHANGE COURSE ECTs //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current ECTs:" << course -> get_ects() <<
                  "     Change ECTs To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer2;
                course -> set_ects(buffer2);
              }
              if (!userInput1.compare("semester")) {
                int buffer2;
                cout << "// CHANGE COURSE SEMESTER //////" << endl;
                cout << "-------------------------" << endl;
                cout << "Current Semester:" << course -> get_semester() <<
                  "     Change Semester To ..... " << endl;
                cout << "-------------------------" << endl;
                cin >> buffer2;
                while (buffer2 > 8 || buffer2 < 1) {
                  cout << "Courses can only be assigned to semesters 1-8. Do you "
                  "want to try again? (Y/N)" <<
                  endl;
                  cin >> buffer;
                  if (buffer != "Y" && buffer != "y") {
                    break;
                  }
                  cin >> buffer2;
                }
                course -> set_semester(buffer2);
              }
              if (!userInput1.compare("mandatory")) {
                cout << "// CHANGE COURSE MANDATORY STATUS //////" << endl;;
                cout << "-------------------------" << endl;
                cout << "Current Mandatory Status:" << course -> get_mandatory() <<
                  "     Change Mandatory Status To (0 for false, 1 "
                "true)..... " <<
                endl;
                cout << "-------------------------" << endl;
                int buffer1;
                cin >> buffer1;

                course -> set_mandatory((buffer1 == 0) ? false : true);
              }
            }
          } else if (!userInput1.compare("remove")) {
            cout << "// REMOVE COURSE  ///////" << endl;

            buffer.clear();

            cout << "Enter Course ID:" << endl;
            cin >> buffer;
            shared_ptr < Course > c = this -> find < Course > (buffer);

            while (c == NULL) {
              buffer.clear();
              cout << "Course ID not found. Do you want to try again? (Y/N)";
              cin >> buffer;
              if (buffer != "Y" && buffer != "y") {
                break;
              } else {
                buffer.clear();
                cout << "Enter Course ID:" << endl;
                cin >> buffer;
                c = this -> find < Course > (buffer);
              }
            }

            if (c != NULL) {
              for (auto & s: this -> studentlist) {
                s -> cleanup(c);
              }
              for (auto & p: this -> professorlist) {
                p -> cleanup(c);
              }
            }

          } else if (!userInput1.compare("export")) {
            cout << "// EXPORT A LIST OF STUDENTS WHO HAVE COMPLETED A COURSE  "
            "///////" <<
            endl;

            string exportfilename = "./../export/excompleted.txt";

            std::ofstream fout;
            fout.open(exportfilename, std::ios::out);

            if (!fout.is_open()) {
              std::cerr << "Error Opening/Writing to File" << endl;
            } else {
              cout << "Enter Course ID:" << endl;
              cin >> buffer;
              shared_ptr < Course > c = this -> find < Course > (buffer);

              while (c == NULL) {
                buffer.clear();
                cout << "Course ID not found. Do you want to try again? (Y/N)";
                cin >> buffer;
                if (buffer != "Y" && buffer != "y") {
                  break;
                } else {
                  buffer.clear();
                  cout << "Enter Course ID:" << endl;
                  cin >> buffer;
                  c = this -> find < Course > (buffer);
                }
              }

              if (c != NULL) {
                for (auto & s: this -> studentlist) {
                  if (s -> has_passed(c) == true) {
                    fout << s -> get_name() << " " << s -> get_surname() << "OF SEMESTER:  " <<
                      s -> get_semester() << " " << "COMPLETED" << endl;
                  }
                }
              }

              fout.close();

            }
          }
        }
      }
    } else if (!userInput1.compare("4")) {

      cout << "WARNING: Verify that all students have been graded before the "
      "end of the current semester!" <<
      endl;
      if (continueop()) {
        current_semester = (current_semester == 1) ? 2 : 1;
        for (auto & p: this -> studentlist) {
          p -> set_semester(p -> get_semester() + 1);
          p -> update_ects();
        }
      }
    }
  }
}