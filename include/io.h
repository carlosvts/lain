#include "lain.h"

LAIN_START

int open_file(const char* path);
long read_file(int fd, void* buf, size_t amount);
long write_file(int fd, const void* buf, size_t data);
int close_file(int fd);

LAIN_END

