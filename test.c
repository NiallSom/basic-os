#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* x = malloc(8);
    char* y = malloc(8);

    printf("x heap: %p | x stack: %p\n", x, &x);
    printf("y heap: %p | y stack: %p\n", y, &y);
    printf("x: %p\n", &x[0]);
}