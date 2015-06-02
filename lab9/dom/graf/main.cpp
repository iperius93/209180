#include <iostream>
#include <iomanip>
#include "graf.hh"
#include "benchmark.hh"

using namespace std;


// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
    int ilosc = 100;
	int ilosc2 = 10000000;
	Benchmark Test;
	Test.generuj_liczby(ilosc2,9);

	graf *graf1;

    graf1 = new graf(30,ilosc*1000);


    Test.testuj(graf1,1,ilosc*1000);
    delete graf1;


	return 0;
}
