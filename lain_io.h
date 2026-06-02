#ifndef LAIN_IO_H
#define LAIN_IO_H

#include "lain_strings.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

static inline int lain_print(const char *format, const char *args[])
{
    int argc = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            if (args[argc] != NULL)
            {
                write(STDOUT_FILENO, args[argc], lain_stringlen(args[argc]));

                argc++;
            }

            i++;
            continue;
        }

        char c = format[i];
        write(STDOUT_FILENO, &c, sizeof(c));
    }

    write(STDOUT_FILENO, "\n", 1);

    return 0;
}

static inline int lain_perror(const char *message)
{
    write(STDERR_FILENO, message, lain_stringlen(message));

    write(STDERR_FILENO, ": ", 2);

    const char *err = strerror(errno);

    write(STDERR_FILENO, err, lain_stringlen(err));

    write(STDERR_FILENO, "\n", 1);

    return -1;
}

#endif
