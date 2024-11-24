#ifndef IDT_H
#define IDT_H
#include <stdint.h>
#define IDT_ENTRIES 256

struct idt_entry {
    uint16_t offset_low;    // Lower 16 bits of the handler address
    uint16_t selector;      // Kernel code segment selector
    uint8_t  zero;          // Reserved, must be zero
    uint8_t  type_attr;     // Descriptor type and attributes
    uint16_t offset_high;   // Higher 16 bits of the handler address
} __attribute__((packed));


struct idt_ptr {
    uint16_t limit; // Size of the IDT - 1
    uint32_t base;  // Base address of the IDT
} __attribute__((packed));
void load_idt();
void enable_interrupts();
void set_idt_entry(int n, uint32_t handler, uint16_t selector, uint8_t type_attr);
void init_idt();

#endif
