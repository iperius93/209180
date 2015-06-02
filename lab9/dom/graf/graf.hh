#ifndef GRAF_HH_
#define GRAF_HH_

#include <iomanip>
#include <iostream>

/*!
 *	\file
	\brief Definicja klasy graf oraz slistEl
*/

const int MAXINT = 2147483647;

using namespace std;


/*!
 *	\brief Modeluje pojęcie slistEL
 *
 *	Struktura modeluje pojecie slistEl.
    Czyli jest to najmniejszy element listy jednokierunkowej.
*/
struct slistEl
{
  slistEl * next;
  int v,w;                        // numer węzła docelowego i waga krawędzi
};

/*!
 *	\brief Modeluje pojęcie graf
 *
 *	Klasa modeluje pojecie struktury danych jakim jest graf.
    Zawiera wierzchołki oraz krawedzie grafu. W pamięci
    zaisany ma rozmiar grafu ilosc wierzcholkow oraz krawedzi.
*/
class graf
{
    public:

    /*!
	 *	\brief Zmienne pomocnicze.
	 *
	 *	Zmienne pomocnicze do iteracji oraz do przechowywania
        rozmiaru grafu np. ilosc krawedzi oraz wierzchołków.
	*/
    int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S;

    /*!
	 *	\brief Lista sąsiedztwa.
	 *
	 *	Lista sąsiedztwa przechowuje informacje
        jak wyglada graf. Ktore krawędzie są ze
        sobą połączone lub nie.
	*/
    slistEl **sasiedztwo;                 // Tablica list sąsiedztwa
    slistEl *pw,*rw;
    bool *QS;//

	/*!
	 *	\brief Konstruktor klasy graf
	 *  \param wierzcholki - liczba wiezrcholkow w grafi
        \param krawedzie - liczba krawedzi w grafie

	 *	Tworzy graf o zadanej liczbie wierzchołkow oraz krawedzi.
        Tworzy zmienne dynamiczne przechowujące informacje o
        budowie grafu.
	*/
    graf(int wierzcholki, int krawedzie);

	/*!
	 *	\brief Destruktor klasy graf
	 *
	 *	Uruchamiany pod koniec pracy obiektu. Usuwa zmienne dzynamiczne
        zwalniajac tym samym pamiec komputera.
	*/
    ~graf();

	/*!
	 *	\brief Inicjalizuje graf danymi z zewnatrz.

        Inicjalizuje "wypełnia" wierzchołki danymi oraz wprowadza
            krawedzie do grafu, czyli połączenia pomiędzi poszczególnymi
            wierzchołkami grafu.
	*/
    void inicjalizuj();

    /*!
	 *	\brief Znajduje najkrótszą scieżke od początku do wierzchołka X

		\param poczatek - informuje gdzie jest początek scieżki, który wierzchołek jest początkiem
		\param X - szukany wierzchołek, do jakiego wierzchołka mamy szukać sciezke
	*/
    void find_min_sciezke(int poczatek, int X);

    /*!
	 *	\brief DFS - Przeszukiwanie w głąb.
		\param poczatek - od jakiego wierzchołka zaczynamy przeszukiwanie

		DFS - Depth-first search - przeszukiwanie w głąb. Metoda która
		przeszukuje (wyswietla) wierzchołki grafu w głąb.
	*/
    void DFS(int poczatek);

    /*!
	 *	\brief BFS - przeszukiwanie wszerz

		\param poczatek - od jakiego wierzchołka zaczynamy przeszukiwanie

		BFS - breadth-first search - przeszukiwanie wszerz. Metoda która
		przeszukuje (wyswietla) wierzchołki grafu wszerz.
	*/
    void BFS(int poczatek);
};

#endif
