
#include "file.hpp"

using namespace std;

File::File()
{
    cout << "file constructor" << endl;
}

File::~File()
{
    cout << "file destructor" << endl;
}

void File::aaa()
{
    cout << "file aaa" << endl;
    a = 10;
    b = 10;
    c = 10;
}

void File::bbb()
{
    a = 20;
    c = 20;
    b = 20;
    cout << "file bbb" << endl;
}
