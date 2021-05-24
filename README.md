# test-dynamic-so
dynamic so test - change order of member functions between using binary and recompile

# how to run
- export LD_LIBRARY_PATH=./
- make
    - file.* test.* : has just 2 member functions
    - many.* sstruct.* : has more than 100 member functions
    - many.* : include enum
    - sstruct.* : no virtual function , use struct instead of class
    - change_order : we change the enum order and member functions in class/struct 
    - main.cpp : call functions

# result
```txt
make com
make[1]: Entering directory '/data01/cheoljoo.lee/code/test-dynamic-so'
g++ -fPIC -c file.cpp -I.
g++ -fPIC -c test.cpp -I.
g++ -fPIC -c many.cpp -I.
g++ -fPIC -c sstruct.cpp -I.
g++ -fPIC -c drived.cpp -I.
g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o drived.o
make[1]: Leaving directory '/data01/cheoljoo.lee/code/test-dynamic-so'
make m
make[1]: Entering directory '/data01/cheoljoo.lee/code/test-dynamic-so'
make[1]: 'm' is up to date.
make[1]: Leaving directory '/data01/cheoljoo.lee/code/test-dynamic-so'
./m
start
file constructor
test constructor
many constructor
sstruct constructor
file.aaa() : file aaa
test.aaa() : test aaa
file.bbb() : file bbb
test.bbb() : test bbb
sstruct.aaa00() : sstruct aaa00
sstruct.aaa50() : sstruct aaa50
sstruct.bbb() : sstruct bbb
many.aaa00() : many aaa00
many.aaa50() : many aaa50
many.bbb() : many bbb
main: color::red 0
color red 0
color blue 2
global_0 0
end
file constructor
many constructor
sstruct constructor
pfile->aaa() : file aaa
pmany->aaa00() : many aaa00
pstruct->aaa00() : sstruct aaa00
pstruct->bbb() : sstruct bbb
many constructor
drive1 constructor
sstruct constructor
drive2 constructor
dr1.ccc() : drive1 ccc
dr1.aaa00() of Many : many aaa00
dr1.bbb() of Many : many bbb
dr2.aaa00() of SStruct : sstruct aaa00
dr2.bbb() of SStruct : sstruct bbb
dr2.ccc() : drive2 ccc
many constructor
drive1 constructor
sstruct constructor
drive2 constructor
pdr1->ccc() : drive1 ccc
pdr1->aaa00() of Many : many aaa00
pdr1->bbb() of Many : many bbb
pdr2->aaa00() of SStruct : sstruct aaa00
pdr2->bbb() of SStruct : sstruct bbb
pdr2->ccc() : drive2 ccc
many constructor
driveStruct constructor
pdrs->ccc() : driveStruct ccc
pdrs->aaa00() of Many : many aaa00
pdrs->bbb() of Many : many bbb
drive2 destructor
sstruct destructor
drive1 destructor
many destructor
sstruct destructor
many destructor
test destructor
file destructor
./m > 1.log
cd change_order; touch file.cpp ; make 
make[1]: Entering directory '/data01/cheoljoo.lee/code/test-dynamic-so/change_order'
g++ -fPIC -c file.cpp -I.
g++ -fPIC -c test.cpp -I.
g++ -fPIC -c many.cpp -I.
g++ -fPIC -c sstruct.cpp -I.
g++ -fPIC -c drived.cpp -I.
g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o drived.o
make[1]: Leaving directory '/data01/cheoljoo.lee/code/test-dynamic-so/change_order'
cp -f change_order/libmy.so.0.0.0 .
./m
start
file constructor
test constructor
many constructor
sstruct constructor
file.aaa() : file aaa
test.aaa() : test aaa
file.bbb() : file bbb
test.bbb() : test bbb
sstruct.aaa00() : sstruct aaa00
sstruct.aaa50() : sstruct aaa50
sstruct.bbb() : sstruct bbb
many.aaa00() : many aaa00
many.aaa50() : many aaa50
many.bbb() : many bbb
main: color::red 0
color red 1
color blue 2
global_0 1
end
file constructor
many constructor
sstruct constructor
pfile->aaa() : file bbb
pmany->aaa00() : many bbb
pstruct->aaa00() : sstruct aaa00
pstruct->bbb() : sstruct bbb
many constructor
drive1 constructor
sstruct constructor
drive2 constructor
dr1.ccc() : drive1 ccc
dr1.aaa00() of Many : many aaa00
dr1.bbb() of Many : many bbb
dr2.aaa00() of SStruct : sstruct aaa00
dr2.bbb() of SStruct : sstruct bbb
dr2.ccc() : drive2 ccc
many constructor
drive1 constructor
sstruct constructor
drive2 constructor
pdr1->ccc() : drive1 ccc
pdr1->aaa00() of Many : many bbb
pdr1->bbb() of Many : many aaa98
pdr2->aaa00() of SStruct : sstruct aaa00
pdr2->bbb() of SStruct : sstruct bbb
pdr2->ccc() : drive2 ccc
many constructor
driveStruct constructor
pdrs->ccc() : driveStruct ccc
pdrs->aaa00() of Many : many bbb
pdrs->bbb() of Many : many aaa98
drive2 destructor
sstruct destructor
drive1 destructor
many destructor
sstruct destructor
many destructor
test destructor
file destructor
./m > 2.log
ldd ./m > ldd.log
diff 1.log 2.log
17c17
< color red 0
---
> color red 1
19c19
< global_0 0
---
> global_0 1
24,25c24,25
< pfile->aaa() : file aaa
< pmany->aaa00() : many aaa00
---
> pfile->aaa() : file bbb
> pmany->aaa00() : many bbb
43,44c43,44
< pdr1->aaa00() of Many : many aaa00
< pdr1->bbb() of Many : many bbb
---
> pdr1->aaa00() of Many : many bbb
> pdr1->bbb() of Many : many aaa98
51,52c51,52
< pdrs->aaa00() of Many : many aaa00
< pdrs->bbb() of Many : many bbb
---
> pdrs->aaa00() of Many : many bbb
> pdrs->bbb() of Many : many aaa98
make: [Makefile:13: all] Error 1 (ignored)
readelf -a ./m > readelf.m.log
readelf -a ./libmy.so.0.0.0 > readelf.libmy.log
```

- conclusion
    - Do not change order
        - pointer : when we declare with new ->  class member funcitn order (ex. File* a = new File; )
        - enumeration order
    - Do not care
        - pointer : when we declare without pointer (new) (ex. File a; )
        - struct does not care about order both pointer (new) and no-pointer declaratin and drived.

- explanation
    - first execution of ./m
    - second execution of ./m
        - use change_order's library
    - comparison between first and second execution
        - we can not find any changes when we change order of member functions in static declaration.
        - we can find changed enum value when we change the order of enum members.
            - main.cpp : it is sure that main.cpp shows the enum value before changing because we did not compile about main.cpp
            - library - print_enum(): it is sure that print_enum shows the changed enum value because we compiled in library.
        - we can find any changes when we change order of member functions in dynamic declaration with new operation.
            - but if we declare as struct , do not care about changed order in struct class.
    - readelf
        - c++ do the mangling for class member functions. so we can find all member functions symbols in .dynsym section
        - this result shows  they use the direct access (just offset in library)  instead of offset from each class.

# reference (korean language)
- https://www.lesstif.com/software-architect/shared-library-linker-loader-12943542.html#id-%EB%8F%99%EC%A0%81%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(sharedlibrary)%EC%99%80Linker/Loader%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-LD_LIBRARY_PATH
- https://jacking75.github.io/Linux_make_shardlib/
- https://sonseungha.tistory.com/462?category=686290
- http://egloos.zum.com/recipes/v/5010841
- https://pu1et-panggg.tistory.com/32
- https://www.technovelty.org/linux/stripping-shared-libraries.html
