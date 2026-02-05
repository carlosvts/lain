#include "io.h"
#include "strings.h"

int main(int argc, const char* argv[])
{
    // copy src from dest, if more than one src, copy into folder
    char buffer[4096];
    int bytes_read = 1;
    if (argc == 3)
    {
        int src = lain::open_file(argv[1]);
        int dst = lain::open_file(argv[argc - 1]);
        while ((bytes_read = lain::read_file(src, buffer, sizeof(buffer))) > 0)
        {
            lain::write_file(dst, buffer, sizeof(bytes_read));
        }
        lain::close_file(src);
        lain::close_file(dst);
    } 
    else 
    {
        // iterate through every file and copy into a directory
        int dst = lain::open_file(argv[argc - 1]);
        for (int i = 1; i <= argc; i++)
        {
            int fd = lain::open_file(argv[i]);
            while ((bytes_read = lain::read_file(fd, buffer, sizeof(buffer))) > 0) 
            {
                lain::write_file(dst, buffer, sizeof(bytes_read));
            }
            lain::close_file(fd);
        }
        lain::close_file(dst);
    }

    return 0;
}