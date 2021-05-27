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

    cout << "file.aaa() class virtual : ";
    file.aaa();
    cout << "test.aaa() class non-virtual: ";
    test.aaa();
    cout << "file.bbb() class virtual: ";
    file.bbb();
    cout << "test.bbb() class non-virtual: ";
    test.bbb();
    cout << "sstruct.aaa00() struct non-virtual: ";
    sstruct.aaa00();
    cout << "sstruct.aaa50() struct non-virtual: ";
    sstruct.aaa50();
    cout << "sstruct.bbb() struct non-virtual: ";
    sstruct.bbb();
    cout << "many.aaa00() class virtual: ";
    many.aaa00();
    cout << "many.aaa50() class virtual: ";
    many.aaa50();
    cout << "many.bbb() class virtual: ";
    many.bbb();
    cout << "main: enum color::red " << Color::red << endl;
    many.print_enum();
    cout << "end" << endl;


    File* pfile = new File;
    Test* ptest = new Test;
    Many* pmany = new Many;
    SStruct* psstruct = new SStruct;
    cout << "pfile->aaa() class virtual pointer: ";
    pfile->aaa();
    cout << "ptest->aaa() class non-virtual pointer: ";
    ptest->aaa();
    cout << "pmany->aaa00() class virtual pointer: ";
    pmany->aaa00();
    cout << "pstruct->aaa00() struct non-virtual pointer: ";
    psstruct->aaa00();
    cout << "pstruct->bbb() struct non-virtual pointer: ";
    psstruct->bbb();

    Drived1 dr1;
    Drived2 dr2;
    cout << "dr1.ccc() virtual drived class: ";
    dr1.ccc();
    cout << "dr1.aaa00() of Many class: ";
    dr1.aaa00();
    cout << "dr1.bbb() of Many class: ";
    dr1.bbb();
    cout << "dr2.ccc() : non-virtual drived class";
    dr2.ccc();
    cout << "dr2.aaa00() of SStruct struct: ";
    dr2.aaa00();
    cout << "dr2.bbb() of SStruct struct: ";
    dr2.bbb();

    Drived1* pdr1 = new Drived1;
    Drived2* pdr2 = new Drived2;
    cout << "pdr1->ccc() virtual drived class pointer:";
    pdr1->ccc();
    cout << "pdr1->aaa00() of Many class pointer: ";
    pdr1->aaa00();
    cout << "pdr1->bbb() of Many class pointer: ";
    pdr1->bbb();
    cout << "pdr2->ccc() non-virtual drived Many pointer: ";
    pdr2->ccc();
    cout << "pdr2->aaa00() of Many class pointer: ";
    pdr2->aaa00();
    cout << "pdr2->bbb() of Many class pointer: ";
    pdr2->bbb();

    DrivedStruct* pdrs = new DrivedStruct;
    cout << "pdrs->ccc() non-virtual drived pointer: ";
    pdrs->ccc();
    cout << "pdrs->aaa00() of SStruct struct pointer : ";
    pdrs->aaa00();
    cout << "pdrs->bbb() of SStruct struct pointer : ";
    pdrs->bbb();
}
