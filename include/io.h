#include "lain.h"

LAIN_START

int open_file(const char* path);
long read_file(const char* file);
long write_file(const char* file);
int close_file(int fd);

LAIN_END

