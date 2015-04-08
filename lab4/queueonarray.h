
#ifndef QUEUE_ON_ARRAY_HH
#define QUEUE_ON_ARRAY_HH

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


using namespace std;
/*!
 *	\brief Modeluje pojęcie Queue
 *
 *	Klasa modeluje pojecie Queue jest to klasa
	modelująca strukture danych Kolejka.
*/
class QueueOnArray
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
    int *tableOfData;    // tablica dynamiczna

  public:
    /*!
     	 * \brief Konstruktor klasy Queue
     	 *
     	 *	\param x - rozmiar tablicy dynamicznej
  	  	 *
     	 * Tworzy nową kolejke, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
     	 *
    */
    QueueOnArray();
    /*!
     	 * \brief Destruktor klasy Queue
  	  	 *
     	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
     	 *
    */
    ~QueueOnArray();

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
	/*!
	 	 * \brief Metoda sortuje kolejke.
	 	 *
			Metoda sortująca dane przechowywane w kolejce (tablica dynamiczna) za pomocą sortowanie szybkiego.
	 */
    void quicksort(int lewy, int prawy);
	/*!
	 	 * \brief Metoda zwracająca wartość pola qptr.
	 	 *
			Metoda zapewnia dostęp do prywatnego pola qptr które wskazuje na poczatek kolejki.
	 */
    int returnQPTR();
	/*!
	 	 * \brief Metoda zwracająca wartość pola qcnt.
	 	 *
		 *	Metoda zapewnia dostęp do prywatnego pola qcnt które wskazuje na koniec kolejki.
    */
    int returnQCNT();
	/*!
	 	 * \brief Metoda wyswietlajaca zawartosc kolejki.
	 	 *
			Metoda odpowiedzialna jest za wyswietlenie zawartości kolejki.
	 */
    void wyswietl_kolejke();

};


#endif
