all:
	echo -n "arch/gdt.o arch/idt.o arch/interrupt_handlers.o " >> ../objs.txt
	gcc -Wno-builtin-declaration-mismatch -m32 -c gdt.c -o gdt.o
	gcc -Wno-builtin-declaration-mismatch -m32 -c idt.c -o idt.o
	gcc -Wno-builtin-declaration-mismatch -m32 -c interrupt_handlers.c -o interrupt_handlers.o