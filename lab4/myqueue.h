/*
 * myqueue.h
 *
 *  Created on: Mar 16, 2015
 *      Author: serek8
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include "mylist.h"

/**
 * @brief Klasa reprezentuje kolejke
 *
 */
class MyQueue : public MyList
{
public:
	/*
	 * @brief Dodaje element do kolejki
	 * @param arg Liczba dodawana do kolejki
	 */
	void push(int arg) {
		push_back(arg);
	}
	/// @brief Wyciaga element z kolejki
	int pop() {
		return pop_front();
	}
};

#endif /* MYQUEUE_H_ */

