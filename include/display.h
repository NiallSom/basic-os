#ifndef DISPLAY_H
#define DISPLAY_H
#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07
#include <stdint.h>
#include <stdarg.h>

struct VGA_pos {
    uint32_t next_line_index;
    uint32_t col;
    uint32_t pos;
};
void clear_screen();
int kprintf(char* str, ...);
void printchar(char character);
void printint(int integer);
void checkPos();
#endif