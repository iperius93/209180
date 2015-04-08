/*
 * mystack.h
 *
 *  Created on: Mar 16, 2015
 *      Author: serek8
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include "mylist.h"

/**
 * @brief Klasa reprezentuje stos
 *
 * Stos, którego index po pushu pokazuje na miejsce nastepne(nastepne za tym elementem)
 */
class MyStack : public MyList
{
public:
	/*
	 * @brief Dodaje element do kolejki
	 * @param arg Liczba dodawana do stosu
	 */
	void push(int arg) {
		push_back(arg);
	}
	/// @brief Wyciaga element ze stosu
	int pop() {
		return pop_back();
	}
};

#endif /* MYSTACK_H_ */
