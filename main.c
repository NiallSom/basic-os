#include "include/string.h"
#include "main.h"
#include "include/x86/gdt.h"
#include "include/x86/idt.h"
#include "include/display.h"
#include "include/first_fit.h"
#include <stdint.h>

#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07




void main() {
    clear_screen();

    const char *welcome = 
"  ____   _____                         \n"
" / __ \\ / ____|                        \n"
"| |  | | (___  _ __ ___   ___ _ __ ___ \n"
"| |  | |\\___ \\| '_ ` _ \\ / _ \\ '__/ __|\n"
"| |__| |____) | | | | | |  __/ |  \\__ \\\n"
" \\____/|_____/|_| |_| |_|\\___|_|  |___/\n"
"                                                         \n"
"                                                         \n";

    //kprintf(welcome);
    kprintf("Initiating GDT ...\n");
    gdt_init();
    kprintf("Initiating IDT ...\n");
    init_idt();
    kprintf("Initiating Memory ...\n");
    init_memory();
    char* mem = allocate(4);
    char* me = allocate(10);
    char* e = allocate(1);
    kprintf("\n%x", e);
}


