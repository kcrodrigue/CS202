project: main.o Implementation.o
	g++ -g main.o Implementation.o -o project

main: main.cpp Implementation.h
	g++ -g -c main.cpp -o main.o

Implementation: Implementation.cpp Implementation.h
	g++ -g -c Implementation.cpp -o Implementation.o
