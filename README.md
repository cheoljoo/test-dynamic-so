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

# result
```txt
make all
make[1]: Entering directory '/data01/cheoljoo.lee/code/test-dynamic-so'
g++ -fPIC -c file.cpp -I.
g++ -fPIC -c test.cpp -I.
g++ -fPIC -c many.cpp -I.
g++ -fPIC -c sstruct.cpp -I.
g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o
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
file aaa
test aaa
file bbb
test bbb
sstruct aaa00
sstruct aaa50
sstruct bbb
many aaa00
many aaa50
many bbb
main: color::red 0
color red 0
color blue 2
global_0 0
end
sstruct destructor
many destructor
test destructor
file destructor
cd change_order; touch file.cpp ; make
make[1]: Entering directory '/data01/cheoljoo.lee/code/test-dynamic-so/change_order'
g++ -fPIC -c file.cpp -I.
g++ -fPIC -c test.cpp -I.
g++ -fPIC -c many.cpp -I.
g++ -fPIC -c sstruct.cpp -I.
g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o
make[1]: Leaving directory '/data01/cheoljoo.lee/code/test-dynamic-so/change_order'
cp -f change_order/libmy.so.0.0.0 .
./m
start
file constructor
test constructor
many constructor
sstruct constructor
file aaa
test aaa
file bbb
test bbb
sstruct aaa00
sstruct aaa50
sstruct bbb
many aaa00
many aaa50
many bbb
main: color::red 0
color red 1
color blue 2
global_0 1
end
sstruct destructor
many destructor
test destructor
file destructor
ldd ./m > ldd.log
readelf -a ./m > readelf.m.log
readelf -a ./libmy.so.0.0.0 > readelf.libmy.log
```

- explanation
    - first execution of ./m
    - second execution of ./m
        - use change_order's library
    - comparison between first and second execution
        - we can not find any changes when we change order of member functions.
        - we can find enum value when we change the order of enum members.
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
