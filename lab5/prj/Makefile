#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: asocjacja
	./asocjacja

asocjacja: obj/main.o
	g++ -Wall -pedantic -o asocjacja obj/main.o

obj/main.o: src/main.cpp inc/map.h inc/hasz_tab.h inc/element.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o asocjacja
