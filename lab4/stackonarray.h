/*
 * stackonarray.h
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#ifndef STACKONARRAY_H_
#define STACKONARRAY_H_

#include <iostream>

using namespace std;

/**
 * Klasa przedstawia stos stworzony na tablicy dynamicznej.
 * Powiekszanie tablicy przeprowadza sie albo o jeden element albo o polowe dotychczasowego rozmiatu
 *
 */
class StackOnArray
{
public:
	/// rozmiar tablicy
	int sizeOfTable;
	/// index zawsze pokazuje na pozycje poprzedzającą ostatni dodany element
	int index;
	/// wskaznik do tablicy w ktorej przechowuje liczby
	int *tableOfData;

public:
/**
 * Konstruktor tablicy
 */
	StackOnArray();
	/**
	 * @brief Dodaje do stosu kolejny element
	 *
	 * Gdy brakuje w tablicy stosu miejsca alokuje nową większą o jeden i kopiuje tam dane
	 */
	void pushByOneAlloc(int arg);

	/**
	 *  @brief Dodaje do stosu kolejny element
	 * Gdy brakuje w tablicy stosu miejsca alokuje nową większą o 2 razy i kopiuje tam dane
	 */
	void pushByDoubleAlloc(int arg);
	/**
	 *  @brief Pobiera jeden element ze stosu
	 */
	int pop();
	/**
	 *  @brief Konstruktor klasy StackOnArray, stos z jednym elementem.
	 */
	~StackOnArray();
	/**
	 *  @brief Zwraca wartosc pola Index w klasie StackOnArray.
	 */
    int returnIndex();
	/**
	 *  @brief Wykonuje sortowanie szybkie na stosie.
	 */
	void quicksort(int left, int right);
	/**
	 *  @brief Wyswietla wszystkie elementy stosu.
	 */
	void wyswietl_stos();

};


#endif /* STACKONARRAY_H_ */

