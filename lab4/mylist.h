/*
 * mylist.h
 *
 *  Created on: Mar 12, 2015
 *      Author: serek8
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include <iostream>

using namespace std;

/**
 * @brief Lista dwukierunkowa
 *
 * Klasa przedstawia liste dwukierunkową dynamiczna
 */
class MyList{

private:
	/// liczba elementow listy
	int sizeOfList;

	/// @brief Klasa 'malych struktur' gdzie jest numer i wskaznik do nas elementu
	class MyListElement {
	public:
		///  Liczba przechowywana
		int  number;

		/**
		 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
		 * @param arg liczba do zapisania w kolejnym elemencie listy
		 */
		MyListElement(int arg);

		///  wskaznik do nastepnej 'malej struktury' w liscie
		MyListElement *nextElement;
		///  wskaznik do poprzedniej 'malej struktury' w liscie
		MyListElement *previousElement;
	};

	///  wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	MyListElement *firstElement;
	///  wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	MyListElement *lastElement;
	///  Konstruktor listy
public:
	MyList();

	/**
	 * @brief Zwraca ilosc elementow listy
	 * @return ilosc elementow tablicy
	 */
	int size();
	/**
	 * @brief Zwraca element ostatni w liscie
	 * @return Zwraca element ostatni w liscie
	 */
	int pop_back();
	/**
	 * @brief Zwraca element pierwszy w liscie
	 * @return Zwraca element pierwszy w liscie
	 */
	int pop_front();
	/**
	 * @brief Wklada element na ostatnie miejsce na liscie
	 */
	void push_back(int arg);
	/**
	 * @brief Wklada element na pierwsze miejsce na liscie
	 */
	void push_front(int arg);
	/**
	 * @brief Zamienia wartości dwóch elementów listy jednokierunkowej.
	 */
	void zamien(MyListElement *pierwszy, MyListElement *drugi);
	/**
	 * @brief Przeciążenie operatora [] za pomocą którego mamy dostep posredni do elementow listy.
	 * @return Zwraca referencje na element listy jednokierunkowej.
	 */
    MyListElement& operator[] (int iter)
    {
        if(iter==0) return *firstElement;
        if(iter == (sizeOfList-1)) return *lastElement;
        MyListElement *tmp = firstElement;
        for(int i=1;i<iter-1;i++) tmp=tmp->nextElement;
        return *tmp;
    }

	/**
	 * @brief Wykonanie sortowania na liscie, sortowanie szybkie listy jedokierunkowej.
	 */
	void quicksort(int lewy, int prawy);

    /**
    * @brief Metoda wyswietla wszystkie elementy listy jedokierunkowej.
    */
    void wyswietl_liste();
};


#endif /* MYLIST_H_ */

