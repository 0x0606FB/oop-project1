Compilation:

g++ main.cpp secretary.cpp professor.cpp student.cpp person.cpp course.cpp -o  main.exe -std=c++17 -g

and to run: ./main.exe (make sure to cd into src).

import/export folders are self explanatory, please be sure to follow the correct format.

For memory leak check:
    After compiling: run valgrind --leak-check=yes ./main.exe