#ifndef LAIN_C_STRINGS_H
#define LAIN_C_STRINGS_H

#include "lain.h"
#include <unistd.h>

unsigned long lain_stringlen(const char* string);
int lain_wired_print(const char* buffer, const char* args[]);
int lain_wired_perror(const char* str);
void lain_reverse(char* str, int len);
void lain_itoa(int num, char* str);

#endif