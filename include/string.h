#ifndef STRING_H
#define STRING_H
#include <stdbool.h>
bool isdigit(char c);
int strlen(const char * ptr);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, int count);
int strncmp(const char *ptr_to_str1, const char *ptr_to_str2, int n);
char* itoa(int integer);
char* _itoh(unsigned int integer, char *buff, int buff_size);
void _reverse_string(char* string);
#endif