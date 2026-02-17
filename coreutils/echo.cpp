#include <lain/lain.hpp>
#include <unistd.h>

int main(int argc, const char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        lain::write_file(STDOUT_FILENO, argv[i], lain::stringlen(argv[i]));
        if (i < argc - 1)
        {
            lain::write_file(STDOUT_FILENO, " ", lain::stringlen(" "));
        }
    }
    lain::write_file(STDOUT_FILENO, "\n", lain::stringlen("\n"));
    return 0;
}