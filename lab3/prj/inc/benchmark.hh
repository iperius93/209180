#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "queue.hh"
#include "stack.hh"
#include "single_list.hh"

/*!
 *	\file 
	\brief Definicja klasy Benchmark
*/
using namespace std;

/*!
 *	\brief Modeluje pojęcie Benchmark
 *
 *	Klasa modeluje pojecie testu Benchmark jest to klasa
	testujaca rożne rodzaje struktur danych, klasa odpowiada za 
	wygenerowanie liczb losowych, zapisanie ich do pliku,
	wczytanie okreslonej liczby danych do struktury i przetestowanie
	struktury danych, oraz obliczenie jej zlozonosci.
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
	 *	\brief Testuje Liste Jednokierunkowa i zapisuje wyniki do pliku wynikow.

		\param Testowa - wskaznik na obiekt typu Single_List, tetsowany obiekt
		\param powtorzenia - ilosc powtorzen testu
		\param ilosc_liczb - ile liczb wykorzystamy do testu
	*/
	void testuj_list(Single_List *Testowa, int powtorzenia, int ilosc_liczb);
	
	/*!
	 *	\brief Testuje Kolejke i zapisuje wyniki do pliku wynikow.

		\param Testowa - wskaznik na obiektu typu Queue , tetsowany obiekt
		\param powtorzenia - ilosc powtorzen testu
		\param ilosc_liczb - ile liczb wykorzystamy do testu
	*/
	void testuj_queue(Queue *Testowa, int powtorzenia, int ilosc_liczb);
	
	/*!
	 *	\brief Testuje Stos i zapisuje wyniki do pliku wynikow.

		\param Testowa - wskaznik na obiektu typu Stack , tetsowany obiekt
		\param powtorzenia - ilosc powtorzen testu
		\param ilosc_liczb - ile liczb wykorzystamy do testu
	*/
	void testuj_stack(Stack *Testowa, int powtorzenia, int ilosc_liczb);
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
