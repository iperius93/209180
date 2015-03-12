#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "lista.hh"
#include "benchmark.hh"

using namespace std;


int main()
{
	int ilosc = 100000; 
	Benchmark Test;
	Lista Testowana(ilosc);
	Test.generuj_liczby(ilosc,30);
	
	for(ilosc=1000;ilosc<100000;ilosc+=1000)
	{
		Test.testuj(Testowana, Testowana.zwroc_adres(),10,ilosc);
	}
	return 0;
}
