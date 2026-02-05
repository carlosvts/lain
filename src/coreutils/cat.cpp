#include "strings.h"
#include "io.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char buffer[4096];
    if (argc == 1)
    {
        int bytes_read;
        while ((bytes_read = lain::read_file(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
        lain::write_file(STDOUT_FILENO, buffer, bytes_read);
    }
    int counter = 1;
    while (counter < argc)
    {
        int fd = lain::open_file(argv[counter]);
        int bytes_read = 0;
        // loop 4kb of reading  
        while ((bytes_read = lain::read_file(fd, buffer, sizeof(buffer))) > 0)
        {
            lain::write_file(STDOUT_FILENO, buffer, bytes_read);
        }
        lain::close_file(fd);
        counter++;
    }
    return 0;
}