#include "io.h"
#include "strings.h"
#include <string>

int main(int argc, const char* argv[])
{
    // copy src from dest, if more than one src, copy into folder
    char buffer[4096];
    int bytes_read = 1;
    
    // More than 3 argc, i.e, need to create a folder
    if (argc > 3)
    {
        // read and write 
        mode_t mode = 0755;
        // check if folder already exists
        int folder_check = lain::isDir(argv[argc - 1]);
        int folder;
        if (!folder_check)
        {
            folder = lain::open_folder(argv[argc - 1], mode);
            if (folder == -1)
            {   
                return 1;
            }
        }

        // iterate through every file and copy into a directory
        for (int i = 1; i < argc - 1; i++)
        {
            int fd = lain::open_file(argv[i]);
            if (fd == -1)
            {
                continue;
            }

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
    else 
    {
        // Copy src to dst
        int src = lain::open_file(argv[1]);
        
        if (!lain::isDir(argv[argc - 1]))
        {
            int dst = lain::open_file(argv[argc - 1]);
            if (dst == -1)
            {
                dst = lain::ocreat(argv[argc - 1]);
            }
            while ((bytes_read = lain::read_file(src, buffer, sizeof(buffer))) > 0)
            {
                lain::write_file(dst, buffer, bytes_read);
            }
            lain::close_file(src);
            lain::close_file(dst);
        }
        else 
        {
            if (lain::fileExists(argv[argc - 1]))
            {

            }
        } 
    }
    return 0;
}