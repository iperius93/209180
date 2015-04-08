/*
 * dataframe.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: serek8
 */

/** @file */

#include "dataframe.h"

DataFrame::DataFrame()
{
	tableOfData = 0;
	outputFileName = NULL;
	inputFileName = NULL;
	sizeOfTable = 0;
}

int DataFrame :: loadDataFromFile()
{
	std::ifstream streamToFile;
	streamToFile.open (inputFileName, std::ifstream::in);
	this->tableOfData = new int[sizeOfTable];
	for(unsigned int i=0; i<sizeOfTable ; i++) {
		streamToFile >> this-> tableOfData[i];
		if (streamToFile.eof())	return 1; //[EoF reached]
	}
	return 0;
}

int DataFrame :: saveDataToFile()
{
	std::ofstream streamToFile;
	streamToFile.open (outputFileName, std::ofstream::out);
	for(unsigned int i=0; i<sizeOfTable ; i++) {
		streamToFile << this-> tableOfData[i] <<' ';
	}
	return 0;
}



DataFrame DataFrame :: operator= (DataFrame dataframe)
{
	this->tableOfData = dataframe.tableOfData;
	this->outputFileName = dataframe.outputFileName;
	this->inputFileName = dataframe.inputFileName;
	this->sizeOfTable = dataframe.sizeOfTable;
	return *this;
}

