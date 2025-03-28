#ifndef GDT_H
#define GDT_H
#include <stdint.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdtr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);
void load_gdtr(struct gdtr* gdtr_ptr);
void gdt_init();

#endif
