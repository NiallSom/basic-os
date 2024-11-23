#ifndef IDT_H
#define IDT_H
#define IDT_SIZE 256
#include <stdint.h>

struct idt_entry_t {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed));

struct idt_ptr_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));


// Functions to initialize the IDT
void init_idt();
void set_idt_entry(int index, uint32_t isr_address, uint16_t selector, uint8_t type_attr);

#endif
