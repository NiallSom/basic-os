#include "kernel.h"
#include "../include/string.h"
#include "../include/x86/gdt.h"
static uint32_t next_line_index = 0;

void main() {
    clear_screen();
    char* welcome = " _   _ _       _ _   _____ _____ \n\\
| \\ | (_)     | | | |  _  /  ___|\n\\
|  \\| |_  __ _| | | | | | \\ `--. \n\\
| . ` | |/ _` | | | | | | |`--. \\ \n\\
| |\\  | | (_| | | | \\ \\_/ /\\__/ /\n\\
\\_| \\_/_|\\__,_|_|_|  \\___/\\____/";
    printk(welcome, strlen(welcome));
    char* loadGDT = "\nLoading GDT ...";
    printk(loadGDT, strlen(loadGDT));
    gdt_init();
    printk("Done", 4);

};



void clear_screen() {
    char *vidmem = (char *) VIDMEMADDR;
    unsigned int i = 0;
    while (i < (80*25*2)) {
        vidmem[i] = ' ';
        i++;
        vidmem[i] = WHITE_TXT;
        i++;
    };
};

void printk(char *message, int length) {
    char *vidmem = (char *) VIDMEMADDR;
    uint32_t char_index = 0;
    uint32_t col = 0;
    uint32_t pos;
    for (int i=0; i<length;i++){
        pos = (next_line_index * 80 * 2) + col;
        if (message[char_index] == '\n') {
            next_line_index+=1;
            col = 0;
        }else{
            vidmem[pos] = message[char_index];
            vidmem[pos+1] = 0x07;
            col+=2;
        }
        if (col > 160){
            next_line_index ++;
            col = 0;
        }
        char_index++;
    }
    next_line_index++;
};