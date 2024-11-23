#ifndef VGA_H
#define VGA_H

#include <stdarg.h>
#include <stdint.h>

#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07


void clear_screen();
void printk(char *message, ...);
void printchar(char character);
void printint(int integer);
void checkPos();
void isr_handler(int interrupt_number);

#endif
