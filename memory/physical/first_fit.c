#include "../../include/first_fit.h"
#include <stddef.h> 
#include "../../include/display.h"

unsigned char memory[MEMORY_SIZE];
typedef struct FreeBlock {
    size_t size;
    struct FreeBlock* next;
} FreeBlock;

FreeBlock* free_list = NULL;


void init_memory() {
    free_list = (FreeBlock*)memory;
    free_list->size = MEMORY_SIZE;
    free_list->next = NULL;
}

void* allocate(int size){
    FreeBlock* prev = NULL;
    FreeBlock* current = free_list;

    while (current != NULL) {
        if (current->size >= size) {
            if(current->size > size) {
                FreeBlock* new_node = (FreeBlock*)((unsigned char*)current+size);
                new_node->size = current->size-size;
                new_node->next = current->next;

                current->size = size;
                current->next = new_node;
            } if (prev == NULL){
                free_list = current->next;
            } else{
                prev->next = current->next;
            }
            return (void*)current;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}

void* let_go(void* data){
    FreeBlock* current = (FreeBlock*) data;
    if (!current->next) {
        kprintf("AHHHHH");
    }
}