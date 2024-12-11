#include "../../include/first_fit.h"
#include "../../include/display.h"

unsigned char memory[MEMORY_SIZE];



typedef struct FreeBlock {
    size_t size;
    unsigned int allocated;
    struct FreeBlock* next;
    struct FreeBlock* prev;
} FreeBlock;

FreeBlock* free_list = NULL;


void init_memory() {
    free_list = (FreeBlock*)memory;
    free_list->size = MEMORY_SIZE;
    free_list->next = NULL;
    free_list->prev = NULL;
    free_list->allocated = 0;
}

void* allocate(size_t size) {
    size = (size + ALIGNMENT-1) & ~(ALIGNMENT-1);
    //kprintf("\n SIZE: %d", size);
    FreeBlock* current = free_list;
    
    while(current->next !=NULL) {
        current = current->next;
    }
    if (current->size>=size){
        FreeBlock* next = (FreeBlock*)((unsigned char*)current+size);
        //kprintf("\nNew node address: %x", next);
        next->size = current->size-size;
        next->prev = current;
        current->size = size;
        current->next = next;
        current = next;
        current->next = NULL;
        //kprintf("\ncurrent:%x",(uintptr_t)((void*)current));
        //kprintf("\nnext:%x",(uintptr_t)((void*)current->next));
    }else {
        kprintf("\nOut of Memory");
        kprintf("\n     |\n     V\n");
        return NULL;
    }
    kprintf("\nbytes-allocated: %d | current: %x | current-size:%d | next:%x",size, current, current->size, current->next);
    kprintf("\n     |\n     V\n");
    return (void*)current;
}


void* let_go(void* data){
    FreeBlock* current = (FreeBlock*)data;
    current->allocated = 0;
    kprintf("\nfreed");
    return data;
}
void *memset(void *location, int c, size_t count)
{
    FreeBlock *current = (FreeBlock *) location;
    if (count > current->size){
        kprintf("ERROR: count too large for size");
        return location;
    }
    kprintf("%d", current->size);
    unsigned char *byte_ptr = (unsigned char *) location;
    for(size_t i=0;i<count;i++){
        byte_ptr[i] = (unsigned char) c;
    }
    return location;
}