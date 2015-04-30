#ifndef QUEUE_HH
#define QUEUE_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

/*!
 *	\file 
	\brief Definicja klasy Queue
*/

#include "element.hh"

using namespace std;
/*!
 *	\brief Modeluje pojęcie Queue
 *
 *	Klasa modeluje pojecie Queue jest to klasa
	modelująca strukture danych Kolejka. Zawiera
	dwa wskażniki typu Element. Jeden jako początek 
	Kolejki, drugi jako koniec Kolejki.
*/
class Queue
{
	/*!
	 *	\brief Zmienne początek i koniec Kolejki.
	 *	
	 *	Wskaźniki na obiekt Element. Pierwszy przechowuje
		adres początku Kolejki, drugi przechowuje adres 
		końca Kolejki.
	*/
	Element *head, *tail;
	
	public:
	/*!
	 *	\brief Konstruktor klasy Queue
	 *
	 *	Inicjalizuje adres początku oraz końca kolejki
		wartością NULL.	
	*/
	Queue()
	{
		head = tail = NULL;
	}
	/*!
	 *	\brief Dekonstruktor klasy Queue
	 *
	 *	Czyści zawartość Kolejki, aż do uzyskania
		wartości 0 "NULL" na adresie początku kolejki.	
	*/
	~Queue()
	{
		while(head) pop();
	}
	
	/*!
	 *	\brief Sprawdza czy aby kolejka nie jest pusta, brak elementów.
	*/
	bool empty();
	
	/*!
	 *	\brief Metoda zwraca wartość typu int, jest to wartość 
		informacji zawartej w elemenci na pierwszym miejscu.
		
		\return Zwraca wartosc informacji elementu.
	*/
	int front();

	/*!
	 *	\brief Metoda dodaje element do Kolejki.
		\param v - zawiera informacje ktora ma byc umieszczona w elemencie.

		Metoda dodaje nowy element do kolejki, zawartość informacji tego elementu
		przesyłąny jest w parametrze v.
	*/
	void push(int v);
	/*!
	 *	\brief Metoda zdejmuje element z kolejki.
		
		Metoda zdejmuje element z kolejki.
	*/
	void pop();
};


#endif
