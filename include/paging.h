#ifndef PAGING_H
#define PAGING_H
#define PAGE_SIZE 4096
#define PAGE_ENTRIES 1024
#define PTE_PRESENT (1 << 0)
#define PTE_RW (1 << 1)
#define PTE_USER (1 << 2)
#define PTE_ACCESSED (1 << 5)
#define PTE_DIRTY (1 << 6)
#define PTE_FRAME_MASK 0xFFFFF000
#include <stdint.h>
void enable_paging();
#endif