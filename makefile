a.out: hashing.o 
	g++ hashing.o 
hashing.o: hashing.cpp TimeInterval.h
	g++ -c hashing.cpp
run: a.out
	./a.out