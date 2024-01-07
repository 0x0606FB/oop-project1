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
            cout << "PROFESSOR OPTIONS: Enter 'add', 'change' or 'remove', 'stats' (case sensitive)" << endl;
            cin >> userInput1;
            if (userInput1.compare("add") && userInput1.compare("change")
                && userInput1.compare("remove") && userInput1.compare("stats")) {
                throw "False Expression.\n";
            }
            check = true;
        } catch (const char s[]) {
            cout << s;
        }
        }     


        if(!userInput1.compare("add")){
            cout << "// ADD PROFESSOR TO UNIVERSITY ///////" << endl;
        }
        else if (!userInput1.compare("change")){
            cout << "// CHANGE PROFESSOR DATA ///////" << endl;
        }
        else if (!userInput1.compare("remove")){
           cout << "// REMOVE PROFESSOR  ///////" << endl;
        }
        else {
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
            cout << "// CHANGE STUDENT DATA ///////" << endl;
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
            cout << "// CHANGE COURSE DATA ///////" << endl;
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