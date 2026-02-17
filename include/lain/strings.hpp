#pragma once
#include <lain/c/strings.h>

namespace lain {

// ---------- string utils ----------

inline unsigned long stringlen(const char* string)
{
    return lain_stringlen(string);
}

inline void reverse(char* str, int len)
{
    lain_reverse(str, len);
}

inline void itoa(int num, char* str)
{
    lain_itoa(num, str);
}

// ---------- wired io helpers ----------

inline int wired_print(const char* buffer, const char* args[])
{
    return lain_wired_print(buffer, args);
}

inline int wired_perror(const char* str)
{
    return lain_wired_perror(str);
}

} // namespace lain
