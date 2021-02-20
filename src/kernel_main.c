#include <stdio.h>
#include "list.h"

extern int __bss_start;
extern int __bss_end;

void __bss_zero();

int global;

struct listElement b = { NULL,NULL, 1 };
struct listElement a = { NULL,NULL, 7 };
struct listElement c = { NULL,NULL, 3 };
struct listElement* head = &a;
struct listElement* list = &a;

void led_init();
void led_on();
void delay();
void led_off();


//MAIN
void kernel_main() {
  /*
    __bss_zero();
	get_timer_count();
	listAdd(list, &b);
	listAdd(list, &c);
	listRemove(head, 1); 
  */  
    led_init();
	while (1) {
        led_on();
        delay();
        led_off();
        delay();
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
unsigned long get_timer_count(){
	unsigned long *timer_count_register = 0x3f003004;
	return *timer_count_register;
}

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

