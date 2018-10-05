#include "SLList.h"
#include <iostream>

SLList::~SLList() 
{ 
	for (SLLNode *p; !is_empty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void SLList::add_to_head(int a) 
{ 
	head = new SLLNode(a, head);
	if (tail == 0) 
		tail = head;
}

void SLList::add_to_tail(int a) 
{ 
	if (tail != 0) {
		tail->next = new SLLNode(a);
		tail = tail->next;
	}
	else
		head = tail = new SLLNode(a);
}

int SLList::delete_from_head() 
{ 
	int a = head->info;
	SLLNode *tmp = head;
	if (head == tail)
		head = tail = 0;
	else
		head = head->next;
	delete tmp;
	return a;
}

int SLList::delete_from_tail() 
{ 
	int a = tail->info;
	if (head == tail) {
		delete head;
		head = tail = 0;
	}
	else {
		SLLNode *p;
		for (p = head; p->next != tail; p = p->next);
		delete tail;
		tail = p;
		tail->next = 0;
	}
	return a;
}

void SLList::delete_node(int a) 
{ 
	if (head != 0) {
		if (head == tail && a == head->info) {
			delete head;
			head = tail = 0;
		}
		else if (a == head->info) {
			SLLNode *p = head;
			head = head->next;
			delete p;
		}
		else {
			SLLNode *pred, *p;
			for (pred = head, p = head->next; 
				p != 0 && !(p->info == a);
				pred = pred->next, p = p->next);
			if (p != 0) {
				pred->next = p->next;
				if (p == tail)
					tail = pred;
				delete p;
			}
		}
	}
}

bool SLList::is_in_list(int a) 
{ 
	SLLNode *p;
	for (p = head; p != 0 && !(p->info == a); p = p->next);
	return p != 0;
}

void SLList::print_list()
{
	for (SLLNode* p = head; p != 0; p = p->next) 
		std::cout << p->info << " ";
	std::cout << std::endl;
}
