#include <iostream>
#include "file.hpp"
#include "test.hpp"
#include "many.hpp"
#include "sstruct.hpp"

using namespace std;

int 
main(void)
{
    cout << "start" << endl;
    File file;
    Test test;
    Many many;
    SStruct sstruct;

    file.aaa();
    test.aaa();
    file.bbb();
    test.bbb();
    sstruct.aaa00();
    sstruct.aaa50();
    sstruct.bbb();
    many.aaa00();
    many.aaa50();
    many.bbb();
    cout << "main: color::red " << Color::red << endl;
    many.print_enum();
    cout << "end" << endl;
}
