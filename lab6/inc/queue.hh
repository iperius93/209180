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
	modelująca strukture danych Kolejka.
*/
class Queue
{
  private:

	/*!
	 	 * \brief Zmienna typu integer, przechowuje rozmiar tablicy danych.
	 	 *
	 	 * Przechowuje rozmiar tablicy danych.
	*/
    int n;

	/*!
	 	 * \brief Zmienna typu integer, wskazuje na początek kolejki.
	 	 *
	 	 * Zmienna ta wskazuje na początek kolejki.
	*/
    int qptr;

	/*!
	 	 * \brief Zmienna typu integer, zlicza ilosc elementow w kolejce
	 	 *
	 	 * Licznik elementow znajdujących się w kolejce.
	*/
    int qcnt;

	/*!
	 	 * \brief Wskażnik na dane typu integer, wskazuje na tablice danych.
	 	 *
	 	 * Wskazuje na tablice danych, przechowuje dane jako kolejka.
	*/
    int * Q;    // tablica dynamiczna

    int *pom;

  public:
    /*!
     	 * \brief Konstruktor klasy Queue
     	 *
     	 *	\param x - rozmiar tablicy dynamicznej
  	  	 *
     	 * Tworzy nową kolejke, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
     	 *
    */
    Queue(int x);
    /*!
     	 * \brief Destruktor klasy Queue
  	  	 *
     	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
     	 *
    */
    ~Queue();

    /*!
    * \brief Sprawdza czy aby Kolejka nie jest pusta, brak elementów.
    *
    * \return Zwraca 1 jesli coś jest, lub 0 jesli jest pusta.
    */
    bool empty(void);

	/*!
	 	 * \brief Metoda zwraca wartość elementu na samym początku kolejki.
		   \return zwraca wartosc elementu na samym początku.

			Metoda która informuje nas jaki element znajduje się na samym początku Kolejki. Zwraca jego wartosc.
	 */
    int  front(void);

	/*!
	 	 * \brief Metoda dodaje element na końcu Kolejki.
		   \param v - zawiera informacje ktora ma byc umieszczona w elemencie.

		 Metoda dodaje nowy element na końcu Kolejki, zawartość informacji tego elementu przesyłąny jest w parametrze v.
    */
    void push(int v);

    /*!
      	 	 * \brief Metoda zdejmuje element z początku Kolejki.
      	 	 *
      			Metoda zdejmuje element z początku Kolejki.
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

    void wyswietl_kolejke()
    {
        for(int i=qptr;i<qcnt;i++)
        {
            cout<<" "<<Q[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
    }

    void scal(int lewy, int srodek, int prawy);
    void merge_sort();
    void merge_sort_wew(int lewy, int prawy);
};


#endif
