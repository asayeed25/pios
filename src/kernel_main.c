//#include <stdio.h>
#include "list.h"
#include "serial.h"
#include "rprintf.h"
#include "page.h"
extern int __bss_start;
extern int __bss_end;
void __bss_zero();
extern struct ppage* free_list;

int global;
#define NULL (void*)0

//MAIN
void kernel_main() {
    init_pfa_list();
    struct ppage* test = free_list;
    test = test->next;
    esp_printf(putc, "Physical Address: %x\n", test->physical_addr);
    test = allocate_physical_pages(2);
    esp_printf(putc, "Physical Pages --> %x \n", test);
    esp_printf(putc, "Physical Pages --> %x \n", test->physical_addr);
    free_physical_pages(test);
    test = free_list->next;
    esp_printf(putc, "After Pages are Freed: %x \n", test->physical_addr);
    
	while (1) {
    }
}


// Homework 1 - Clearing BSS
// Function to clear bss
void __bss_zero() {
	(&__bss_start)[0] = 0x0d;
	int i = 0;
	while ((&__bss_start) + i != &__bss_end) {
		(&__bss_start)[i] = 0;
		i++;
	}
}

// In Class Activity - Timer
/*unsigned long get_timer_count(){
	unsigned long *timer_count_register = 0x3f003004;
	return *timer_count_register;
}
*/

// Homework 4 - LED Blinky 
// Worked with Haris after class 

unsigned int *gpset1 = 0xFE200020;
unsigned int *gpclr1 = 0xFE20002C;
unsigned int *gpfsel4 = 0xFE200010;

//Configure the GPIO42 pin to act as an output
void led_init(){
	unsigned int mask_number = 0xFFFFFE3F; 
	*gpfsel4 = *gpfsel4 & mask_number; 
	*gpfsel4 = *gpfsel4 | (1 << 6);
	return;
}

//Turns the LED on 
void led_on(){
	*gpset1 = (1 << 10);
}

//Turns the LED off
void led_off(){
	*gpclr1 = (1 << 10);

}

void delay(){
    unsigned int i = 0;
    for (i; i < 100000; i++){
        asm("NOP");
    }
}

