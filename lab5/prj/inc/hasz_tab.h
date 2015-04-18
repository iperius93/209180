#ifndef  HASZ_TAB_H
#define HASZ_TAB_H

#include <iostream>
#include <string>

#include "element.h"

/*!
 *	\file
	\brief Definicja klasy hasz_tab
*/

using namespace std;

/*!
 *	\brief Modeluje pojęcie hasz_tab
 *
 *	Klasa modeluje pojecie hasz_tab jest to klasa
	modelująca strukture danych jakim jest tablica mieszająca.
*/
template <typename type_key,typename type_value>
class hasz_tab
{
    /*!
	 *	\brief Wskaźnik typu element wskazuje na tablice złożoną z elementow.
	 *
	 *	Zmienna przechowuje wskażnik na tablice typu element.
	*/
    element<type_key,type_value> *tab;

    /*!
	 *	\brief Zmienna przechowywująca rozmiar tablicy.
	 *
	 *	Zmienna przechowywuje informacjena temat rozmiaru tablicy w obiekcie.
	*/
    int rozmiar;

    public:
        /*!
     	 * \brief Konstruktor klasy hasz_tab
     	 *
     	 *	\param size - rozmiar tablicy dynamicznej
  	  	 *
     	 * Tworzy nową tablice haszowana, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
     	 *
    */
    hasz_tab(int size);

    /*!
     	 * \brief Destruktor klasy hasz_tab
  	  	 *
     	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
     	 *
    */
    ~hasz_tab();

    /*!
        * \brief Przeciążenie operatora [] .
        * \param key - klucz przesyłany do funkcji
        * \return Zwraca referencje na konkretny element tablicy typu element.

        Przeciążenie wyciąga konkretny element z tablicy za pomocą klucza przesyłanego do funkcji jako parametr.
    */
    element<type_key,type_value>& operator[] (type_key key)
    {
        return tab[hf(key)];
    }
    #if STRING_KEY
    /*!
        * \brief Przeciążenie operatora []
        * \param indeks - numer elementu przesyłany do funkcji
        * \return Zwraca referencje na konkretny element tablicy typu element.
    */
    element<type_key,type_value>& operator[] (int indeks)
    {
        return tab[indeks];
    }
    #endif
    /*!
        * \brief Funkcja haszująca do tablicy mieszającej.
        * \param key - klucz na podstawie ktorego obliczany jest indeks
        * \return Zwraca indeks obliczony na podstawie klucza.
    */
    unsigned int hf(type_key key);
};



template <typename type_key,typename type_value>
hasz_tab<type_key,type_value>::hasz_tab(int size)
{
    tab = new element<type_key,type_value>[size];
    rozmiar=size;
}


template <typename type_key,typename type_value>
hasz_tab<type_key,type_value>::~hasz_tab()
{
    delete [] tab;
}

/*!
    Funkcja haszująca do tablicy mieszającej. Sumuje wszystkie wartości string'a i
    oblicza reszte z dzielenia przez rozmiar tablicy. Wynikiem obliczeń jest indeks
    w tablicy gdzie przypisany zostanie element, wraz z informacją.
*/
template <typename type_key,typename type_value>
unsigned int hasz_tab<type_key,type_value>::hf(type_key key)
{
    #if STRING_KEY
    unsigned int klucz_haszujacy = 0;

    for(int i = 0; i<key.length();i++)
    {
        klucz_haszujacy += key[i]*i;          //suma znakow klucza
    }

    klucz_haszujacy %= rozmiar;    //modula = reszta z dzialenia

    return klucz_haszujacy;
    #else
    unsigned int klucz_haszujacy = key;
    return klucz_haszujacy;
    #endif


}
#endif
