#include "../include/x86/idt.h"
#include "../include/interrupt_handlers.h"

struct idt_entry idt[IDT_ENTRIES];
struct idt_ptr idtp;
void enable_interrupts() {
    asm volatile ("sti");
}
void disable_interrupts() {
    asm volatile ("cli");
}
void set_idt_entry(int interrupt_num, uint32_t handler_address, uint16_t selector, uint8_t type_attr) {
    idt[interrupt_num].offset_low = handler_address & 0xFFFF;
    idt[interrupt_num].offset_high = (handler_address >> 16) & 0xFFFF;
    idt[interrupt_num].selector = selector;
    idt[interrupt_num].zero = 0;
    idt[interrupt_num].type_attr = type_attr;
}

void load_idt() {
    idtp.limit = (sizeof(struct idt_entry) * IDT_ENTRIES) - 1;
    idtp.base = (uint32_t)&idt;

    asm volatile ("lidt (%0)" : : "r" (&idtp));
}


void init_idt() {
    set_idt_entry(0, (uint32_t)exc_divide_by_zero, 0x08, 0x8E);  // 0x08 is the kernel code segment, 0x8E is the type/attributes
    load_idt();
}