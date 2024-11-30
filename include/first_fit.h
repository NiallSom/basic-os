#ifndef FIRST_FIT_H
#define FIRST_FIT_H
#define MEMORY_SIZE 1024 * 1024
void init_memory();
void* allocate(int size);
void* let_go(void* address);
#endif