#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "element.hh"
#include "single_list.hh"
#include "queue.hh"
#include "stack.hh"
#include "benchmark.hh"

/*!
 *   \file
 *   \brief Plik glowny programu
*/

using namespace std;	

int main()
{
	int ilosc = 10;
	int ilosc2 = 100000; 
	Benchmark Test;
	Test.generuj_liczby(ilosc2,30);
	/*
	Stack S(1);
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj_stack(&S,10,ilosc);
	}
	Queue Q(1);
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj_queue(&Q,10,ilosc);
	}
	
	
	*/
	
	Single_List L(1);
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj_list(&L,10,ilosc);
	}

	return 0;

}
