#include "include/string.h"
#include "main.h"
#include "include/x86/gdt.h"
#include "include/x86/idt.h"
#include "include/display.h"
#include "include/malloc.h"
#include <stdint.h>

#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07

void* stack_ptr;

void main() {
    clear_screen();

    const char *welcome = 
"  ____   _____                         \n"
" / __ \\ / ____|                        \n"
"| |  | | (___  _ __ ___   ___ _ __ ___ \n"
"| |  | |\\___ \\| '_ ` _ \\ / _ \\ '__/ __|\n"
"| |__| |____) | | | | | |  __/ |  \\__ \\\n"
" \\____/|_____/|_| |_| |_|\\___|_|  |___/\n"
"                                                         \n";

    kprintf(welcome);
    kprintf("Initiating GDT ...\n");
    gdt_init();
    kprintf("Initiating IDT ...\n");
    init_idt();
    kprintf("Initiating Memory ...\n");
    init_memory();
    char* mem = allocate(4);
    char* x = allocate(8);
    char* y = allocate(8);

    //kprintf("%d\n",((FreeBlock*) (mem-sizeof(FreeBlock)))->size);
    //kprintf("x heap: %x | x stack: %x\n", x, &x);
    //kprintf("y heap: %x | y stack: %x\n", y, &y);
    //kprintf("x: %x\n", &x[0]);
    //kprintf("\nmem: %x",&mem[20]);
    kprintf("mem loc: %x\n", mem);
    kprintf("%d",  __STDC_VERSION__);
}
// 1055657
// 1055664