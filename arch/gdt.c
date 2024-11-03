#include "../include/x86/gdt.h"

struct gdt_entry gdt[3];
struct gdtr gdtr;

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
    gdt[index].base_low = (base & 0xFFFF);
    gdt[index].base_middle = (base >> 16) & 0xFF;
    gdt[index].base_high = (base >> 24) & 0xFF;

    gdt[index].limit_low = (limit & 0xFFFF);
    gdt[index].granularity = (limit >> 16) & 0x0F;
    gdt[index].granularity |= granularity & 0xF0;
    gdt[index].access = access;
}

void gdt_init() {
    // Null segment
    gdt_set_entry(0, 0, 0, 0, 0);

    // code segment: read/execute
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    // cata segment: read/write
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    gdtr.limit = (sizeof(gdt) - 1);
    gdtr.base = (uint32_t)&gdt;
    load_gdtr(&gdtr);
}

void load_gdtr(struct gdtr* gdtr_ptr) {
    asm volatile("lgdt (%0)" : : "r"(gdtr_ptr));
}
