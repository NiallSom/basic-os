#include "idt.h"
#include "../include/string.h"

// Declare the IDT and its pointer
idt_entry_t idt[IDT_SIZE];
idt_ptr_t idt_ptr;

// Set an entry in the IDT
void set_idt_gate(int n, uint32_t handler) {
    idt[n].base_low = handler & 0xFFFF;        // Low 16 bits of the address
    idt[n].sel = 0x08;                        // Kernel code segment selector
    idt[n].always0 = 0;                       // Always set to 0
    idt[n].flags = 0x8E;                      // Interrupt gate (0x8E = Present, Ring 0, 32-bit)
    idt[n].base_high = (handler >> 16) & 0xFFFF; // High 16 bits of the address
}

// Initialize the IDT
void init_idt() {
    idt_ptr.limit = sizeof(idt_entry_t) * IDT_SIZE - 1;
    idt_ptr.base = (uint32_t)&idt;

    // Clear the IDT
    memset(&idt, 0, sizeof(idt_entry_t) * IDT_SIZE);

    // Load the IDT (defined in assembly)
    lidt(&idt_ptr);  // Load IDT pointer using lidt instruction
}
