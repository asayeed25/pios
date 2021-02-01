//Define data structure for elements in linked List

struct listElement {
	struct listElement* next;
	struct listElement* prev;
	int data;
};

void listAdd(struct listElement* head, struct listElement* ele);
void listRemove(struct listElement** head, int data);
