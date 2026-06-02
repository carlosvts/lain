#ifndef LAIN_FS_H
#define LAIN_FS_H

#include "lain_io.h"

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

static inline int lain_open(const char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
    {
        lain_perror(path);
        return -1;
    }

    return fd;
}

static inline int lain_create(const char *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        lain_perror(path);
        return -1;
    }

    return fd;
}

static inline long lain_read(int fd, void *buffer, size_t size)
{
    long bytes = read(fd, buffer, size);

    if (bytes == -1)
    {
        lain_perror("read");
        return -1;
    }

    return bytes;
}

static inline long lain_write(int fd, const void *buffer, size_t size)
{
    long bytes = write(fd, buffer, size);

    if (bytes == -1)
    {
        lain_perror("write");
        return -1;
    }

    return bytes;
}

static inline int lain_close(int fd)
{
    int result = close(fd);

    if (result == -1)
    {
        lain_perror("close");
        return -1;
    }

    return result;
}

static inline int lain_mkdir(const char *path, mode_t mode)
{
    int result = mkdir(path, mode);

    if (result == -1)
    {
        lain_perror(path);
        return -1;
    }

    return result;
}

static inline int lain_exists(const char *path)
{
    struct stat st;

    return stat(path, &st) == 0;
}

static inline int lain_is_dir(const char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
    {
        return 0;
    }

    return S_ISDIR(st.st_mode);
}

#endif
