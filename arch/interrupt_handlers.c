#include "../include/interrupt_handlers.h"
#include "../include/display.h"

void exc_divide_by_zero() {
    kprintf("Interrupt: divide by zero - need to notify process");
    while(1);

}