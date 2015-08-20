
all: clean union-find

union-find: UFind.o main.o
	g++ main.o UFind.o -o union-find

main.o: main.cpp
	g++ -c main.cpp

UFind.o: UFind.cpp
	g++ -c UFind.cpp

clean:
	rm -rf *.o
