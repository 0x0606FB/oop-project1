    #include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;



void menu(){

    // exception handling 
    
    cout << "Press 1 for Professor options, 2 for Student options, 3 for Course options, 4 for extra options" << endl;
    int userInput1;
    cin >> userInput1;

    if (userInput1 == 1){

        string userInputProf;
        cout << "PROFESSOR OPTIONS: Enter 'add', 'change' or 'remove' (case sensitive)" << endl;
        cin >> userInputProf;

        if(userInputProf.compare("add") == 0){
            cout << "// ADD PROFESSOR TO UNIVERSITY ///////" << endl;
        }
        else if (userInputProf.compare("change") == 0){
            cout << "// CHANGE PROFESSOR DATA ///////" << endl;
        }
        else if (userInputProf.compare("remove") == 0){
           cout << "// REMOVE PROFESSOR  ///////" << endl;
        }
        else{
            cout << "Wrong input" << endl;
        }


    }

    else if (userInput1 == 2){
        string userInputStud;
        cout << "STUDENT OPTIONS: Enter 'add', 'change' or 'remove' (case sensitive)" << endl;
        cin >> userInputStud;

        if(userInputStud.compare("add") == 0){
            cout << "// ADD STUDENT TO UNIVERSITY ///////" << endl;
        }
        else if (userInputStud.compare("change") == 0){
            cout << "// CHANGE STUDENT DATA ///////" << endl;
        }
        else if (userInputStud.compare("remove") == 0){
           cout << "// REMOVE STUDENT  ///////" << endl;
        }
        else{
            cout << "Wrong input" << endl;
        }
    }

    else if (userInput1 == 3){
        string userInputCour;
        cout << "COURSE OPTIONS: Enter 'add', 'change' or 'remove' (case sensitive)" << endl;
        cin >> userInputCour;

        if(userInputCour.compare("add") == 0){
            cout << "// ADD COURSE TO UNIVERSITY ///////" << endl;
        }
        else if (userInputCour.compare("change") == 0){
            cout << "// CHANGE COURSE DATA ///////" << endl;
        }
        else if (userInputCour.compare("remove") == 0){
           cout << "// REMOVE COURSE  ///////" << endl;
        }
        else{
            cout << "Wrong input" << endl;
        }

    }
    else if(userInput1 == 4){
        cout << 
        "EXTRA OPTIONS: Press 1 to assign Professor to Course, 2 to sign up Student for Class, 3 to show passing Students of a Course" <<
        ", 4 to print Professor's Course stats, 5 to print Student's grades, 6 to print graduation-eligible Students" << endl;





    }
    else{
        cout << "Wrong input" << endl;
    }

}