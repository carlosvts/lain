#include "lain.h"
#include "io.h"

#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

// All of the above functions should be REMADE to include MORE FEATURES

int open_file(const char* path)
{
    int fd = open(path, O_RDONLY, 0);
    if (fd == -1)
    {
        // TODO change to my print later
        return 1;
    }
    return fd;
}

long read_file(int fd, size_t amount)
{
    char buffer[sizeof(amount)];
    int bytes = read(fd, buffer, amount);
    if (bytes == -1)
    {
        return 1;
    }
    return bytes;
}

long write_file(int fd, size_t data)
{
    char buffer[sizeof(data)];
    int bytes = write(fd, buffer, data);
    if (bytes == -1) 
    {
        return 1;
    }
    return bytes;
}

int close_file(int fd)
{
    int ok = close(fd);
    if (ok == -1) { return 1; }
}