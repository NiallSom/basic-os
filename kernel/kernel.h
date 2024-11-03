#ifndef KERNEL_H
#define KERNEL_H
#define VIDMEMADDR 0xB8000
#define WHITE_TXT 0x07
#include "../include/stdint.h"


void clear_screen();
void printk(char *message, int length);
void main();
#endif