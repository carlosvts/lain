#include "lain.h"
#include "io.h"
#include "strings.h"

#include <cstdio>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STDOUT 1
#define STDERR 2
int wired_print(const char* string, const char* args[])
{
    int argc = 0;

    unsigned long len = stringlen(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '%' && string[i+1] == 's')
        {
            if (args[argc] != NULL)
            {
                //         1 
                write(STDOUT_FILENO, &args[argc], sizeof(args[argc]));
                argc++;
            }
            else 
            {
                char c = string[i];
                write(STDOUT_FILENO, &c, sizeof(c));
            }
        }
    }
}

// All of the above functions should be REMADE to include MORE FEATURES

int open_file(const char* path)
{
    int fd = open(path, O_RDONLY, 0);
    const char* args[] = {path, NULL};
    if (fd == -1)
    {
        wired_print("Unable to open file at path %s", args);
        return -1;
    }
    return fd;
}

long read_file(int fd, size_t amount)
{
    char bytes_to_read[12];
    itoa(amount, bytes_to_read);
    
    const char* ptr = bytes_to_read;
    const char* args[] = {ptr, NULL};
    
    char buffer[sizeof(amount)];
    int bytes = read(fd, buffer, amount);
    
    if (bytes == -1)
    {
        wired_print("Unable to read %s bytes from file", args);
        return -1;
    }
    return bytes;
}

long write_file(int fd, size_t data)
{
    char buffer[sizeof(data)];
    char bytes_to_write[12];
    itoa(data, bytes_to_write);
    
    const char* ptr = bytes_to_write;
    const char* args[] = {ptr, NULL};
    
    int bytes = write(fd, buffer, data);
    
    if (bytes == -1) 
    {
        return wired_print("Unable to write %s bytes from file", args);
    }
    return bytes;
}

int close_file(int fd)
{
    const char* args[] = {NULL};
    int ok = close(fd);
    if (ok == -1) 
    {
        return  wired_print("An error occurred while closing file", args);
    }
}
