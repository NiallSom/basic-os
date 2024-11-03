#ifndef STRING_H
#define STRING_H
#include <stdbool.h>
bool isdigit(char c);
int strlen(const char * ptr);
int strnlen(const char* ptr, int max);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, int count);
int strncmp(const char *ptr_to_str1, const char *ptr_to_str2, int n);
#endif