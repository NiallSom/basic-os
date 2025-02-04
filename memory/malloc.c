#include "../include/malloc.h"
#include "../include/paging.h"
#include "../include/display.h"
unsigned char bitmap[256]; // 1MB/4KB(blocks) = 256 bytes to represent each 256 blocks
// This is not good - will need to add an allocated datatype in struct

FreeBlock* head = (FreeBlock*)HEAP_BASE;

void init_memory() {
    head->size = HEAP_SIZE;
    head->next = NULL;
    head->prev = NULL;
    memset(bitmap,0,256);
    kprintf("Initializing paging ...\n");
    init_paging();
    kprintf("DONE\n");
}

void* allocate(size_t size) {
    size = sizeof(FreeBlock)+(size + ALIGNMENT-1) & ~(ALIGNMENT-1);
    size_t _mem_index = 0;
    kprintf("Base: %x\n", HEAP_BASE);
    while (_mem_index < 257) {
        if (bitmap[_mem_index] == 0) {
            FreeBlock* node = _find_node(_mem_index);
            if (size <= node->size) { 
                if (node->next) {
                    kprintf("Allocate into pre-existing node at: %x\n", node);
                    bitmap[_mem_index] = 1;
                    return (void*)((unsigned char*)node + sizeof(FreeBlock));   
                } else {
                    kprintf("Creating new node at: %x\n", node);
                    FreeBlock* next = (FreeBlock*)((unsigned char*)node + size);
                    next->size = node->size - size;
                    next->prev = node;
                    next->next = NULL;
                    node->next = next;
                    node->size = size;
                    bitmap[_mem_index] = 1;
                    return (void*)((unsigned char*)node + sizeof(FreeBlock));
                }
            }
        }
        _mem_index++;
    }
    kprintf("\nERROR: OUT OF HEAP SPACE");
    return NULL;
}

char* pallocate(size_t size) {
    
}

void* aligned_alloc(size_t alignment, size_t size) {
    return NULL;
}

FreeBlock* _find_node(size_t location){
    FreeBlock* current = head;
    for(size_t count = 0; count < location;count++){
        if (current->next){
            current = current->next;
        }
    }
    return current;
} 

void* let_go(void* data){
    FreeBlock* current = (FreeBlock*)data;
    kprintf("\nfreed");
    return data;
}
void *memset(void *location, int c, size_t count)
{
    unsigned char *byte_ptr = (unsigned char *) location;
    for(size_t i=0;i<count;i++){
        byte_ptr[i] = (unsigned char) c;
    }
    return location;
}