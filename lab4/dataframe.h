/*
 * dataframe.h
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#ifndef DATAFRAME_H_
#define DATAFRAME_H_

#include <fstream>



class DataFrame
{
public:
	/**
	 * @brief Zawiera adres do tablicy {size} elementów
	 */
	int *tableOfData;
	/**
	 * @brief Zawiera nazwe pliku do zapisu
	 */
	char *outputFileName;
	/**
	 * @brief Zawiera nazwe pliku do odczytu
	 */
	char *inputFileName;
	/**
	 * @brief Rozmiar tablicy tableOfData
	 *
	 */
	unsigned int sizeOfTable;

	/**
	 * @brief Przypisuje zmiennym wartosci domyslne
	 */
	DataFrame();
	/**
	 * @brief Ładuje dane z pliku
	 *
	 * Wczytuje dane z pliku i zapisuje je dynamicznie do tablicy
	 * jednowymiarowej, na ktora wskazuje wskaźnik *tableOfData
	 *
	 * Rozmiar tablicy jest przechowywany w sizeOfTable
	 *
	 */
	int loadDataFromFile();

	/**
	 * @brief Zapisuje dane do pliku
	 *
	 * Wczytuje liczby z pliku o nazwie intputFileName
	 */
	int saveDataToFile();

	/**
	 * @brief Kopiuje elementy roznych obiektow
	 *
	 * Zapisuje kolejne liczby do pliku o nazwie outputFileName
	 */
	DataFrame operator= (DataFrame dataframe);
	virtual ~DataFrame() {}


};



#endif /* DATAFRAME_H_ */

