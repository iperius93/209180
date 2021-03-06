#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "single_list.hh"

/*!
* \file
* \brief Definicja metod klasy Single_List
* 
*/
using namespace std;

/*!
 * 
 	 * Tworzy nową liste, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
*/
Single_List::Single_List(int x)
{
  n = x;
  L = new int[x];
  front_ptr = back_ptr = qcnt = 0;
}

/*!

 	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
*/
Single_List::~Single_List()
{
  delete [] L;
}

/*!
	Sprawdza czy aby Lista nie jest pusta, brak elementów.
 	 Zwraca 1 jesli coś jest, lub 0 jesli jest pusta.
*/
bool Single_List::empty(void)
{
  return !qcnt;
}
/*!

	 Metoda dodaje nowy element na początku Listy, zawartość informacji tego elementu przesyłąny jest w parametrze v.
*/
void Single_List::push_front(int v)
{

}
/*!

	 Metoda dodaje nowy element na końcu Listy, zawartość informacji tego elementu przesyłąny jest w parametrze v.
*/
void Single_List::push_back(int v)
{
	  int i;
	  if(qcnt < n)
	  {
	    i = back_ptr + qcnt++;
	    if(i >= n) i -= n;
	    L[i] = v;
	  }
	  else
	  {
		  (*this).zwieksz_tablice_o_jeden();
		  //(*this).zwieksz_tablice_dwarazy();
		    i = back_ptr + qcnt++;
		    if(i >= n) i -= n;
		    L[i] = v;
	  }
}
	
/*!

			Metoda zdejmuje element z początku Listy.
	 */
void Single_List::pop_front()
{
	  if(qcnt)
	  {
	    qcnt--;
	    front_ptr++;
	    if(front_ptr == n) front_ptr = 0;
	  }
}

/*!

		Metoda zdejmuje element z końca Listy.
 */
void Single_List::pop_back()
{
	  if(qcnt)
	  {
	    qcnt--;
	    back_ptr--;
	    if(back_ptr == n) back_ptr = 0;
	  }
}

/*!

		Metoda która informuje nas jaki element znajduje się na samym początku Listy. Zwraca jego wartosc.
 */
int Single_List::front(void)
{
  if(qcnt) return L[front_ptr];
  return -MAXINT;
}
/*!

		Metoda która informuje nas jaki element znajduje się na samym końcu Listy. Zwraca jego wartosc.
 */
int Single_List::back(void)
{
  if(qcnt) return L[back_ptr];
  return -MAXINT;
}

/*!

		Metoda zwiększa rozmiar tablicy dynamicznej o jeden element.
 */
void Single_List::zwieksz_tablice_o_jeden()
{
	int *tab2 = new int [++n];			// nowa tablica o rozmiarze o jeden wiekszym
	
	for(int i=0;i<n-1;i++)
	{
		tab2[i] = L[i];				// skopjuj wszystkie dane ze starej tablicy
	}	
	delete[] L;						// zniszcz stara tablice
	L = tab2;						// umiesć nową tablice pod wskaznik S
}

/*!
 
		Metoda zwiększa rozmiar tablicy dynamicznej do dwu-krotności istniejącej tablicy dynamicznej.
 */
void Single_List::zwieksz_tablice_dwarazy()
{
	int nowy_rozmiar = 2*n;
	int *tab2 = new int [nowy_rozmiar];		// nowa tablica o rozmiarze dwukrotnie wiekszym
	
	for(int i=0;i<n;i++)
	{
		tab2[i] = L[i];				// skopjuj wszystkie dane ze starej tablicy
	}
	n = nowy_rozmiar;
	delete[] L;					// zniszcz stara tablice
	L = tab2;					// umiesć nową tablice pod wskaznik S
}
