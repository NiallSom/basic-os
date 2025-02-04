#include "../include/paging.h"
#include "../include/malloc.h"
#include "../include/display.h"

static uint32_t* page_directory = 0;
static uint32_t page_dir_loc = 0;
static uint32_t* last_page = 0;


void enable_paging(){
    asm volatile ("mov %%eax, %%cr3" : : "a"(page_dir_loc));
    asm volatile ("mov %cr0, %eax");
    asm volatile ("orl $0x80000000, %eax"); // setting the paging bit (31)
    asm volatile ("mov %eax, %cr0");
}