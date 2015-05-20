#ifndef DRZEWORB_HH
#define DRZEWORB_HH

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*!
 *	\file
	\brief Definicja klasy drzewoRB
*/

/*!
 *	\brief Modeluje pojęcie wezelRB
 *
 *	Klasa modeluje pojecie wezła drzewa jest to struktura
	zawierające niezbedne pola jakie musi posiadać wezeł
	drzewo czerwono - czarnego.
*/
struct wezelRB
{
    /*!
	 *	\brief Wskaznik na rodzica aktualnego wezła.
	 *
	 *	Pole jest wskanikiem ktore wskazuje na wezeł
	 * wyższy od aktualnego.
	*/
    wezelRB *rodzic;

    /*!
	 *	\brief Wskaznik na lewego potomka aktualnego wezła.
	 *
	 *	Pole jest wskaznikiem ktore wskazuje na wezeł
	 * o jeden niższy niz aktualny.
	*/
    wezelRB *lewy_syn;

    /*!
	 *	\brief Wskaznik na prawego potomka aktualnego wezła.
	 *
	 *	Pole jest wskaznikiem ktore wskazuje na wezeł
	 * o jeden niższy niz aktualny.
	*/
    wezelRB *prawy_syn;

    /*!
	 *	\brief Zmienna przechowujaca dane na wezle.
	 *
	 *	Pole przechowuje liczbe typu int ktora w
     *  naszym przypadku jest informacja zapisana w wezle.
	*/
    int wartosc;

    /*!
	 *	\brief Zmienna zawierajaca informacje o kolorze wezła.
	 *
	 *	Pole przechowuje informacje jakiego koloru jest dany
	 *  wezeł R - czerwony, B - czarny.
	*/
    char kolor;
};

/*!
 *	\brief Modeluje pojęcie drzewoRB
 *
 *	Klasa modeluje pojecie drzewaRB czyli drzewa
 *  czerwono - czarnego.
*/
class drzewoRB
{
  private:
    /*!
	 *	\brief Zmienna przechowuje informacje o strażniku
	 *
	 *	Pole zawiera informacje jak wygląda strażnik. Wykorzystywane
        do oznacznia liści (ostatnich pustych elementow) drzewa.
	*/
    wezelRB straznik;

    /*!
	 *	\brief Zmienna przechowuje informacje o korzeniu drzewa.
	 *
	 *	Pole zawiera informacje o początku całego drzewa, jest to pierwszy wezeł drzewa.
	*/
    wezelRB *korzen;

    /*!
	 *	\brief Zmienne typu string, pomocne przy wyswietlaniu drzewa.
	 *
	 *	Zmienne pomocne przy wyswietlaniu drzewa na konsoli.
	*/
    string cr,cl,cp;

	/*!
	 *	\brief Funkcja wyswietlajaca drzewo czerwono - czarne.

		\param sp -
		\param sn -
		\param p - wskaznik na wezeł od ktorego zaczynamy wyswietlanie.
	*/
    void wyswietlRB(string sp, string sn, wezelRB *p);

  public:
	/*!
	 *	\brief Konstruktor klasy drzewoRB
	 *
	 *	Inicjalizuje strażnika, inicjalizuje pole korzen jako strażnik (puste drzewo).
	*/
    drzewoRB();

	/*!
	 *	\brief Dekonstruktor klasy drzewoRB
	 *
	 *	Niszczy całą strukture drzewa, zwalniając przy tym miejsce pamięci.
	*/
    ~drzewoRB();

	/*!
	 *	\brief Niszczy drzewo, zwalniajac przy tym miejsce pamięci.

		\param p - wskaznik na wezel od ktorego ma nastopić niszczenie drzewa
	*/
    void zniszcz(wezelRB *p);

	/*!
	 *	\brief Wysietla całe drzewo czyli od korzenia aż po liście.

	*/
    void print();

 	/*!
	 *	\brief Funkcja odpowiedzialna za wyszukiwanie elementow na drzewie.

		\param k - wartość jakiej szukamy na drzewie
		\return Zwraca adres na znaleziony wezeł.
	*/
    wezelRB* szukaj(int k);

 	/*!
	 *	\brief Wyszukuje najmniejszy węzeł w poddrzewie o korzeniu p

		\param p - adres poddrzewa w którym szukamy najmniejszego wezła
		\return Zwraca adres najmniejszego wezła w podtrzewie p.
	*/
    wezelRB* min_wezel(wezelRB *p);

  	/*!
	 *	\brief Wyszukuje następnika w poddrzewie o korzeniu p.

		\param p - adres poddrzewa w którym szukamy następnika wezła
		\return Zwraca adres nastpnika wezła w poddrzewie p.
	*/
    wezelRB* nastepca(wezelRB *p);

 	/*!
	 *	\brief Funkcja dokonująca rotacji w lewo wezełow w drzewie.

		\param A - jest to adres wezła względem którego dokonujemy rotacji.
	*/
    void rot_L(wezelRB *A);

	/*!
	 *	\brief Funkcja dokonująca rotacji w prawo wezełow w drzewie.

		\param A - jest to adres wezła względem którego dokonujemy rotacji.
	*/
    void rot_R(wezelRB *A);

 	/*!
	 *	\brief Dodaje nowy wezel do drzewa.

		\param k - informacja w postaci liczby jaka przechowuje nowy wezel
	*/
    void dodaj(int k);

	/*!
	 *	\brief Usuwa wezeł którego adres podany jest jako parametr.

		\param X - adres wezła które ma zostać usunięte.
	*/
    void usun(wezelRB *X);
};

#endif
