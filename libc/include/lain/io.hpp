#pragma once
#include <lain/c/io.h>

namespace lain {

// ---------- file descriptors ----------

inline int open_file(const char* path)
{
    return lain_open_file(path);
}

inline long read_file(int fd, void* buf, size_t amount)
{
    return lain_read_file(fd, buf, amount);
}

inline long write_file(int fd, const void* buf, size_t data)
{
    return lain_write_file(fd, buf, data);
}

inline int close_file(int fd)
{
    return lain_close_file(fd);
}

// ---------- creation ----------

inline int open_folder(const char* path, mode_t mode)
{
    return lain_open_folder(path, mode);
}

inline int ocreat(const char* path)
{
    return lain_ocreat(path);
}

// ---------- filesystem queries ----------
// using bool instead of int
inline bool is_dir(const char* path)
{
    return lain_is_dir(path);
}

inline bool file_exists(const char* path)
{
    return lain_file_exists(path);
}

} // namespace lain
