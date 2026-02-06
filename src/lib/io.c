#include "lain.h"
#include "io.h"
#include "strings.h"

#include <cerrno>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int wired_print(const char* string, const char* args[])
{
    int argc = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '%' && string[i+1] == 's')
        {
            if (args[argc] != NULL)
            {
                //         1 
                write(STDOUT_FILENO, args[argc], stringlen(args[argc]));
                argc++;
            }
            i++;
            continue;
        }
        else 
        {
            char c = string[i];
            write(STDOUT_FILENO, &c, sizeof(c));
        }
        
    }
    write(STDOUT_FILENO, "\n", stringlen("\n"));
    return 0;
}

int wired_perror(const char* str)
{
    int err = errno;
    int len = stringlen(str);
    // writing the error code
    char errbuffer[12];
    itoa(err, errbuffer);
    
    write(STDERR_FILENO, str, len);
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
        wired_print("At file %s: ", args);
        wired_perror("    Unable to open file\n");
        return -1;
    }
    return fd;
}

long read_file(int fd, void* buf, size_t amount)
{   
    int bytes = read(fd, buf, amount);
    if (bytes == -1)
    {
        wired_perror("    An error occurred while reading\n");
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
        wired_print("Writing  %s bytes to file", args);
        wired_perror("    Unable to write to file");
        return -1;
    }
    return bytes;
}

int close_file(int fd)
{
    int ok = close(fd);
    if (ok == -1) 
    {
        wired_perror("    An error ocurred while closing this file");
        return -1;
    }
    return ok; 
}

int open_folder(const char* path, mode_t mode)
{
    int ok = mkdir(path, mode);
    if (ok == -1)
    {
        if (errno == EEXIST)
        {
            wired_perror("Folder already exists");
            return -1;
        }
        wired_perror("Error while creating directory");
        return -1;
    }
    return ok;
}

// path should be the full path
int ocreat(const char* path)
{
    int fd = open(path, O_WRONLY | O_CREAT, 0644);
    const char* args[] = {path, NULL};
    if (fd == -1)
    {
        wired_print("At path %s: ", args);
        wired_perror("    Unable to open\n");
        return -1;
    }
    return fd;
}

int isDir(const char* path)
{
    // gets metadata from file
    struct stat path_stat;
    if (stat(path, &path_stat) != 0)
    {
        return 0; 
    }

    return S_ISDIR(path_stat.st_mode);
}

int fileExists(const char* path)
{
    struct stat file;
    if (stat(path, &file) == 0) 
    {
        return 1;
    }
    return 0;
}