#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "stack.hh"

using namespace std;

bool Stack::empty()
{
	return !S;
}

Element* Stack::top(void)
{
	return S;
}

void Stack::push(int v)
{
	Element* e = new Element;
	e->info = v;
	e->next = S;
	S = e;
}

void Stack::pop(void)
{
	if(S)
	{
		Element* e = S;
		S = S->next;
		delete e;
	}
}
