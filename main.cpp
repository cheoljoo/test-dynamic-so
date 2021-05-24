#include <iostream>
#include "file.hpp"
#include "test.hpp"
#include "many.hpp"
#include "sstruct.hpp"
#include "drived.hpp"

using namespace std;

int 
main(void)
{
    cout << "start" << endl;
    File file;
    Test test;
    Many many;
    SStruct sstruct;

    cout << "file.aaa() : ";
    file.aaa();
    cout << "test.aaa() : ";
    test.aaa();
    cout << "file.bbb() : ";
    file.bbb();
    cout << "test.bbb() : ";
    test.bbb();
    cout << "sstruct.aaa00() : ";
    sstruct.aaa00();
    cout << "sstruct.aaa50() : ";
    sstruct.aaa50();
    cout << "sstruct.bbb() : ";
    sstruct.bbb();
    cout << "many.aaa00() : ";
    many.aaa00();
    cout << "many.aaa50() : ";
    many.aaa50();
    cout << "many.bbb() : ";
    many.bbb();
    cout << "main: color::red " << Color::red << endl;
    many.print_enum();
    cout << "end" << endl;


    File* pfile = new File;
    Many* pmany = new Many;
    SStruct* psstruct = new SStruct;
    cout << "pfile->aaa() : ";
    pfile->aaa();
    cout << "pmany->aaa00() : ";
    pmany->aaa00();
    cout << "pstruct->aaa00() : ";
    psstruct->aaa00();
    cout << "pstruct->bbb() : ";
    psstruct->bbb();

    Drived1 dr1;
    Drived2 dr2;
    cout << "dr1.ccc() : ";
    dr1.ccc();
    cout << "dr1.aaa00() of Many : ";
    dr1.aaa00();
    cout << "dr1.bbb() of Many : ";
    dr1.bbb();
    cout << "dr2.aaa00() of SStruct : ";
    dr2.aaa00();
    cout << "dr2.bbb() of SStruct : ";
    dr2.bbb();
    cout << "dr2.ccc() : ";
    dr2.ccc();

    Drived1* pdr1 = new Drived1;
    Drived2* pdr2 = new Drived2;
    cout << "pdr1->ccc() : ";
    pdr1->ccc();
    cout << "pdr1->aaa00() of Many : ";
    pdr1->aaa00();
    cout << "pdr1->bbb() of Many : ";
    pdr1->bbb();
    cout << "pdr2->aaa00() of SStruct : ";
    pdr2->aaa00();
    cout << "pdr2->bbb() of SStruct : ";
    pdr2->bbb();
    cout << "pdr2->ccc() : ";
    pdr2->ccc();

    DrivedStruct* pdrs = new DrivedStruct;
    cout << "pdrs->ccc() : ";
    pdrs->ccc();
    cout << "pdrs->aaa00() of Many : ";
    pdrs->aaa00();
    cout << "pdrs->bbb() of Many : ";
    pdrs->bbb();
}
