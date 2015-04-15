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
 * Metoda ktora testuje obiekt typu Single_List wysłany jako wskaźnik. 
   Testuj za pomocą określonej ilosci danych, ilosc danych zawarta jest w zmiennej ilosc_liczb.
   Metoda testuje program kilka razy w zaleznosci od zmiennej powtorzenia.
 */

void Benchmark::testuj_list(Single_List *Testowa, int powtorzenia, int ilosc_liczb)
{
	cout << ilosc_liczb << endl;
	double suma_czas = 0;
	double czas=0;
	clock_t start = 0;
	int dane=0;
	fstream plik_danych;

	for(int j=0;j<powtorzenia;j++)
	{
		dane=0;
		plik_danych.open("dane.txt",std::ios::in);
		if( plik_danych.good() == true )
		{
			start = clock();
			for(int i=0;i<ilosc_liczb;i++)
			{
				plik_danych >> dane;
				(*Testowa).push_back(dane);
			}
			czas = (((float)(clock()-start))/1000);
		} else cout << "Dostep do pliku zostal zabroniony!" << endl;
				
		plik_danych.close();
		suma_czas += czas;
		
		while(!(*Testowa).empty())
		{
			//cout << (*Testowa).front()<<endl;
			(*Testowa).pop_front();
		}
		
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

/*!
 * Metoda ktora testuje obiekt typu Queue wysłany jako wskaźnik. 
   Testuj za pomocą określonej ilosci danych, ilosc danych zawarta jest w zmiennej ilosc_liczb.
   Metoda testuje program kilka razy w zaleznosci od zmiennej powtorzenia.
 */
void Benchmark::testuj_queue(Queue *Testowa, int powtorzenia, int ilosc_liczb)
{
	cout << ilosc_liczb << endl;
	float suma_czas = 0;		// zsumowany czas wukonywanych operacji
	float czas=0;				// czas na jeden test
	clock_t start = 0;			// start testu
	int dane=0;					// zmienna pobrana z pliku
	fstream plik_danych;		// plik danych
	
	for(int j=0;j<powtorzenia;j++)			// ile powtorzen testu
	{
		dane=0;
		plik_danych.open("dane.txt",std::ios::in);		// otworz plik
		if( plik_danych.good() == true )
		{
			start = clock();		// start testu
			for(int i=0;i<ilosc_liczb;i++)		// ile liczb wczytac
			{		
				plik_danych >> dane;		// wczytaj dane 
				(*Testowa).push(dane);		// umiesc na kolejce
			}
			czas = (((float)(clock()-start))/1000);		// stop test, zapisz czas
		} else cout << "Dostep do pliku zostal zabroniony!" << endl;
				
		plik_danych.close();
		suma_czas += czas;		// zsumuj czasy testow
		
		while(!(*Testowa).empty())
		{
			//cout << (*Testowa).front()<<endl;    // wyswietl dane na kolejce
			(*Testowa).pop();					// zdejmij wszystkie dane z kolejki
		}
		
	}
	double srednia;		
	srednia = suma_czas/powtorzenia;		// oblicz sredni czas testu
	
	plik_wynikow.open("wyniki.txt",std::ios::out | std::ios::app);		//otworz plik z wynikami
	if( plik_wynikow.good() == true )
	{
		plik_wynikow << ilosc_liczb <<' '<<srednia<<endl;			// zapisz wynik do pliku 
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;
	
	plik_wynikow.close();
}

/*!
 * Metoda ktora testuje obiekt typu Stack wysłany jako wskaźnik. 
   Testuj za pomocą określonej ilosci danych, ilosc danych zawarta jest w zmiennej ilosc_liczb.
   Metoda testuje program kilka razy w zaleznosci od zmiennej powtorzenia.
 */
void Benchmark::testuj_stack(Stack *Testowa, int powtorzenia, int ilosc_liczb)
{
	cout << ilosc_liczb << endl;
	float suma_czas = 0;
	float czas=0;
	clock_t start= 0;
	
	int dane=0;
	fstream plik_danych;
	
	for(int j=0;j<powtorzenia;j++)
	{
		dane=0;
		plik_danych.open("dane.txt",std::ios::in);
		if( plik_danych.good() == true )
		{
			start = clock();
			for(int i=0;i<ilosc_liczb;i++)
			{
				plik_danych >> dane;
				(*Testowa).push(dane);
			}
			czas = (((float)(clock()-start))/1000);
		} else cout << "Dostep do pliku zostal zabroniony!" << endl;
		
		plik_danych.close();
		
		suma_czas += czas;
		
		while(!(*Testowa).empty())
		{
			//cout << (*Testowa).top()<<endl;
			(*Testowa).pop();
		}
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

