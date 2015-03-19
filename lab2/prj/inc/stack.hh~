#ifndef STACK_HH
#define STACK_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

/*!
 *	\file 
	\brief Definicja klasy Stack
*/

#include "element.hh"

using namespace std;

/*!
 *	\brief Modeluje pojęcie Stack
 *
 *	Klasa modeluje pojecie Stack jest to klasa
	modelująca strukture danych Stos. Zawiera
	wskażnik typu Element.
*/
class Stack{

	/*!
	 *	\brief Wskażniki na pierwszy element Stosu.
	 *	
	 *	Wskaźniki na obiekt Element. Przechowuje adres
		na pierwszy element stosu.
	*/
	Element* S;
	
	public:
	/*!
	 *	\brief Konstruktor klasy Stack
	 *
	 *	Inicjalizuje adres początku stosu
		wartością NULL.	
	*/
	Stack()
	{
		S = NULL;
	}
	/*!
	 *	\brief Dekonstruktor klasy Stack
	 *
	 *	Czyści zawartość Stosu, aż do uzyskania
		wartości 0 "NULL" na adresie początku Stosu.	
	*/
	~Stack()
	{
		while(S) pop();
	}
	/*!
	 *	\brief Sprawdza czy aby Stos nie jest pusty, brak elementów.
	*/
	bool empty();
	/*!
	 *	\brief Metoda zwraca adres do elementu na samej górze.
		\return zawraca wskażnik na element na samej górze.

		Metoda która informuje nas jaki lement znajduje się
		na samej górze Stosu. Zwraca jego adres.
	*/
	Element* top(void);

	/*!
	 *	\brief Metoda dodaje element do Stosu.
		\param v - zawiera informacje ktora ma byc umieszczona w elemencie.

		Metoda dodaje nowy element do Stosu, zawartość informacji tego elementu
		przesyłąny jest w parametrze v.
	*/
	void push(int v);

	/*!
	 *	\brief Metoda zdejmuje element ze stosu.
		
		Metoda zdejmuje element ze stosu.
	*/
	void pop(void);

};

#endif
