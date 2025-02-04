/*
 * link.ld
 */

OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
	. = 0x100000;
	.text : {*(.text)}
	.rodata : {*(.rodata)}
	.data : {*(.data)}
	.bss  : {*(.bss) *(COMMON)}
	.heap : {
		__heap_start__ = .;
		. += 0x10000;/*reserve 64KB for heap*/
		__heap_end__ = .;
	}
}