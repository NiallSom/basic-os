#include "../include/display.h"
#include "../include/string.h"
#include "../include/malloc.h"
char *vidmem = (char *)VIDMEMADDR;
struct VGA_pos VGA_position = {0, 0, 0};
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
void _check_pos() {
    if (VGA_position.col >= 160) { // 80 characters long 
        VGA_position.next_line_index++;
        VGA_position.col = 0;
    }
    if (VGA_position.next_line_index > 25){
        clear_screen();
    }
    VGA_position.pos = (VGA_position.next_line_index * 160) + VGA_position.col;
}

void _print_char(char character) {
    _check_pos();
    if (character == '\n') {
        VGA_position.next_line_index++;
        VGA_position.col = 0;
    }else{
        vidmem[VGA_position.pos] = character;
        vidmem[VGA_position.pos + 1] = WHITE_TXT;
        VGA_position.col += 2;
    }
}

void _print_int(int integer) {
    char buffer[12];
    int i = 0;
    if (integer == 0) {
        _print_char('0');
        return;
    }

    if (integer < 0) {
        _print_char('-');
        integer = -integer;
    }

    while (integer > 0) {
        buffer[i++] = '0' + (integer % 10);
        integer /= 10;
    }

    while (i > 0) {
        _print_char(buffer[--i]);
    }
}


int kprintf(char *message, ...) {
    if (!message) {return 1;}
    va_list args;
    va_start(args, message);
    for (const char *p=message; *p;p++){
        _check_pos();
        if (*p != '%') {
            _print_char(*p);
        }else{
            switch (*(++p)){
            case '%': 
                _print_char('%'); 
                break; 
            //character
            case 'c':
                char value = (char) va_arg(args, int);
                _print_char(value);
                break;
            //number
            case 'd': 
                int i = va_arg(args, int); 
                _print_int(i);
                break; 
            //string
            case 's':
                char* string = (char*) va_arg(args, char*);
                while(*string != '\0'){
                    _print_char(*string++);
                }
                break;
            //pointer
            case 'x':
                void* mem = va_arg(args, void*);
                uintptr_t addr = (uintptr_t)mem;
                char buffP[11];
                _itoh(addr,buffP,11);
                kprintf("%s",buffP);
                break;
            default:
                break;
            }
        }
        if (*p == '\0'){
            break;
        }
    }
    va_end(args);
    return 0;
};
