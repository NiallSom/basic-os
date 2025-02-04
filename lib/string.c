#include "../include/string.h"
#include "../include/display.h"
#include <stdlib.h>

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

char *_itoh(unsigned int integer, char *buff, int buff_size)
{
    char x[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int temp;
    int pos = 0;
    while (integer>0){
        temp = integer % 16;
        buff[pos++] = x[temp];
        integer /= 16;
    }
    while(pos<buff_size-3){
        buff[pos++] = '0';
    }
    buff[pos++] = 'x';
    buff[pos++] = '0';
    _reverse_string(buff);

    buff[pos] = '\0';
    return buff;
}


bool isdigit(char c){
    return c > 47 && c < 58;
}

void _reverse_string(char* string){
    size_t length_of_str = strlen(string);
    for (size_t i=0;i<length_of_str/2;i++){
        char temp = string[i];
        string[i] = string[length_of_str-i-1];
        string[length_of_str-i-1] = temp;
    }
}

