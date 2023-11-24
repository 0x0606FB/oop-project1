#include "./../headers/person.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {

    Person jimmy("Jimmy", "Jimmytopoulos", "69420", "jimmy", 400000);
    // Person nikos("Nikos", "Nikolis", "333", "kolas", 50000000);
    // Person testperson = Person();

    // cout << testperson.get_name() << endl;
    // cout << testperson.get_count() << endl;

    cout << jimmy;

    return 0;

}   