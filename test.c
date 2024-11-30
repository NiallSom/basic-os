#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *itoh(int integer, char *buff)
{
    char x[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int temp;
    int pos = 0;
    if(integer==0){
        buff[pos]='0';
        return buff;
    }
    while (integer>0){
        temp = integer % 16;
        buff[pos++] = x[temp];
        integer /= 16;
    }
    return buff;
}

int main() {
    char* mem = malloc(10);
    char* buff = itoh(hex, mem);
    printf("%s",buff);
    free(mem);
}