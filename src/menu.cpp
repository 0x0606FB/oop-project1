#include <exception>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

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

void menu(){

    while (1) {
        string userInput1;
        bool check = false;
    while (!check) {
        try {
            cout << "Press 1 for Professor options, 2 for Student options, 3 for Course options, 0 to quit menu" << endl;         
            cin >> userInput1;
        if (userInput1.compare("1") && userInput1.compare("2") && userInput1.compare("3") && userInput1.compare("0")) {
            throw "False Value.\n";
        } else if (!userInput1.compare("0")){
            throw 0;
        }
        check = true;
    } 
    catch (const char s[]) {
        cout << s;
    } catch (const int quit) {
            cout << "Are you sure you want to quit? (Y/N)" << endl;
            cin >> userInput1;
            if (!userInput1.compare("y") || !userInput1.compare("Y")) {
                return;
            }
    } 
    
    
    }
    
    if (!userInput1.compare("1")){
        
        

        check = false;
        userInput1.clear();
        
        while (!check) {
        try {
            cout << "PROFESSOR OPTIONS: Enter 'add', 'change' or 'remove', 'stats' or 'back' to go back (case sensitive)" << endl;
            cin >> userInput1;
            if (userInput1.compare("add") && userInput1.compare("change")
                && userInput1.compare("remove") && userInput1.compare("stats") && userInput1.compare("back")) {
                throw "False Expression.\n";
            } else if (!userInput1.compare("back")){
                throw 0;
            }
            check = true;
        } catch (const char s[]) {
            cout << s;
        }  catch (int back) {
            break;
        }
        }     


        if(!userInput1.compare("add")){
            cout << "// ADD PROFESSOR TO UNIVERSITY ///////" << endl;
            if (!continueop()) {goto }
        }
        else if (!userInput1.compare("change")){
            cout << "// CHANGE PROFESSOR DATA ///////" << endl;
        }
        else if (!userInput1.compare("remove")){
           cout << "// REMOVE PROFESSOR  ///////" << endl;
        }
        else if (!userInput1.compare(("stats"))){
            cout << "// PRINT PROFESSOR STATS FOR EACH COURSE UNDERTAKEN //////" << endl;
        }

    }

    else if (!userInput1.compare("2")){
        
        check = false;
        userInput1.clear();

        while (!check) {
        try {
            cout << "STUDENT OPTIONS: Enter 'add', 'change', 'remove', 'register', 'stats', 'graduate' (case sensitive)" << endl;
            cin >> userInput1;
            if (userInput1.compare("add") && userInput1.compare("change") 
                && userInput1.compare("remove") && userInput1.compare("register")
                && userInput1.compare("graduate")) {
                throw "False Expression.\n";
            }
            check = true;
        } catch (const char s[]) {
            cout << s;
        }
        }


        if(!userInput1.compare("add")){
            cout << "// ADD STUDENT TO UNIVERSITY ///////" << endl;
        }
        else if (!userInput1.compare("change")){
            check = false;
            userInput1.clear();

            while (!check) {
            try {
                cout << "CHANGE STUDENT DETAILS: Enter 'semester', 'ects', 'passed' (case sensitive)" << endl;
                cin >> userInput1;
                if (userInput1.compare("semester") && userInput1.compare("ects") && userInput1.compare("passed")) {
                    throw "False Expression.\n";
                }
                check = true;
            } catch (const char s[]) {
                cout << s;
            }
            }
            if (!userInput1.compare("semester")){
                cout << "// CHANGE STUDENT SEMESTER //////" << endl; ////////////////////////////////////////////
            }
            if (!userInput1.compare("ects")){
                cout << "// CHANGE STUDENT ECTS //////" << endl;     ///////////////////////////////////////////
            }
            if (!userInput1.compare("passed")){
                cout << "// CHANGE STUDENT PASSED STATUS //////" << endl;   ////////////////////////////////////
            }
        }
        else if (!userInput1.compare("remove")){
           cout << "// REMOVE STUDENT  ///////" << endl;
        }
        else if (!userInput1.compare("register")) {
            cout << "// REGISTER STUDENT TO COURSE ///////" << endl;
        }
        else if (!userInput1.compare("stats")) {
            cout << "// PRINT A STUDENTS' STATS ///////" << endl;
        }
        else if (!userInput1.compare("graduate")){
            cout << "PRINT LIST OF STUDENTS WHO CAN GRADUATE ///////" << endl;
        }
    }

    else if (!userInput1.compare("3")){
        
        
        check = false;
        userInput1.clear();
        
        while (!check) {
        try {
            cout << "COURSE OPTIONS: Enter 'add', 'change' or 'remove', 'assign', 'export' (case sensitive)" << endl;
            cin >> userInput1;
            if (userInput1.compare("add") && userInput1.compare("change")
                && userInput1.compare("remove") && userInput1.compare("assign")
                && userInput1.compare("export")) {
                throw "False Expression.\n";
            }
            check = true;
        } catch (const char s[]) {
            cout << s;
        }
        }     


    

        if(!userInput1.compare("add")){
            cout << "// ADD COURSE TO UNIVERSITY ///////" << endl;
        }
        else if (!userInput1.compare("change")){
            check = false;
            userInput1.clear();

            while (!check) {
            try {
                cout << "CHANGE COURSE DETAILS: Enter 'name', 'serialno', 'ects', 'semester', 'mandatory' (case sensitive)" << endl;
                cin >> userInput1;
                if (userInput1.compare("name") && userInput1.compare("serialno") && userInput1.compare("ects") 
                    && userInput1.compare("semester") && userInput1.compare("mandatory")) {
                    throw "False Expression.\n";
                }
                check = true;
            } catch (const char s[]) {
                cout << s;
            }
            }
            if (!userInput1.compare("name")){
                cout << "// CHANGE COURSE NAME //////" << endl;             /////////////////////////////////
            }
            if (!userInput1.compare("serialno")){
                cout << "// CHANGE COURSE SERIALNO //////" << endl;         /////////////////////////////////
            }
            if (!userInput1.compare("ects")){
                cout << "// CHANGE COURSE ECTS //////" << endl;             /////////////////////////////////
            }
            if (!userInput1.compare("semester")){
                cout << "// CHANGE COURSE PASSED SEMESTER //////" << endl;  /////////////////////////////////
            }
            if (!userInput1.compare("mandatory")){
                cout << "// CHANGE COURSE MANDATORY STATUS //////" << endl; /////////////////////////////////
            }
        }
        else if (!userInput1.compare("remove")){
           cout << "// REMOVE COURSE  ///////" << endl;
        }
        else if (!userInput1.compare("assign")){
           cout << "// ASSIGN PROFESSOR TO COURSE  ///////" << endl;
        }
        else if (!userInput1.compare("export")){
           cout << "// EXPORT A LIST OF STUDENTS WHO HAVE COMPLETED A COURSE  ///////" << endl;
        }
    } 
}
}