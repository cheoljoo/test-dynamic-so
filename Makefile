# https://stackoverflow.com/questions/8941110/how-i-could-add-dir-to-path-in-makefile
LD_LIBRARY_PATH := .:$(LD_LIBRARY_PATH)
all: file.cpp test.cpp file.hpp test.hpp many.cpp many.hpp sstruct.cpp sstruct.hpp main.cpp drived.cpp
	make com
	make m
	./m
	./m > 1.log
	cd change_order; touch file.cpp ; make 
	cp -f change_order/libmy.so.0.0.0 .
	./m
	./m > 2.log
	ldd ./m > ldd.log
	-diff 1.log 2.log
	readelf -a ./m > readelf.m.log
	readelf -a ./libmy.so.0.0.0 > readelf.libmy.log

com: file.cpp test.cpp file.hpp test.hpp many.cpp many.hpp sstruct.cpp sstruct.hpp drived.cpp
	g++ -fPIC -c file.cpp -I.
	g++ -fPIC -c test.cpp -I.
	g++ -fPIC -c many.cpp -I.
	g++ -fPIC -c sstruct.cpp -I.
	g++ -fPIC -c drived.cpp -I.
	g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o drived.o

m: main.cpp
	g++ -o m main.cpp 	-L./ -lmy
	# export LD_LIBRARY_PATH=./

clean:
	/bin/rm -f *.o
	/bin/rm -f */*.o
	/bin/rm -f m
	/bin/rm -f *.log
