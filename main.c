#include "include/string.h"
#include "main.h"
#include "include/x86/gdt.h"
#include "include/x86/idt.h"
#include <stdarg.h>
#include <stdint.h>

#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07

struct VGA_pos {
    uint32_t next_line_index;
    uint32_t col;
    uint32_t pos;
};

struct VGA_pos VGA_position = {0, 0, 0};

char *vidmem = (char *)VIDMEMADDR;

void clear_screen() {
    unsigned int i = 0;
    while (i < (80 * 25 * 2)) {
        vidmem[i] = ' ';
        i++;
        vidmem[i] = WHITE_TXT;
        i++;
    }
    VGA_position.next_line_index = 0;
    VGA_position.col = 0;
    VGA_position.pos = 0;
}

void checkPos() {
    if (VGA_position.col >= 160) {
        VGA_position.next_line_index++;
        VGA_position.col = 0;
    }
    VGA_position.pos = (VGA_position.next_line_index * 160) + VGA_position.col;
}

void printchar(char character) {
    checkPos();
    if (character == '\n') {
        VGA_position.next_line_index++;
        VGA_position.col = 0;
    }else{
        vidmem[VGA_position.pos] = character;
        vidmem[VGA_position.pos + 1] = WHITE_TXT;
        VGA_position.col += 2;
    }
}

void printint(int integer) {
    char buffer[12];
    int i = 0;

    if (integer == 0) {
        printchar('0');
        return;
    }

    if (integer < 0) {
        printchar('-');
        integer = -integer;
    }

    while (integer > 0) {
        buffer[i++] = '0' + (integer % 10);
        integer /= 10;
    }

    while (i > 0) {
        printchar(buffer[--i]);
    }
}
void printk(char *message, ...) {
    va_list args;
    va_start(args, message);
    uint32_t char_index = 0;
    for (const char *p=message; *p;p++){
        checkPos();
        if (*p != '%') {
            printchar(message[char_index]);
        }else{
            switch (*(++p)){
            case 'c':
                char value = (char) va_arg(args, int);
                printchar(value);
                char_index++;
                break;
            case '%': 
                printchar('%'); 
                char_index++;
                break; 
            case 'd': 
                int i = va_arg(args, int); 
                printint(i);
                char_index++;
                break; 
            default:
                break;
            }
        }
        
        if (message[char_index] == '\0'){
            break;
        }
        char_index++;
    }
    va_end(args);
};


void main() {
    clear_screen();

    char *welcome =
        " _   _ _       _ _   _____ _____ \n"
        "| \\ | (_)     | | | |  _  /  ___|\n"
        "|  \\| |_  __ _| | | | | | \\ `--. \n"
        "| . ` | |/ _` | | | | | | |`--. \\ \n"
        "| |\\  | | (_| | | | \\ \\_/ /\\__/ /\n"
        "\\_| \\_/_|\\__,_|_|_|  \\___/\\____/\n";
    printk(welcome);
    printk("Initiating GDT ...", '1', 234);
    gdt_init();
}



