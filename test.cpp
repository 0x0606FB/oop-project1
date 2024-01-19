#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

#include <type_traits>
class A {
    int a;
    public:
        void print() {
            cout << "A" << endl;
        }
};

class B {
    int b;
    public:
        void print() {
            cout << "B" << endl;
        }
};

class C {
    int c;
    public:
        void print() {
            cout << "C" << endl;
        }
};

template <typename T> void func(void) {

    T item;

    if constexpr (std::is_same_v<T, A>) {
        item.print();
    } else if constexpr (std::is_same_v<T, B>) {
        item.print();
    } else if constexpr (std::is_same_v<T, C>) {
        item.print();
    }
}

int main(void) {

    // func<A>();
    // func<B>();
    // func<C>();

    std::ofstream fout; 
    fout.open("./export/excompleted.txt");
    fout << "Hello World" << endl;

    fout.close();



    return 0;
}