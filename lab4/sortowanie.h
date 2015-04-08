/*
 * stackonarray.h
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

#ifndef SORTOWANIE_H_
#define SORTOWANIE_H_
class Pair
    {
        int l, r;

        public:
        Pair(int l, int r)
        {
            this.l = l;
            this.r = r;
        }
    }

void quicksort_stack(MyStack *Stack);

int wyciągnij_srodkowy(MyStack *Stack);

#endif /* SORTOWANIE_H_ */
