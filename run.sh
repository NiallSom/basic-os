nasm -f elf32 kernel/kernel.asm -o bin/kasm.o
gcc -Wno-builtin-declaration-mismatch -m32 -c kernel/kernel.c -o bin/kc.o 
gcc -Wno-builtin-declaration-mismatch -m32 -c lib/string.c -o bin/string.o
gcc -Wno-builtin-declaration-mismatch -m32 -c arch/gdt.c -o bin/gdt.o
# Link to produce the 'kernel' file
ld -m elf_i386 -T kernel/link.ld -o kernel-exec bin/kasm.o bin/kc.o bin/string.o bin/gdt.o

# Run with QEMU
qemu-system-i386 -kernel kernel-exec
