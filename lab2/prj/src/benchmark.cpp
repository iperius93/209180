#include "benchmark.hh"

/*!
 *   \file
 *   \brief Definicja metod klasy Benchmark
 *
 *
 *
 *
*/

using namespace std;

/*!
 * Metoda ktora generuje liczby losowe, 
   ilosc wygenerowanych liczb zawiera parametr 
   o nazwie ilosc, zakres wylosowanych liczb 
   zalezy od zmiennej zakres. Wylosowane 
   liczby zapisywane są do pliku danych.
 */

void Benchmark::generuj_liczby(int ilosc, int zakres)
{
	srand(time(NULL));
	plik_danych.open("dane.txt",std::ios::out);
	if( plik_danych.good() == true )
	{
		for(int i=0;i<ilosc;i++)
		{
			plik_danych << ((rand() % zakres) + 0)<<' ';
		}
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;
	
	plik_danych.close();
}

/*!
 * Metoda ktora testuje obiekt typu Lista wysłany jako parametr. 
   Testuj za pomocą określonej ilosci danych, ilosc danych zawarta jest w zmiennej ilosc_liczb.
   Metoda testuje program kilka razy w zaleznosci od zmiennej powtorzenia.
 */
void Benchmark::testuj(Lista Testowa, int rodzaj_listy, int powtorzenia, int ilosc_liczb)
{
	
	double suma_czas = 0;
	double czas=0;
	timeval *start = new timeval;
	timeval *stop = new timeval;

	for(int j=0;j<powtorzenia;j++)
	{
		gettimeofday(start, NULL);
		if(rodzaj_listy == 1) Testowa.wczytaj_dane_list(ilosc_liczb);
		else if(rodzaj_listy == 2) Testowa.wczytaj_dane_queue(ilosc_liczb);
		else if(rodzaj_listy == 3) Testowa.wczytaj_dane_stack(ilosc_liczb);
		else cerr << "Bledny kod"<<endl;
		gettimeofday(stop,NULL);
		czas = stop->tv_usec - start->tv_usec;
		suma_czas += czas;
		if(rodzaj_listy == 1) Testowa.wyswietl_dane_list();
		else if(rodzaj_listy == 2) Testowa.wyswietl_dane_queue();
		else if(rodzaj_listy == 3) Testowa.wyswietl_dane_stack();
		else cerr << "Bledny kod"<<endl;
	}
	double srednia;
	srednia = suma_czas/powtorzenia;
	
	plik_wynikow.open("wyniki.txt",std::ios::out | std::ios::app);
	if( plik_wynikow.good() == true )
	{
		plik_wynikow << ilosc_liczb <<' '<<srednia<<endl;
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;
	
	plik_wynikow.close();
}

