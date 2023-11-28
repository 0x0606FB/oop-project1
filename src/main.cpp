#include "./../headers/secretary.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    Person *john = new Person("John", "Doe",  0000001, "john@mail.com", 20);
    Person *jane = new Person("Jane", "Smith",0000002, "jane@mail.com", 23);
    
    Secretary testSecretary;

    // cout << "# of people created so far:  " << Person::get_total_counter() << endl;
    // // cout << "Adding 3 test entities    :  " << endl;

    testSecretary + john;
    testSecretary + jane;
    // // testSecretary.add_person();
    cout << Person::get_total_counter() << endl; // 2

    
    cout << "Contents of testSecretary :  " << endl; 
    testSecretary.dump();
    cout << Person::get_total_counter() << endl; //0?

    Secretary copySecretary(testSecretary);
    cout << "Copied contents of testSecretary into copySecretary" << endl;
    copySecretary.dump();

    cout << "Searching for person with registry number = 0000001:" << endl;
    cout << testSecretary.find_person(0000001);
    cout << "Try searching for a person with a registry number:"   << endl;
    cout << testSecretary.find_person();

    cout << Person::get_total_counter() << endl;
    
    
    return 0;

}