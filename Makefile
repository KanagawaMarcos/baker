all: baker clean

baker : main.o buffer.o docente.o  producao.o
	g++ main.o buffer.o docente.o  producao.o -o baker

main.o: main.cpp
	g++ -c main.cpp

buffer.o: buffer.cpp docente.o producao.o
	g++ -c buffer.cpp

docente.o: docente.cpp
	g++ -c docente.cpp

producao.o: producao.cpp
	g++ -c producao.cpp

clean:
	rm -rf *.o
