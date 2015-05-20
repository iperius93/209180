#include "benchmark.h"
#include "drzewoRB.h"

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
 * Metoda ktora testuje obiekt typu drzewoRB wysłany jako wskaźnik.
   Testuj za pomocą określonej ilosci danych, ilosc danych zawarta jest w zmiennej ilosc_liczb.
   Metoda testuje program kilka razy w zaleznosci od zmiennej powtorzenia.
 */
void Benchmark::testuj(drzewoRB *Testowe, int powtorzenia, int ilosc_liczb)
{
	cout << ilosc_liczb << endl;
	float suma_czas = 0;
	float czas=0, czas2 = 0;
	clock_t start= 0, start2 = 0;

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
				Testowe->dodaj(dane);
			}
			czas = (((float)(clock()-start))/1000);
		} else cout << "Dostep do pliku zostal zabroniony!" << endl;

		plik_danych.close();

		suma_czas += czas;
	}
	double srednia;
	srednia = suma_czas/powtorzenia;

    start2 = clock();
    Testowe->szukaj(((rand() % 100) + 0));
    czas2 = (((float)(clock()-start2))/1000);

    double srednia2;
    srednia2 = czas2/powtorzenia;

	plik_wynikow.open("wyniki.txt",std::ios::out | std::ios::app);
    if( plik_wynikow.good() == true )
	{
		plik_wynikow << ilosc_liczb <<' '<<srednia<<' '<<srednia2<<endl;
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;

	plik_wynikow.close();
}

