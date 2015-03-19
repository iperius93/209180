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
#include "lista.hh"
#include "benchmark.hh"

using namespace std;	

int main()
{
	int ilosc = 10;
	int ilosc2 = 1000000; 
	Benchmark Test;
	Lista Testowana;
	Test.generuj_liczby(ilosc2,30);
	// Lista jednokierunkowa 1
	// Kolejka 2
	// Stos 3
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		Test.testuj(Testowana,1,10,ilosc);
	}
	
	
	
	
	
/*	Single_List sl;
	Element *p;
	int i;
	
	cout << "(A) : "; sl.showInfo();
	
	for(i=1;i<=5;i++)
	{
		p = new Element;
		p->info = i;
		sl.push_front(p);
	}
	
	cout << "(B) : "; sl.showInfo();
	
	for(i = 1; i <= 5; i++)
	{
		p = new Element;
		p->info = i;
		sl.push_back(p);
	}
	
	cout << "(C) : "; sl.showInfo();


	sl.pop_front();
	  
	cout << "(D) : ";   sl.showInfo();
	*/
	
	
	
	
	
	
/*	Stack S;
	int i;
	
	for(i=1;i<=10;i++) S.push(i);
	
	while(!S.empty())
	{
		cout << S.top()->info<<endl;
		S.pop();
	}
	*/
	
/*	Queue Q;
	int i;
	
	for(i=1; i<=10; i++) Q.push(i);
	
	while(!Q.empty())
	{
		cout << Q.front()<<endl;
		Q.pop();
	}*/
	
	
	return 0;

}
