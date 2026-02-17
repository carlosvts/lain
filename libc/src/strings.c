#include "strings.h"

void lain_reverse(char* str, int len)
{
    // technically we need to reverse only half of the string
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void lain_itoa(int num, char* str)
{
    int i = 0;
    int is_negative = 0;
    

    if (num == 0)
    {
        str[i++] = 0;
        str[i] = '\0';
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        // ex: 42
        // 42 --> 4
        // 2 --> 2
        int rem = rem % 10;
        str[i++] = rem + '0';
        num /= 10;
    }
    if (is_negative)
    {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    lain_reverse(str, i);
}

unsigned long lain_stringlen(const char* string)
{
    unsigned long len = 0;
    while (string[len] != '\0')
    {
        len++;
    }
    return len;
}

