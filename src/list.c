//Linked List with functions to add and remove elements from the list

//Source: Linked List Homework https://github.com/neilklingensmith/linkedlisthomework
//Collaborated with Haris Q. and w/ help from Jack

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Adding new elements to the list
void listAdd(struct listElement* head, struct listElement* ele)
{
	struct listElement* prev; 
	struct listElement* temp = head;
	while (temp->next) {
		prev = temp;
		temp = temp->next;
	}
	temp->prev = prev;
	temp->next = ele;
}

//Removing an element from the list
void listRemove(struct listElement** head, int data)
{
	struct listElement* listHead = *head;
	if (head == NULL) {
		return;
	}
	if (listHead->data == data) {
		*head = listHead->next;
		return;
	}
	while (listHead->next) {
		if (data == listHead->next->data) {
			listHead->next = listHead->next->next;
			break;
		}
		listHead = listHead->next;
	}
}

int main()
{
	//Creating a list head pointer
	struct listElement* listHead = NULL;
}
