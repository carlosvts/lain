#include "io.h"
#include "strings.h"
#include <string>

int main(int argc, const char* argv[])
{
    // copy src from dest, if more than one src, copy into folder
    char buffer[4096];
    int bytes_read = 1;
    struct stat path_stat;
    stat(argv[2], &path_stat)
    if (argc == 3 && )
    {
        int src = lain::open_file(argv[1]);
        int dst = lain::open_file(argv[argc - 1]);
        while ((bytes_read = lain::read_file(src, buffer, sizeof(buffer))) > 0)
        {
            lain::write_file(dst, buffer, bytes_read);
        }
        lain::close_file(src);
        lain::close_file(dst);
    } 
    else 
    {
        // read and write 
        mode_t mode = 0755;
        // iterate through every file and copy into a directory
        lain::open_folder(argv[argc - 1], mode);
        for (int i = 1; i < argc - 1; i++)
        {
            int fd = lain::open_file(argv[i]);
            std::string final_path = argv[argc -1] + "/" + argv[i];
            int dst = lain::ocreat(final_path.c_str());
            while ((bytes_read = lain::read_file(fd, buffer, sizeof(buffer))) > 0) 
            {
                lain::write_file(dst, buffer, bytes_read);
            }
            lain::close_file(fd);
            lain::close_file(dst);
        }
    }
    return 0;
}