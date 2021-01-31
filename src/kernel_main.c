// function to clear bss
// source: Lab 1/28/21

#include <stdio.h>

extern long __bss_start;
extern long __bss_end;

void kernel_main() {
    __bss_zero();
    while(1){
    }
}
void __bss_zero(){
    char *begin_bss = &__bss_start;
    char *end_bss = &__bss_end;

//to check if code is functioning as intended
    begin_bss[0] = 0x0d;
    
    int i =0;
    while(&begin_bss[i] != &end_bss){
        begin_bss[i] = 0;
        i++;
    }
}
