#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "drzewoRB.h"
#include "benchmark.h"

/*!
 *   \file
 *   \brief Plik głowny
 *
 *
 *
 *
*/

using namespace std;

const int MAXN =10;


int main()
{
    int ilosc = 10;
	int ilosc2 = 10000000;
	Benchmark Test;
	Test.generuj_liczby(ilosc2,100);

	drzewoRB * RBT;

	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
        RBT = new drzewoRB;
		Test.testuj(RBT,1,ilosc);
		delete RBT;
	}

    return 0;
}