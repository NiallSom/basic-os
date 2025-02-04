#ifndef MALLOC_H
#define MALLOC_H
extern char __heap_start__, __heap_end__;
#define MEMORY_SIZE 1024 * 1024
#define ALIGNMENT 4
#define HEAP_BASE ((void*)&__heap_start__)
#define HEAP_END ((void*)&__heap_end__)
#define HEAP_SIZE ((size_t)(&__heap_end__ - &__heap_start__))
#include <stddef.h> 
typedef struct FreeBlock {
    size_t size;
    struct FreeBlock* next;
    struct FreeBlock* prev;
    size_t allocated; // either 0 or 1
}FreeBlock;
void init_memory();
void* aligned_alloc(size_t alignment, size_t size);
void* allocate(size_t size);
void* let_go(void* address);
void* memset(void* location, int c, size_t count);
FreeBlock* _find_node(size_t location);
#endif

//1055136
//1120672