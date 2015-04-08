/*
 * mylist.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: serek8
 */


#include "mylist.h"

MyList::MyList()
{
	firstElement = lastElement = new MyListElement(0);
	sizeOfList = 0;
}


void MyList :: push_back(int arg)
{
	MyListElement *newMyListElement = new MyListElement(arg);
	if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
	//newMyListElement -> nextElement = 0;
	newMyListElement -> previousElement = this -> lastElement;
	this -> lastElement -> nextElement = newMyListElement;
	this->lastElement = newMyListElement;
}
void MyList :: push_front(int arg)
{
	MyListElement *newMyListElement = new MyListElement(arg);
	if(!sizeOfList++) {firstElement = lastElement = newMyListElement;}
	//newMyListElement -> previousElement =  0;
	newMyListElement -> nextElement = this -> firstElement;
	this -> firstElement -> previousElement = newMyListElement;
	this->firstElement = newMyListElement;
}

int MyList :: pop_back()
{
	if(!(sizeOfList--)) { sizeOfList=0; return 0; }
	int tmpNumber = this -> lastElement -> number;
	MyListElement *originMyListElement = this -> lastElement;
	this -> lastElement = this -> lastElement -> previousElement;
	delete originMyListElement;
	return tmpNumber;
}
int MyList :: pop_front()
{
	if(!(sizeOfList--)) { sizeOfList=0; return 0; }
	int tmpNumber = this -> firstElement -> number;
	MyListElement *originMyListElement = this -> firstElement;
	this -> firstElement = this -> firstElement -> nextElement;

	delete originMyListElement;
	return tmpNumber;
}

MyList :: MyListElement :: MyListElement(int arg)
{
	this -> number = arg;
	this -> nextElement =0;
	this -> previousElement =0;
}

int MyList::size()
{
	return sizeOfList;
}

void MyList::wyswietl_liste()
{
   for(int i=0 ;i<sizeOfList; i++)
       cout << ((*this)[i]).number <<' ';

}

void MyList::zamien(MyListElement *pierwszy, MyListElement *drugi)
{
    int tmp=0;
    tmp = (*pierwszy).number;
    (*pierwszy).number = (*drugi).number;
    (*drugi).number = tmp;
}

void MyList::quicksort(int lewy, int prawy)
{
    int v= ((*this)[(lewy+prawy)/2]).number;
    int i,j;
    i=lewy;
    j=prawy;

    do
    {
        while(((*this)[i]).number<v) i++;
        while(((*this)[j]).number>v) j--;
                if(i<=j)
                {
                    (*this).zamien(&(*this)[i],&(*this)[j]);
                    i++;
                    j--;
                }
    }
    while(i<=j);
    if(j>lewy) this->quicksort(lewy, j);
    if(i<prawy) this->quicksort(i, prawy);

}

