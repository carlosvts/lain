#include "lain.h"
#include "io.h"
#include "strings.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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
                write(STDOUT_FILENO, args[argc], sizeof(args[argc]));
                argc++;
            }
            else 
            {
                char c = string[i];
                write(STDOUT_FILENO, &c, sizeof(c));
            }
        }
    }
    write(STDOUT_FILENO, "\n", stringlen("\n"));
    return 0;
}

int wired_perror(const char *str)
{
    int err = errno;
    int len = stringlen(str);
    // writing the error code
    char errbuffer[12];
    itoa(err, errbuffer);
    
    write(STDERR_FILENO, str, len);
    write(STDERR_FILENO, ": [ERROR_CODE]: ", stringlen(": [ERROR_CODE]: "));
    write(STDERR_FILENO, errbuffer, stringlen(errbuffer));
    write(STDERR_FILENO, "\n", stringlen("\n"));
    return 0;
}

// All of the above functions should be REMADE to include MORE FEATURES

int open_file(const char* path)
{
    int fd = open(path, O_RDONLY, 0);
    const char* args[] = {path, NULL};
    if (fd == -1)
    {
        wired_print("Unable to open file at path %s", args);
        wired_perror(" ");
        return -1;
    }
    return fd;
}

long read_file(int fd, void* buf, size_t amount)
{
    const char* args[] = {buf, NULL};
    
    int bytes = read(fd, buf, amount);
    if (bytes == -1)
    {
        wired_print("Unable to read %s bytes from file", args);
        wired_perror(" ");
        return -1;
    }
    return bytes;
}

long write_file(int fd, const void* buf, size_t data)
{
    const char* args[] = {buf, NULL};
    
    int bytes = write(fd, buf, data);   
    if (bytes == -1) 
    {
        wired_print("Unable to write %s bytes from file", args);
        wired_perror(" ");
        return -1;
    }
    return bytes;
}

int close_file(int fd)
{
    const char* args[] = {NULL};
    int ok = close(fd);
    if (ok == -1) 
    {
        wired_print("An error occurred while closing file", args);
        wired_perror(" ");
        return -1;
    }
    return ok; 
}
