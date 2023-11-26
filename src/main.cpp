#include "./../headers/person.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    Person jimmy("Jimmy", "Jimmytopoulos", "69420", "jimmy", 400000);
    Person nikos("Nikos", "Nikolis", "333", "kolas", 50000000);
    // Person testperson = Person();
    cout << Person::get_total_counter() << endl;
    cout << nikos;


    return 0;

}   