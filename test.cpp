
#include "test.hpp"

using namespace std;

Test::Test()
{
    cout << "test constructor" << endl;
}

Test::~Test()
{
    cout << "test destructor" << endl;
}

void Test::aaa()
{
    cout << "test aaa" << endl;
    a = 10;
    b = 10;
    c = 10;
}

void Test::bbb()
{
    cout << "test bbb" << endl;
    a = 20;
    c = 20;
    b = 20;
}
