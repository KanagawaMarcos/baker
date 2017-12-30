all: baker
	
baker : main.o buffer.o docente.o
	g++ main.o buffer.o -o baker -o baker

main.o: main.cpp
	g++ -c main.cpp

buffer.o: buffer.cpp
	g++ -c buffer.cpp

docente.o: docente.cpp
	g++ -c docente.cpp

clean:
	rm -rf *.o
