all:
	echo -n "memory/malloc.o " >> ../objs.txt
	echo -n "memory/paging.o " >> ../objs.txt
	gcc -Wno-builtin-declaration-mismatch -m32 -c paging.c -o paging.o
	gcc -Wno-builtin-declaration-mismatch -m32 -c malloc.c -o malloc.o
