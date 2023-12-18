#include "./../headers/secretary.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {

    Person *john = new Person("John", "Doe",  0000001, "john@mail.com", 20);
    Person *jane = new Person("Jane", "Smith",0000002, "jane@mail.com", 23);
    
    Secretary testSecretary;

    
    cout << "Added 2 test entities. Please fill out the information to add another person manually." << endl;

    testSecretary + john;
    testSecretary + jane;
    testSecretary.add_person();
    
    cout << "# of people created so far:  " << Person::get_total_counter() << endl << endl;
    
    cout << "Contents of testSecretary :  " << endl; 
    testSecretary.dump();
    
    Secretary copySecretary = testSecretary;
    cout << endl << "Copied contents of testSecretary into copySecretary" << endl << endl;
    cout << "Contents of copySecretary :  " << endl; 
    copySecretary.dump();

    cout << "Searching for person with registry number = 0000001:" << endl;
    cout << testSecretary.find_person(0000001);
    cout << "Try searching for a person with a registry number (integer):"   << endl;
    cout << testSecretary.find_person();

    cout << "# of people created so far:  " << Person::get_total_counter() << endl;
    
    return 0;
}