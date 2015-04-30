#ifndef SINGLE_LIST_HH
#define SINGLE_LIST_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

/*!
 *	\file 
	\brief Definicja klasy Single_List
*/

#include "element.hh"

using namespace std;	

/*!
 *	\brief Modeluje pojęcie Single_List
 *
 *	Klasa modeluje pojecie Single_List jest to klasa
	modelująca strukture danych Lista_Jednokierunkowa. Zawiera
	dwa wskażniki typu Element. Jeden jako początek 
	Listy, drugi jako koniec Listy.
*/
class Single_List {
	/*!
	 *	\brief Wskażniki początek i koniec Listy.
	 *	
	 *	Wskaźniki na obiekt Element. Pierwszy przechowuje
		adres początku Listy, drugi przechowuje adres 
		końca Listy.
	*/
	Element *front, *back;
	/*!
	 *	\brief Zmienna przechowywująca ilość elementow.
	 *	
	 *	Zmienna typu int, ktora zawiera liczbe elementow 
		w Liscie.
	*/
	int counter;
	
	public:
		/*!
	 *	\brief Konstruktor klasy Single_List
	 *
	 *	Inicjalizuje adres początku oraz końca kolejki
		wartością NULL.	
		Licznik elementów ustawia na 0;
	*/
	Single_List()
	{
		front=back=NULL;
		counter = 0;
	}
	/*!
	 *	\brief Dekonstruktor klasy Single_List
	 *
	 *	Czyści zawartość Listy, aż do uzyskania
		wartości 0 "NULL" na adresie początku Listy.	
	*/
	~Single_List()
	{
		Element *p;
		
		while(front)
		{
			p = front->next;
			delete front;
			front = p;
		}
	}
	/*!
	 *	\brief Metoda informująca o ilosci elementow.
	 *	\return Zwraca liczbe typu int, ktora informuje o liczbie elementow na Liscie.	
	*/
	int size();
	/*!
	 *	\brief Metoda dodaje element na początku Listy.
		\param p - obiekt typu Element, zostanie umieszczony na Liscie.
		\return zawraca wskażnik na nowy element.

		Metoda dodaje nowy element na początku Listy, element który 
		ma być umieszczony wysyłany jest jako parametr.
	*/
	Element* push_front(Element * p);
	/*!
	 *	\brief Metoda dodaje element na końcu Listy.
		\param p - obiekt typu Element, zostanie umieszczony na Liscie.
		\return zawraca wskażnik na nowy element.

		Metoda dodaje nowy element na końcu Listy, element który 
		ma być umieszczony wysyłany jest jako parametr.
	*/
	Element* push_back(Element *p);

	/*!
	 *	\brief Metoda zdejmuje element z początku Listy.
		\return Zwraca adres na zdjęty element.

		Metoda zdejmuje element z początku listy, zwraca adres na zdjęty element.
	*/
	Element* pop_front();

	/*!
	 *	\brief Metoda zdejmuje element z końca Listy.
		\return Zwraca adres na zdjęty element.

		Metoda zdejmuje element z końca listy, zwraca adres na zdjęty element.
	*/
	Element* pop_back();
		
	/*!
	 *	\brief Metoda wyświetla zawartość całej Listy
		\return Zwraca adres na zdjęty element.

		Metoda wyświetla zawartość całej Listy.
	*/
	void showInfo();

};

#endif
