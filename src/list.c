//Linked List with functions to add and remove elements from the list

#include <stddef.h>
#include "list.h"

//Adding new elements to the list
void listAdd(struct listElement **head, struct listElement *newElement){
	struct listElement *iterator = (struct listElement*)head;
	
	//link element b into the list between iterator and iterator->next
	newElement->next = iterator->next;
	newElement->prev = iterator;
	
	iterator->next = newElement;
	
	if(newElement->next != NULL){
		newElement->next->prev = newElement;
	}
}
	


//Removing an element from the list
void listRemove(struct listElement *b){
	
	if(b->next != NULL)
		b->next->prev = b->prev;
		
	b->prev->next = b->prev;
	
	//NULLify the element's next and prev pointers to indicate
	//that it is not linked into a list
	b->next = NULL;
	b->prev = NULL;
}	
	

