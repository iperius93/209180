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
    srand(time(NULL));

	int ilosc = 10;
	int ilosc2 = 10000000;
	Benchmark Test;
	Test.generuj_liczby(ilosc2,100);

	/*
	Stack S(1);
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj_stack(&S,10,ilosc);
	}
	*/
/*  Queue Q(10);
	for(int i = 0; i<10;i++)
	{
        Q.push(((rand() % 30) + 0));
	}
    Q.wyswietl_kolejke();
    cout << endl;
    cout << endl;
	Q.merge_sort(0,9);
    Q.wyswietl_kolejke();
    cout << endl; */
    Queue Q(ilosc2);
    Q.wyswietl_kolejke();
    Test.testuj_queue(&Q,10,ilosc);     //test 10 liczb
    Q.wyswietl_kolejke();

    Test.testuj_queue(&Q,10,ilosc*10);//test 100 liczb
    Test.testuj_queue(&Q,10,ilosc*100);//test 1000 liczb
    Test.testuj_queue(&Q,10,ilosc*1000);//test 10000 liczb
    Test.testuj_queue(&Q,10,ilosc*10000);//test 100000 liczb
    Test.testuj_queue(&Q,10,ilosc*100000);//test 1000000 liczb
    Test.testuj_queue(&Q,10,ilosc*1000000);//test 10000000 liczb


	/*Single_List L(1);
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj_list(&L,10,ilosc);
	}*/

	return 0;

}
