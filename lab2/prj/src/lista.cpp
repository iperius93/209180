#include "lista.hh"

using namespace std;

/*!
 *   \file
 *   \brief Definicja metod klasy Macierz
 *
 *
 *
 *
*/


/*!
 * Metoda ktora otwiera plik w ktorym znajduja 
   się wygenerowane liczby, i wczytuje te 
   liczby do tablicy w obiekcie typu Lista.
 */
void Lista::wczytaj_dane()
{
	fstream plik_danych;
	plik_danych.open("dane.txt",std::ios::in);
	if( plik_danych.good() == true )
	{
		for(int i=0;i<ilosc;i++)
		{
			plik_danych >> tablica[i];
		}
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;
	
	plik_danych.close();
}



/*!
 * Metoda ktora wyswietla liczby przechowywane przez tablice.
 */
void Lista::wyswietl_dane()
{
	for(int i=0;i<ilosc;i++)
	{
		cout << tablica[i] << endl;
	}
}



/*!
 * Metoda zwraca adres do prywatnego pola klasy Lista, czyli adres tablicy typu int.
 */
int* Lista::zwroc_adres()
{
	return tablica;
}

