all: file.cpp test.cpp file.hpp test.hpp many.cpp many.hpp sstruct.cpp sstruct.hpp
	g++ -fPIC -c file.cpp -I.
	g++ -fPIC -c test.cpp -I.
	g++ -fPIC -c many.cpp -I.
	g++ -fPIC -c sstruct.cpp -I.
	g++ -shared -Wl,-soname,libmy.so.0 -o libmy.so.0.0.0 file.o test.o many.o sstruct.o

m: main.cpp
	g++ -o m main.cpp 	-L./ -lmy
	# export LD_LIBRARY_PATH=./

test: file.cpp test.cpp file.hpp test.hpp many.cpp many.hpp sstruct.cpp sstruct.hpp main.cpp
	make all
	make m
	./m
	cd change_order; touch file.cpp ; make 
	cp -f change_order/libmy.so.0.0.0 .
	./m
	ldd ./m > ldd.log
	readelf -a ./m > readelf.m.log
	readelf -a ./libmy.so.0.0.0 > readelf.libmy.log
