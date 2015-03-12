#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: benchmark
	./benchmark

benchmark: obj/main.o obj/benchmark.o obj/lista.o
	g++ -Wall -pedantic -o benchmark obj/main.o obj/lista.o\
                                   obj/benchmark.o

obj/main.o: src/main.cpp inc/benchmark.hh inc/lista.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh
	g++ ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/lista.o: src/lista.cpp inc/lista.hh 
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp

clean:
	rm -f obj/*.o benchmark
