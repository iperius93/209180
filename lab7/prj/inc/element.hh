#ifndef ELEMENT_HH
#define ELEMENT_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
/*!
 *	\file 
	\brief Definicja struktury Element
*/

/*!
	\brief Modeluje pojęcie Element	

	Struktura Element jest podstawową 
	jednostką (elementem) należącą do klasy
	Single_List, Queue, Stack.
*/
struct Element {
	/*!
	 *	\brief Zmienna przechowywująca informacje zawarta w elemencie.
	 *	
	 *	Zmienna przechowywuje informacje, która zawiera cały element.
	*/
	int info;
	/*!
	 *	\brief Wskaźnik na następny element.
	 *	
	 *	Wskażnik przechowywujący adres na następny element struktury danych.
	*/
	Element *next;
};


#endif
