#include "strings.h"
#include "io.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
   int counter = 1;
   char buffer[4096];
   int ok = 1;
   while (ok > 0)
    {
        int fd = lain::open_file(argv[counter]);
        ok = fd;
        int bytes_read = lain::read_file(fd, buffer, sizeof(buffer));
        lain::write_file(STDOUT_FILENO, buffer, bytes_read);
        counter++;
    }
    return 1;
}