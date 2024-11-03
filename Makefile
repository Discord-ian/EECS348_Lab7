all: obj/matrix.o
	g++ -std=c++11 -o bin/matrix.out obj/matrix.o
obj/main.o: main.cpp
	g++ -std=c++11 -o obj/main.o -c main.cpp
obj/matrix.o: matrix.cpp
	g++ -std=c++11 -o obj/matrix.o -c matrix.cpp
clean:
	rm -f obj/*.o
	rm -f bin/*.out
setup:
	mkdir -p bin/
	mkdir -p obj/
