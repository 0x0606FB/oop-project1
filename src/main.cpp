#include "./../headers/secretary.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    Person *john = new Person("John", "Doe",  0000001, "john@mail.com", 20);
    Person *jane = new Person("Jane", "Smith",0000002, "jane@mail.com", 23);
    
    Secretary testSecretary;

    testSecretary + john;
    testSecretary + jane;
    testSecretary.dump();

    cout << testSecretary.find_person() << endl;
    cout << testSecretary.find_person(0000003);

    // Secretary copySecretary(testSecretary);


    // copySecretary.dump();
   





}