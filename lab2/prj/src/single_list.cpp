#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "single_list.hh"

using namespace std;

int Single_List::size()
{
	return counter;
}
	
Element* Single_List::push_front(Element * p)
{
	p->next = front;
	front = p;
	if(!back) back = front;
	counter++;
	return front;
}
	
Element* Single_List::push_back(Element *p)
{
	if(back) back->next = p;
	p->next = NULL;
	back = p;
	if(!front) front = back;
	counter++;
	return back;
}
	
Element* Single_List::pop_front()
{
	Element *p;
		
	if(front)
	{
		p = front;
		front = front->next;
		if(!front) back = NULL;
		counter--;
		return p;
	}
	else return NULL;
}
	
Element* Single_List::pop_back()
{
	Element* p;
	if(back)
	{
		p = back;
		if(p == front) front = back = NULL;
		else
		{
			back = front;
			while(back->next != p) back = back->next;
			back->next = NULL;
		}
		counter--;
		return p;
	}
	else return NULL;
}
	
void Single_List::showInfo()
{
	Element *p;
	if(!front) cout << "Lista jest pusta." << endl;
	else
	{
		p = front;
		while(p)
		{
			cout << p->info<< " ";
			p = p->next;
		}
		cout << endl;
	}
}
