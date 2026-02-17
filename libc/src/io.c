#include <lain/c/lain.h>
#include <lain/c/io.h>
#include <lain/c/strings.h>

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int lain_wired_print(const char* string, const char* args[])
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

int lain_wired_perror(const char* str)
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

int lain_open_file(const char* path)
{
    int fd = open(path, O_RDONLY, 0);
    const char* args[] = {path, NULL};
    if (fd == -1)
    {
        lain_wired_print("At file %s: ", args);
        lain_wired_perror("    Unable to open file\n");
        return -1;
    }
    return fd;
}

long lain_read_file(int fd, void* buf, size_t amount)
{   
    int bytes = read(fd, buf, amount);
    if (bytes == -1)
    {
        lain_wired_perror("    An error occurred while reading\n");
        return -1;
    }
    return bytes;
}

long lain_write_file(int fd, const void* buf, size_t data)
{
    const char* args[] = {buf, NULL};
    
    int bytes = write(fd, buf, data);   
    if (bytes == -1) 
    {
        lain_wired_print("Writing  %s bytes to file", args);
        lain_wired_perror("    Unable to write to file");
        return -1;
    }
    return bytes;
}

int lain_close_file(int fd)
{
    int ok = close(fd);
    if (ok == -1) 
    {
        lain_wired_perror("    An error ocurred while closing this file");
        return -1;
    }
    return ok; 
}

int lain_open_folder(const char* path, mode_t mode)
{
    int ok = mkdir(path, mode);
    if (ok == -1)
    {
        if (errno == EEXIST)
        {
            lain_wired_perror("Folder already exists");
            return -1;
        }
        lain_wired_perror("Error while creating directory");
        return -1;
    }
    return ok;
}

// path should be the full path
int lain_ocreat(const char* path)
{
    // 0644 permissions rw-r--r--
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    const char* args[] = {path, NULL};
    if (fd == -1)
    {
        lain_wired_print("At path %s: ", args);
        lain_wired_perror("    Unable to open\n");
        return -1;
    }
    return fd;
}

int lain_is_dir(const char* path)
{
    // gets metadata from file
    struct stat path_stat;
    if (stat(path, &path_stat) != 0)
    {
        return 0; 
    }

    return S_ISDIR(path_stat.st_mode);
}

int lain_file_exists(const char* path)
{
    struct stat file;
    if (stat(path, &file) == 0) 
    {
        return 1;
    }
    return 0;
}
