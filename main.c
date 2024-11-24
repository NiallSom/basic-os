#include "include/string.h"
#include "main.h"
#include "include/x86/gdt.h"
#include "include/x86/idt.h"
#include "include/display.h"
#include <stdarg.h>
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
    kprintf("Done\n");
    kprintf("Initiating IDT ...\n");
    init_idt();
    int x = 1/0;
    kprintf("Done\n");
}



