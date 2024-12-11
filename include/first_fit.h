#ifndef FIRST_FIT_H
#define FIRST_FIT_H
#define MEMORY_SIZE 1024 * 1024
#define ALIGNMENT 4
#include <stddef.h> 
void init_memory();
void* allocate(size_t size);
void* let_go(void* address);
void* memset(void* location, int c, size_t count);
#endif