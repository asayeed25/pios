// Function that writes zeros to the bss segment of the kernel

#include <stdio.h>
#include "list.h"

extern int __bss_start;
extern int __bss_end;

// Collaborated with Haris Q. and w/ help from Jack
void __bss_zero();
int global;

struct listElement b = { NULL,NULL, 1 };
struct listElement a = { NULL,NULL, 7 };
struct listElement c = { NULL,NULL, 3 };
struct listElement* head = &a;
struct listElement* list = &a;

void kernel_main() {
	__bss_zero();
	listAdd(list, &b);
	listAdd(list, &c);
	listRemove(head, 1); 
	while (1) {
	}
}

// Function to clear bss
// Worked with Jack in Lab-Thursday to check if working
void __bss_zero() {
	(&__bss_start)[0] = 0x0d;
	int i = 0;
	while ((&__bss_start) + i != &__bss_end) {
		(&__bss_start)[i] = 0;
		i++;
	}
}
