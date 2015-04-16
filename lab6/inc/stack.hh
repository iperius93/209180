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
	tabele danych typu int
*/
class Stack
{
  private:
	/*!
	 	 * \brief Zmienna typu integer, przechowuje rozmiar tablicy danych.
	 	 * 
	 	 * Przechowuje rozmiar tablicy danych.
	*/
    int n;      
	/*!
	 	 * \brief Zmienna typu integer, wskazuje na wierzch stosu.
	 	 * 
	 	 * Zmienna ta wskazuje na wierzchołek stosu.
	*/
    int sptr;
	/*!
	 	 * \brief Wskażnik na dane typu integer, wskazuje na tablice danych.
	 	 * 
	 	 * Wskazuje na tablice danych, przechowuje dane jako stos.
	*/
    int * S;    

  public:
    /*!
     	 * \brief Konstruktor klasy Stack
     	 *
     	 *	\param x - rozmiar tablicy dynamicznej
  	  	 *
     	 * Tworzy nowy stos, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
     	 * 
    */
    Stack(int x); 
    /*!
     	 * \brief Destruktor klasy Stack
  	  	 *
     	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
     	 * 
    */
    ~Stack();    
    /*!
    * \brief Sprawdza czy aby Stos nie jest pusty, brak elementów.
    * 
    * \return Zwraca 1 jesli coś jest, lub 0 jesli jest pusty.
    */
    bool empty(void);
    
	/*!
	 	 * \brief Metoda zwraca wartość elementu na samej górze stosu.
		   \return zwraca wartosc elementu na samej górze.
		   
			Metoda która informuje nas jaki element znajduje się na samej górze Stosu. Zwraca jego wartosc.
	 */
    int  top(void);
    
	/*!
	 	 * \brief Metoda dodaje element do Stosu.
		   \param v - zawiera informacje ktora ma byc umieszczona w elemencie.
		   
		 Metoda dodaje nowy element do Stosu, zawartość informacji tego elementu przesyłąny jest w parametrze v.
    */
    void push(int v);
    
	/*!
	 	 * \brief Metoda zdejmuje element ze stosu.
	 	 *
			Metoda zdejmuje element ze stosu.
	 */
    void pop(void);
    
	/*!
	 	 * \brief Metoda zwiększa rozmiar tablicy o jeden element.
	 	 *
			Metoda zwiększa rozmiar tablicy dynamicznej o jeden element.
	 */
    void zwieksz_tablice_o_jeden();
    
	/*!
	 	 * \brief Metoda zwiększa rozmiar tablicy dwa razy.
	 	 *
			Metoda zwiększa rozmiar tablicy dynamicznej do dwu-krotności istniejącej tablicy dynamicznej.
	 */
    void zwieksz_tablice_dwarazy();
};

#endif
