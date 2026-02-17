#ifndef LAIN_C_IO_H
#define LAIN_C_IO_H

#include "lain.h"
#include <sys/stat.h>

int lain_open_file(const char* path);
long lain_read_file(int fd, void* buf, size_t amount);
long lain_write_file(int fd, const void* buf, size_t data);
int lain_close_file(int fd);
int lain_open_folder(const char* path, mode_t mode);
int lain_ocreat(const char* path);
int lain_is_dir(const char* path);
int lain_file_exists(const char* path);

#endif