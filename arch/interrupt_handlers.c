#include "../include/interrupt_handlers.h"
#include "../include/display.h"

void exc_divide_by_zero() {
    kprintf("Interrupt: divide by zero - need to notify process");
    while(1);
}


void exc_page_fault() {
    kprintf("Interrupt: page fault - see intel docs");
    while(1);
}