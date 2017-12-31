all: baker clean

baker : main.o buffer.o docente.o regra.o
	g++ main.o buffer.o docente.o regra.o -o baker

main.o: main.cpp
	g++ -c main.cpp

buffer.o: buffer.cpp
	g++ -c buffer.cpp

docente.o: docente.cpp
	g++ -c docente.cpp

regra.o: regra.cpp
	g++ -c regra.cpp

clean:
	rm -rf *.o
