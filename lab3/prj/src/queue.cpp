#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "queue.hh"

/*!
 *   \file
 *   \brief Definicja metod klasy Queue
*/

using namespace std;

/*!

  	 * Tworzy nową kolejke, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
 */
Queue::Queue(int x)
{
  n = x;
  Q = new int[x];
  qptr = qcnt = 0;
}


/*!

 	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
*/
Queue::~Queue()
{
  delete [] Q;
}

/*!
 	 Sprawdza czy aby Kolejka nie jest pusta, brak elementów.
 	 Zwraca 1 jesli coś jest, lub 0 jesli jest pusta.
*/
bool Queue::empty(void)
{
  return !qcnt;
}

/*!

		Metoda która informuje nas jaki element znajduje się na samym początku Kolejki. Zwraca jego wartosc.
 */
int Queue::front(void)
{
  if(qcnt) return Q[qptr];
  return -MAXINT;
}

/*!
 
	 Metoda dodaje nowy element na końcu Kolejki, zawartość informacji tego elementu przesyłąny jest w parametrze v.
*/
void Queue::push(int v)
{
  int i;
  if(qcnt < n)
  {
    i = qptr + qcnt++;
    if(i >= n) i -= n;
    Q[i] = v;
  }
  else
  {
	  //(*this).zwieksz_tablice_o_jeden();
	  (*this).zwieksz_tablice_dwarazy();
	    i = qptr + qcnt++;
	    if(i >= n) i -= n;
	    Q[i] = v;
  }
}

/*!

  			Metoda zdejmuje element z początku Kolejki.
 */
void Queue::pop(void)
{
  if(qcnt)
  {
    qcnt--;
    qptr++;
    if(qptr == n) qptr = 0;
  }
}

/*!
 
		Metoda zwiększa rozmiar tablicy dynamicznej o jeden element.
 */
void Queue::zwieksz_tablice_o_jeden()
{
	int *tab2 = new int [++n];			// nowa tablica o rozmiarze o jeden wiekszym
	
	for(int i=0;i<n-1;i++)
	{
		tab2[i] = Q[i];				// skopjuj wszystkie dane ze starej tablicy
	}
	delete[] Q;						// zniszcz stara tablice
	Q = tab2;						// umiesć nową tablice pod wskaznik S
}

/*!

		Metoda zwiększa rozmiar tablicy dynamicznej do dwu-krotności istniejącej tablicy dynamicznej.
 */
void Queue::zwieksz_tablice_dwarazy()
{
	int nowy_rozmiar = 2*n;
	int *tab2 = new int [nowy_rozmiar];  // nowa tablica o rozmiarze dwukrotnie wiekszym
	
	for(int i=0;i<n;i++)
	{
		tab2[i] = Q[i];			// skopjuj wszystkie dane ze starej tablicy
	}
	n = nowy_rozmiar;
	delete[] Q;				// zniszcz stara tablice
	Q = tab2;				// umiesć nową tablice pod wskaznik S
}
