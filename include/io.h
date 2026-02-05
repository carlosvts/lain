#include "lain.h"
#include <sys/stat.h>
LAIN_START

int open_file(const char* path);
long read_file(int fd, void* buf, size_t amount);
long write_file(int fd, const void* buf, size_t data);
int close_file(int fd);
int open_folder(const char* path, mode_t mode);

LAIN_END

