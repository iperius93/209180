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
	modelująca strukture danych Lista_Jednokierunkowa.
*/
class Single_List
{
  private:
	/*!
	 	 * \brief Zmienna typu integer, przechowuje rozmiar tablicy danych.
	 	 * 
	 	 * Przechowuje rozmiar tablicy danych.
	*/
    int n;
    
	/*!
	 	 * \brief Zmienna typu integer, wskazuje na początek listy.
	 	 * 
	 	 * Zmienna ta wskazuje na początek listy.
	*/
    int front_ptr;
    
	/*!
	 	 * \brief Zmienna typu integer, wskazuje na koniec listy.
	 	 * 
	 	 * Zmienna ta wskazuje na koniec listy.
	*/
    int back_ptr;
    
	/*!
	 	 * \brief Zmienna typu integer, zlicza ilosc elementow na liscie.
	 	 * 
	 	 * Licznik elementow znajdujących się na liscie.
	*/
    int qcnt; 
    
	/*!
	 	 * \brief Wskażnik na dane typu integer, wskazuje na tablice danych.
	 	 * 
	 	 * Wskazuje na tablice danych, przechowuje dane jako lista jednokierunkowa.
	*/
    int *L;    

  public:
    
    /*!
     	 * \brief Konstruktor klasy Single_List
     	 *
     	 *	\param x - rozmiar tablicy dynamicznej
  	  	 *
     	 * Tworzy nową liste, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
     	 * 
    */
    Single_List(int x);
    
    /*!
     	 * \brief Destruktor klasy Single_List
  	  	 *
     	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
     	 * 
    */
    ~Single_List();  
    
    /*!
    * \brief Sprawdza czy aby Lista nie jest pusta, brak elementów.
    * 
    * \return Zwraca 1 jesli coś jest, lub 0 jesli jest pusta.
    */
    bool empty(void);
    
	/*!
	 	 * \brief Metoda zwraca wartość elementu na samym początku listy.
		   \return zwraca wartosc elementu na samym początku.
		   
			Metoda która informuje nas jaki element znajduje się na samym początku Listy. Zwraca jego wartosc.
	 */
    int  front(void);
    
	/*!
	 	 * \brief Metoda dodaje element na początek Listy.
		   \param v - zawiera informacje ktora ma byc umieszczona w elemencie.
		   
		 Metoda dodaje nowy element na początku Listy, zawartość informacji tego elementu przesyłąny jest w parametrze v.
    */
    void push_front(int v);
    
    /*!
    	 	 * \brief Metoda zdejmuje element z początku Listy.
    	 	 *
    			Metoda zdejmuje element z początku Listy.
    	 */
    void pop_front(void);
    
	/*!
	 	 * \brief Metoda zwraca wartość elementu na samym końcu listy.
		   \return zwraca wartosc elementu na samym koncu.
		   
			Metoda która informuje nas jaki element znajduje się na samym końcu Listy. Zwraca jego wartosc.
	 */
    int back(void);
    
	/*!
	 	 * \brief Metoda dodaje element na końcu Listy.
		   \param v - zawiera informacje ktora ma byc umieszczona w elemencie.
		   
		 Metoda dodaje nowy element na końcu Listy, zawartość informacji tego elementu przesyłąny jest w parametrze v.
    */
    void push_back(int v);
    
	/*!
	 	 * \brief Metoda zdejmuje element z końca Listy.
	 	 *
			Metoda zdejmuje element z końca Listy.
	 */
    void pop_back(void);
    
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
