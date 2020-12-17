all: p1

run: p1
	./assn07

p1 : p1.o Matrix.o
	g++ -o assn07 p1.o Matrix.o

p1.o : p1.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors -O0 p1.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c -g -Wall -std=c++14 -pedantic-errors -O0 Matrix.cpp

clean:
	rm -f *.o
	rm -f p1
	rm -f Matrix
	rm -f *~
