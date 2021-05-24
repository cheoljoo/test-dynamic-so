all: file.cpp test.cpp file.hpp test.hpp many.cpp many.hpp sstruct.cpp sstruct.hpp drived.cpp
	g++ -fPIC -c file.cpp -I.
	g++ -fPIC -c test.cpp -I.
	g++ -fPIC -c many.cpp -I.
	g++ -fPIC -c sstruct.cpp -I.
	g++ -fPIC -c drived.cpp -I.
	g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o drived.o

