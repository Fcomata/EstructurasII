all: hello

hello: main2.o Bloque.o Cache.o
	g++ -o mi_cache Bloque.o Cache.o main2.o

main2.o: main2.cpp
	 g++ -std=c++0x -c main2.cpp

Bloque.o: Bloque.cpp Bloque.h
	g++ -std=c++0x -c Bloque.cpp

Cache.o: Cache.cpp Cache.h
	g++ -std=c++0x -c Cache.cpp

clean:
	rm *o main
