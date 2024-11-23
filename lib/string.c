#include "../include/string.h"


int strlen(const char * string){
    int i=0;
    while(string[i] != '\0'){
        i++;
    }
    return i++;
}
char *strcpy(char *dest, const char *src)
{
    char* res = dest;
    int i=0;
    while(*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0x00;
    return res;
}

char *strncpy(char *dest, const char *src, int count)
{
    char* res = dest;
    int i=0;
    while(*src != '\0') {
        if (i>count) break;
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = 0x00;
    return res;
}

int strncmp(const char *ptr_to_str1, const char *ptr_to_str2, int n)
{
    unsigned char c1,c2;
    while (n-- > 0){
        c1 = (unsigned char)* ptr_to_str1++;
        c2 = (unsigned char)* ptr_to_str2++;
        if (c1 != c2) return c1-c2; // if string1 is larger then string2 the number will be positive, else negative
        if (c1 == '\0') return 0; // strings are identical to this point
    }
}

bool isdigit(char c){
    return c > 47 && c < 58;
}

