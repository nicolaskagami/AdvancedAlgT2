
all: clean UF0 UF1 UF2 

UF0: UFind.cpp main.cpp
	g++ -DPATH_COMPRESSION=0 -DWEIGHT_BALANCING=0 main.cpp UFind.cpp -o UF0

UF1: UFind.cpp main.cpp
	g++ -DPATH_COMPRESSION=0 -DWEIGHT_BALANCING=1 main.cpp UFind.cpp -o UF1

UF2: UFind.cpp main.cpp
	g++ -DPATH_COMPRESSION=1 -DWEIGHT_BALANCING=1 main.cpp UFind.cpp -o UF2

clean:
	rm -rf *.o
