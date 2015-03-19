#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*!
 *	\file 
	\brief Definicja klasy Benchmark
*/

#include "lista.hh"

/*!
 *	\brief Modeluje pojęcie Benchmark
 *
 *	Klasa modeluje pojecie testu Benchmark jest to klasa
	testujaca rożne rodzaje List, klasa odpowiada za 
	wygenerowanie liczb losowych, zapisanie ich do pliku,
	wczytanie okreslonej liczby danych do Listy i przetestowanie
	listy, oraz obliczenie jej zlozonosci.
*/

class Benchmark
{
	/*!
	 *	\brief Zmienna skojarzona z plikiem danych.
	 *	
	 *	Pole jest skojarzone z plikiem ktore zawiera 
	 *	wylosowane liczby. 
	*/
	fstream plik_danych;
	/*!
	 *	\brief Zmienna skojarzona z plikiem wynikow.
	 *	
	 *	Pole jest skojarzone z plikiem ktore zawiera 
	 *	wyniki testow, czyli ilosc danych oraz 
		odpowiadajacy im czas wykonywania operacji.
	*/
	fstream plik_wynikow;
	
	public:
	/*!
	 *	\brief Generuje losowe liczby i zapisuje do pliku.
		
		\param ilosc - parametr zawiera ile liczb ma wygenerować
		\param zakres - parametr zawiera zakres wylosowanyc liczb [0:zakres]
	*/
	void generuj_liczby(int ilosc, int zakres);
	
	/*!
	 *	\brief Testuje Liste i zapisuje wyniki do pliku wynikow.

		\param Testowa - obiekt typu Lista, tetsowany obiekt
		\param rodzaj_listy - wskazuje na jakiej strukturze danych pracujemy
		\param powtorzenia - ilosc powtorzen testu
		\param ilosc_liczb - ile liczb wykorzystamy do testu
	*/
	void testuj(Lista Testowa, int rodzaj_listy, int powtorzenia, int ilosc_liczb);
	
	/*!
	 *	\brief Konstruktor klasy Benchmark
	 *
	 *	Otwiera plik wynikow oraz usuwa z niego zawartość.	
	*/
	Benchmark()
	{
		plik_wynikow.open("wyniki.txt",ios::out | ios::trunc);
		if( plik_wynikow.good() == true )
		{

		} else cout << "Dostep do pliku zostal zabroniony!" << endl;
		
		plik_wynikow.close();
	}
	
};


#endif
