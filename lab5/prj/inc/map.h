#ifndef  MAP_H
#define MAP_H

#include <iostream>
#include <string>

#include "element.h"
#include "hasz_tab.h"

/*!
 *	\file
	\brief Definicja klasy map
*/

using namespace std;

/*!
 *	\brief Modeluje pojęcie map
 *
 *	Klasa modeluje pojecie map jest to klasa
	modelująca tablicę asocjacyjną.
*/
template <typename type_key,typename type_value>
class map
{
    /*!
	 *	\brief wskażnik na obiekt typu hasz_tab.
	 *
	 *	Zmienna przechowywuje adres na tablice haszowaną.
	*/
    hasz_tab<type_key,type_value> *tablica_haszowana;

    /*!
	 *	\brief Zmienna przechowywująca rozmiar tablicy haszwanej.
	 *
	 *	Zmienna przechowywuje informacjeo rozmiarze tablicy haszowanej.
	*/
    int rozmiar;

    public:
    /*!
     	 * \brief Konstruktor klasy map
     	 *
     	 *	\param size - rozmiar tablicy haszowanej
  	  	 *
     	 * Tworzy obiekt dynamiczny typu hasz_tab, tworzy dynamiczny obiekt  o rozmiarze podanym w parametrze.
     	 *
    */
    map(int size);

    /*!
     	 * \brief Destruktor klasy map
  	  	 *
     	 * Niszczy dynamiczną zmienną, zwalnia pamięć.
     	 *
    */
    ~map();

    /*!
        * \brief Przeciążenie operatora [] .
        * \param key - klucz przesyłany do funkcji
        * \return Zwraca referencje na konkretny element tablicy typu element.

        Przeciążenie wyciąga konkretny element z tablicy za pomocą klucza przesyłanego do funkcji jako parametr.
        Funkcja wstawia również klucz do konkretnego elementu tablicy.
    */
    type_value& operator[] (type_key key)
    {
        ((*tablica_haszowana)[key]).klucz = key;
        return ((*tablica_haszowana)[key]).info;
    }
	
    /*!
        * \brief Funkcja szuka numeru ostatniego elementu tablicy asocjacyjnej.
        * \return Zwraca liczbe na którym miejscu znajduje się ostatni element.
    */
    int end();

    /*!
        * \brief Funkcja szuka elementu w tablicy asocjacyjnej.
        * \param key - klucz przesyłany do funkcji.
        * \return Zwraca liczbe na którym miejscu znajduje się element, jesli go nie ma zwraca adres ROZMIAR.

    */
    int find(type_key key);

   /*!
        * \brief Funkcja usuwa element z tablicy asocjacyjnej.
        * \param indeks - numer elementu do usunięcia

        Funkcja usuwa element który znajduje się pod numerem podanym w parametrze (indeks).
    */
    void erase(int indeks);
    #if STRING_KEY
    /*!
        * \brief Funkcja usuwa element z tablicy asocjacyjnej.
        * \param key - klucz elementu do usunięcia.

    */
    void erase(type_key key);
    #endif
    /*!
        * \brief Funkcja czysci tablice asocjacyjną.
    */
    void clear();

};

template <typename type_key,typename type_value>
map<type_key,type_value>::map(int size)
{
    tablica_haszowana = new hasz_tab<type_key,type_value>(size);
    rozmiar = size;
}

template <typename type_key,typename type_value>
map<type_key,type_value>::~map()
{
    delete tablica_haszowana;
}

/*!

     Funkcja przeglada cało tablice haszowana i zlicza ilosc elementow zwraca numer ostatniego elementu na tablicy haszowanej
	lub liczbe rozmiar jesli jest ona pusta.

*/
template <typename type_key,typename type_value>
int map<type_key,type_value>::end()
{
    int j=-1;
    for(int i=0;i<rozmiar;i++)
    {
	if( !( (*tablica_haszowana)[i].klucz == ZERO && (*tablica_haszowana)[i].info == 0 ) )    j++;    // jesli cos jest w elemencie
    }
    if(j == -1) return rozmiar;//nie znaleziono nic
    else return j;
}

/*!

    Funkcja ma za zadanie znalezienie elementu w tablicy asocjacyjenj i podanie jego pozycji w tablicy.

*/
template <typename type_key,typename type_value>
int map<type_key,type_value>::find(type_key key)
{
    int j=0; 
    for(int i=0;i<rozmiar;i++)
    {
	if( !( (*tablica_haszowana)[i].klucz == ZERO && (*tablica_haszowana)[i].info == 0 ) )  // jesli cos jest w elemencie
	{
	    if(  (*tablica_haszowana)[i].klucz == key )  return  j;   // jesli to jest to czego szukamy
	    j++;
	}
    }
    return rozmiar;   //jesli nie ma zwroc rozmiar

}

/*!

        Funkcja usuwa element który znajduje się pod numerem podanym w parametrze (indeks).

*/
template <typename type_key,typename type_value>
void map<type_key,type_value>::erase(int indeks)
{
    int j=-1;
    for(int i=0;i<rozmiar;i++)
    {
	if( !( (*tablica_haszowana)[i].klucz == ZERO && (*tablica_haszowana)[i].info == 0 ) )    j++;    // jesli cos jest w elemencie
	if(indeks == j)
	{
	     (*tablica_haszowana)[i].klucz = ZERO;
             (*tablica_haszowana)[i].info = 0;
	}
    }
}
#if STRING_KEY

/*!

    Funkcja usuwa element którego klucz pasuje do klucza wysłanego jako parametr funkcji(key).

*/
template <typename type_key,typename type_value>
void map<type_key,type_value>::erase(type_key key)
{
    (*tablica_haszowana)[key].klucz = ZERO;
    (*tablica_haszowana)[key].info = 0;
}
#endif

/*!

    Funkcja ma za zadanie wyczyszczenie całej tablicy asocjacyjnej.

*/
template <typename type_key,typename type_value>
void map<type_key,type_value>::clear()
{
    for(int i=0;i<rozmiar;i++)
    {
         (*tablica_haszowana)[i].info = 0;
         (*tablica_haszowana)[i].klucz = ZERO;
    }
}

#endif
