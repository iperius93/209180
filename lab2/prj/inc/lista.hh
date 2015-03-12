#ifndef LISTA_HH
#define LISTA_HH

/*!
 *	\file 
	\brief Definicja klasy Lista

*/

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*!
 *	\brief Modeluje pojęcie Lista
 *
 *	Klasa modeluje pojecie Listy w naszym przypadku
 *	tablice o zadanym rozmiarze w zmiennej ilosc 
 * 	typu int.
*/

class Lista
{
	/*!
	 *	\brief Wskaznik na tablice typu int.
	 *	
	 *	Pole jest wzkaznikiem na tablice ktora 
	 *	zawiera pola typu int.
	*/
	int *tablica;
	/*!
	 *	\brief Zmienna typu int, ktora przechowuje 
	 *	ile elementow ma tablica.
	*/
	int ilosc;
	
	/*!
	 *	\brief Konstruktor klasy Lista
	 *
	 *	Tworzy dynamiczna tablice za pomocą 
		wskaznika tablica, ilosc elementow zalezy 
		od parametru ilosc_liczb.
		\param ilosc_liczb - ilosc pol w tablicy
		\pre - brak
		
	*/
	public:
	Lista(int ilosc_liczb)
	{
		tablica = new int [ilosc_liczb];
		ilosc=ilosc_liczb;
	}
	
	/*!
	 *	\brief Wczytuje dane do tablicy.
	*/
	void wczytaj_dane();

	/*!
	 *	\brief Wyswietla dany do tablicy.
	*/
	void wyswietl_dane();

	/*!
	 *	\brief Zwraca adres do tablicy, typu int.
	*/
	int* zwroc_adres();
};


#endif
