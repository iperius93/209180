#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "queue.hh"


using namespace std;

bool Queue::empty()
{
	return !head;
}
	
int Queue::front()
{
	if(head) return head->info;
	else
	{
		cerr << "Kolejka jest pusta."<<endl;
		return -2147321;
	}
}
	
void Queue::push(int v)
{
	Element *p = new Element;
	p->next = NULL;
	p->info = v;
	if(tail) tail->next = p;
	else head = p;
	tail = p;
}
	
void Queue::pop()
{
	if(head)
	{
		Element *p = head;
		head = head->next;
		if(!head) tail = NULL;
		delete p;
	}
}
