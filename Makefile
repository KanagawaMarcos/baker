all: baker clean

baker : main.o buffer.o docente.o periodico.o
	g++ main.o buffer.o docente.o periodico.o -o baker

main.o: main.cpp
	g++ -c main.cpp

buffer.o: buffer.cpp
	g++ -c buffer.cpp

docente.o: docente.cpp
	g++ -c docente.cpp

periodico.o:
	g++ -c periodico.cpp

clean:
	rm -rf *.o
