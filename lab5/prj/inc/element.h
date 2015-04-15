#ifndef ELEMENT_HH
#define ELEMENT_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

#define ZERO ""
#define STRING_KEY 1

/*!
 *	\file
	\brief Definicja struktury element
*/

using namespace std;

/*!
	\brief Modeluje pojęcie element

	Struktura Element jest podstawową
	jednostką (elementem) należącą do klasy
	hasz_tab.
*/
template <typename type_key,typename type_value>
struct element {

	/*!
	 *	\brief Zmienna przechowywująca informacje zawarta w elemencie.
	 *
	 *	Zmienna przechowywuje informacje, która zawiera cały element.
	*/
	type_value info;

    /*!
	 *	\brief Zmienna przechowywująca klucz elementu.
	 *
	 *	Zmienna przechowywuje klucz, która związana jest z informacją.
	*/
	type_key klucz;

    /*!
     	 * \brief Konstruktor struktury element
     	 *
     	 * Inicjalizuje dwa pola struktury (info oraz klucz) zerami, zależnie od typu, string "", int 0 (zerem).
     	 *
    */
	element()
	{
	    info = 0;
	    klucz = ZERO;
	}
};


#endif

