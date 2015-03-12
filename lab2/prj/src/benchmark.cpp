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
void Benchmark::testuj(Lista Testowa, int* dane, int powtorzenia, int ilosc_liczb)
{
	Testowa.wczytaj_dane();
	
	double suma_czas = 0;
	double czas=0;
	timeval *start = new timeval;
	timeval *stop = new timeval;

	for(int j=0;j<powtorzenia;j++)
	{
		gettimeofday(start, NULL);
		for(int i=0;i<ilosc_liczb;i++)
		{
			dane[i] = dane[i] * 2;
		}
		gettimeofday(stop,NULL);
		czas = stop->tv_usec - start->tv_usec;
		suma_czas += czas;
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

