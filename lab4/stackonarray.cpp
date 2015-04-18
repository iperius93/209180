
/*
 * stackonarray.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#include "stackonarray.h"


StackOnArray::StackOnArray()
{
	sizeOfTable =1;
	index=0;
	tableOfData = new int[1];
}


void StackOnArray::pushByOneAlloc(int arg)
{
	if(index==0){
		tableOfData[0] = arg;
		++index; // teraz index = 1
		return;
	}
	if(index==sizeOfTable)
	{
		int *tmpTableOfData = new int[index+1];	//index pokazuje zawsze na nastepny element ktory jest jeszcze pusty
		for(int i =0 ; i<index; i++)
		{
			tmpTableOfData[i] = tableOfData[i];
		}
		delete[] tableOfData;
		tableOfData = tmpTableOfData;
	}
	tableOfData[index] = arg;
	sizeOfTable = ++index ;
	//Po zakonczeniu tej funkcji index i sizeOfTable musza byc sobie rowne
}

void StackOnArray::pushByDoubleAlloc(int arg)
{
	if(index==0){
		tableOfData[0] = arg;
		++index;
		return;
	}

	if(sizeOfTable==index)
	{

		int *tmpTableOfData = new int[2*index];
		sizeOfTable = 2*index;
		for(int i =0 ; i<index; i++)
		{
			tmpTableOfData[i] = tableOfData[i];
		}
		delete[] tableOfData;
		tableOfData = tmpTableOfData;
	}
	tableOfData[index++] = arg; // powiekszam index po przypisaniu nowej wartosci
}

int StackOnArray::pop()
{
	return tableOfData[--index];
}

StackOnArray:: ~StackOnArray()
{
delete [] 	tableOfData;
}

int StackOnArray::returnIndex()
{
    return index;
}

void StackOnArray::quicksort(int lewy, int prawy)
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

void StackOnArray::wyswietl_stos()
{
    for(int i=0;i<index;i++)
    {
        cout<<this->tableOfData[i]<<' ';
        if(i%10 == 0 && i != 0) cout << endl;
    }
}
