#include "./../headers/secretary.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    Person *jimmy = new Person("Jimmy", "Jimmytopoulos", "69420", "jimmy", 400000);
    Person *nikos = new Person("Nikos", "Nikolis", "333", "kolas", 50000000);
    // cout << Person::get_total_counter() << endl;
    // cout << nikos << endl;

    // // TESTING SECRETARY FUNCTIONS //

    // Person john("John", "Doe", "0000001", "john@mail.com", 20);
    // Person jane("Jane", "Smith", "0000002", "jane@mail.com", 23);
    
    // Person testPerson;

    // string buffer;
    // int age;

    // cout << "Please give name: ";
    // cin >>  buffer;
    // testPerson.set_name(buffer);
    // buffer.clear();

    // cout << "Please give surname: ";
    // cin >>  buffer;
    // testPerson.set_surname(buffer);
    // buffer.clear();

    // cout << "Please give register number: ";
    // cin >>  buffer;
    // testPerson.set_regnum(buffer);
    // buffer.clear();

    // cout << "Please give e-mail address: ";
    // cin >>  buffer;
    // testPerson.set_email(buffer);
    // buffer.clear();

    // cout << "Please give age: ";
    // cin >>  age;
    // testPerson.set_age(age);
    
    Secretary testSecretary;

    // testSecretary.add_person();

    // testSecretary.add_person();
    testSecretary + jimmy;
    testSecretary + nikos;
    // testSecretary.dump();

    // Secretary testSecretary2(testSecretary);
    // testSecretary2.dump();

    Secretary testSecretary3;
    testSecretary3 = testSecretary;

    testSecretary3.dump();
    






    return 0;
}