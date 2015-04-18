/*
 * mybenchmark.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */

#include "mybenchmark.h"


double MyBenchmark::testAlgorithm(unsigned int repetition)
{
	time_t benchmarkTimeInTotal = 0;
	time_t benchmarkTimeForOneLoop = 0;

	int *originalTableOfData = new int[sizeOfTable];
	for(unsigned int i=0; i<sizeOfTable; i++)
		originalTableOfData[i]=tableOfData[i];

	for(unsigned int i=0 ; i<repetition ; i++)	{
		for(unsigned int i=0; i<sizeOfTable; i++)
			tableOfData[i]=originalTableOfData[i];

		benchmarkTimeForOneLoop = clock();
			this->executeAlgorithm();
		benchmarkTimeInTotal += clock() - benchmarkTimeForOneLoop;
	}


	return (( (double)benchmarkTimeInTotal ) /CLOCKS_PER_SEC);
}

double MyBenchmark::timerValue=0;
void MyBenchmark :: timerStart()
{
	MyBenchmark::timerValue = (( (double)clock() ) /CLOCKS_PER_SEC);
}

double MyBenchmark :: timerStop()
{
	return (( (double)clock() ) /CLOCKS_PER_SEC) - MyBenchmark::timerValue;
}

