/*
 * numbergenerator.h
 *
 *  Created on: Mar 11, 2015
 *      Author: serek8
 */
/** @file */
#ifndef NUMBERGENERATOR_H_
#define NUMBERGENERATOR_H_

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "dataframe.h"

/**
 * @brief Klasa generujaca losowe liczby
 *
 * Klasa generujaca losowe liczby na podstawie czasu maszyny na ktorym jest uruchomiona
 * Wszystkie funkcje zapisu pliku dziedziczy z klasy DataFrame
 *
 */
class NumberGenerator : public DataFrame
{
public:
/**
 * @brief Generuje losowe liczby
 *
 * Generuje losowe liczby na podstawie czasu maszyny
 */
void generateNumbers()
{
	time_t randomTime = clock();
	this->tableOfData = new int[sizeOfTable];
	for(unsigned int i=0; i<sizeOfTable ; i++)
	{
		srand (randomTime = clock());
		this->tableOfData[i] = rand()%100;
		randomTime = clock();
	}
}

using DataFrame::operator=;
 ~NumberGenerator() {}
};

#endif /* NUMBERGENERATOR_H_ */

