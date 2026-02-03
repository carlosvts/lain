#include "lain.h"
#include <unistd.h>

LAIN_START

unsigned long stringlen(const char* string);
int wired_print(const char* buffer, const char* args[] = NULL);

void reverse(char* str, int len);
void itoa(int num, char* str);

LAIN_END