#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "queueonarray.h"

#define MAXINT 24586332

/*!
 *   \file
 *   \brief Definicja metod klasy Queue
*/

using namespace std;

/*!

  	 * Tworzy nową kolejke, tworzy dynamiczna tablice danych o rozmiarze podanym w parametrze.
 */
QueueOnArray::QueueOnArray()
{
  n = 1;
  tableOfData = new int[1];
  qptr = qcnt = 0;
}


/*!

 	 * Niszczy dynamiczną tablicę danych, zwalnia pamięć.
*/
QueueOnArray::~QueueOnArray()
{
  delete [] tableOfData;
}

/*!
 	 Sprawdza czy aby Kolejka nie jest pusta, brak elementów.
 	 Zwraca 1 jesli coś jest, lub 0 jesli jest pusta.
*/
bool QueueOnArray::empty(void)
{
  return !qcnt;
}

/*!

		Metoda która informuje nas jaki element znajduje się na samym początku Kolejki. Zwraca jego wartosc.
 */
int QueueOnArray::front(void)
{
  if(qcnt) return tableOfData[qptr];
  return -MAXINT;
}

/*!

	 Metoda dodaje nowy element na końcu Kolejki, zawartość informacji tego elementu przesyłąny jest w parametrze v.
*/
void QueueOnArray::push(int v)
{
  int i;
  if(qcnt < n)
  {
    i = qptr + qcnt++;
    if(i >= n) i -= n;
    tableOfData[i] = v;
  }
  else
  {
	  //(*this).zwieksz_tablice_o_jeden();
	  (*this).zwieksz_tablice_dwarazy();
	    i = qptr + qcnt++;
	    if(i >= n) i -= n;
	    tableOfData[i] = v;
  }
}

/*!

  			Metoda zdejmuje element z początku Kolejki.
 */
void QueueOnArray::pop(void)
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
void QueueOnArray::zwieksz_tablice_o_jeden()
{
	int *tab2 = new int [++n];			// nowa tablica o rozmiarze o jeden wiekszym

	for(int i=0;i<n-1;i++)
	{
		tab2[i] = tableOfData[i];				// skopjuj wszystkie dane ze starej tablicy
	}
	delete[] tableOfData;						// zniszcz stara tablice
	tableOfData = tab2;						// umiesć nową tablice pod wskaznik S
}

/*!

		Metoda zwiększa rozmiar tablicy dynamicznej do dwu-krotności istniejącej tablicy dynamicznej.
 */
void QueueOnArray::zwieksz_tablice_dwarazy()
{
	int nowy_rozmiar = 2*n;
	int *tab2 = new int [nowy_rozmiar];  // nowa tablica o rozmiarze dwukrotnie wiekszym

	for(int i=0;i<n;i++)
	{
		tab2[i] = tableOfData[i];			// skopjuj wszystkie dane ze starej tablicy
	}
	n = nowy_rozmiar;
	delete[] tableOfData;				// zniszcz stara tablice
	tableOfData = tab2;				// umiesć nową tablice pod wskaznik S
}

void QueueOnArray::quicksort(int lewy, int prawy)
{
    int v= this->tableOfData[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;

    do
    {
        while(this->tableOfData[i]<v) i++;
        while(this->tableOfData[j]>v) j--;
                if(i<=j)
                {
                    x=this->tableOfData[i];
                    this->tableOfData[i]=this->tableOfData[j];
                    this->tableOfData[j]=x;
                    i++;
                    j--;
                }
    }
    while(i<=j);
    if(j>lewy) this->quicksort(lewy, j);
    if(i<prawy) this->quicksort(i, prawy);

}

int QueueOnArray::returnQPTR()
{
    return qptr;
}

int QueueOnArray::returnQCNT()
{
    return qcnt;
}

void QueueOnArray::wyswietl_kolejke()
{
    for(int i=qptr;i<qcnt;i++)
    {
        cout<<this->tableOfData[i]<<' ';
        if(i%10 == 0 && i != 0) cout << endl;
    }
}
