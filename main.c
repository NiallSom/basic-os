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

    char *welcome =
        " _   _ _       _ _   _____ _____ \n"
        "| \\ | (_)     | | | |  _  /  ___|\n"
        "|  \\| |_  __ _| | | | | | \\ `--. \n"
        "| . ` | |/ _` | | | | | | |`--. \\ \n"
        "| |\\  | | (_| | | | \\ \\_/ /\\__/ /\n"
        "\\_| \\_/_|\\__,_|_|_|  \\___/\\____/\n";
    kprintf(welcome);
    kprintf("Initiating GDT ...\n");
    gdt_init();
    kprintf("Initiating IDT ...\n");
    init_idt();
    //int x = 1/0;
    //kprintf("C:/Users/Niall/Desktop/Operating-Systems/basic-kernel#\n");
    kprintf("Initiating Memory ...\n");
    init_memory();
    kprintf("Allocating 10 bytes of memory ...\n");
    char* mem = allocate(1);
    kprintf("\nNew node address: %x", mem);
    char* mm = allocate(10);
    kprintf("\nNew node address: %x", mm);
    char* mme = allocate(10);
    kprintf("\nNew node address: %x", mme);
}

