.PHONY: all
all: assembly bkernel link start clean
CC = gcc
NASM = nasm
LD = ld

CFLAGS = -Wno-builtin-declaration-mismatch -fno-stack-protector -m32 -c
LDFLAGS = -m elf_i386
ASMFLAGS = -f elf32


assembly:
	$(NASM) $(ASMFLAGS) boot.asm -o boot.o

bkernel:
	if [ -e "objs.txt" ]; then rm objs.txt; fi;
	$(CC) -c main.c -o kernel.o $(CFLAGS)
	echo -n "boot.o kernel.o " >> objs.txt
	cd arch && $(MAKE) $(MFLAGS)
	cd lib && $(MAKE) $(MFLAGS)
	cd display && $(MAKE) $(MFLAGS)
	cd memory/physical && $(MAKE) $(MFLAGS)

link:
	$(LD) $(LDFLAGS) -T link.ld -o niallos kernel.o boot.o lib/string.o arch/gdt.o arch/idt.o arch/interrupt_handlers.o display/display.o memory/physical/first_fit.o
start: 
	qemu-system-i386 -kernel niallos
clean:
	@$(foreach obj, $(shell cat objs.txt), rm -f $(obj);)
	rm objs.txt