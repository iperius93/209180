
/*
 * multiplybytwo.h
 *
 *  Created on: Mar 6, 2015
 *      Author: serek8
 */
/** @file */
#ifndef MULTIPLYBYTWO_H_
#define MULTIPLYBYTWO_H_

#include "mybenchmark.h"
#include "dataframe.h"


/**
 * @brief Algorytm mnozy kazda liczbe razy 2
 *
 * Algorytm mnozy kazda kolejna liczbe przez 2
 */
class MultiplyByTwo : public  MyBenchmark
{
public:
	/**
	 * @brief Wykonuje algorytm mnozenie x2
	 *
	 */
	void executeAlgorithm();

	~MultiplyByTwo(){}



	using DataFrame::operator=;

};

#endif /* MULTIPLYBYTWO_H_ */
