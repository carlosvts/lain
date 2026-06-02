# lain

> Present day, present time.

A lightweight header-only C library inspired by low-level Unix programming
and some of the ergonomic ideas found in modern languages such as Rust.

`lain` provides small, composable modules for strings, file handling,
I/O, containers, and other foundational utilities while remaining
simple, explicit, and close to the operating system.

The goal is not to replace libc.

The goal is to explore how such abstractions can be built from first
principles while preserving the simplicity and transparency of C.

---

## Philosophy

`lain` follows a few simple principles:

- Header-only whenever practical.
- Explicit behavior over hidden magic.
- Minimal dependencies.
- POSIX-first design.
- Small, composable modules.
- Learn by rebuilding fundamental abstractions.

The project is heavily inspired by Unix design and by the ergonomics
of modern systems languages, particularly Rust.

---

## Current Modules

### `lain.h`

Fundamental types used throughout the library.

```c
i8   i16   i32   i64
u8   u16   u32   u64

f32  f64

usize 
isize
```

### `lain_strings.h`

Basic string utilities and string abstractions.

```c
String
lain_string()
lain_stringlen()
lain_reverse()
lain_itoa()
```

### `lain_io.h`

Low-level output and error handling.

```c
lain_print()
lain_perror()
```

### `lain_fs.h`

Filesystem and file descriptor helpers.

```c
lain_open()
lain_create()
lain_read()
lain_write()
lain_close()
lain_mkdir()
lain_exists()
lain_is_dir()
```

---

## Example

```c
#include <lain/lain_fs.h>

int main(void)
{
    i32 fd = lain_open(
        lain_string("hello.txt"));

    if (fd == -1)
    {
        return 1;
    }

    lain_close(fd);

    return 0;
}
```

---

## Planned modules:

- Dynamic vectors (`Vec`)
- String builders
- Iterators
- Result types
- Option types
- Argument parsing
- Directory traversal
- Logging utilities
- Memory utilities

The objective is to provide useful abstractions without hiding how the
underlying system works.

---

## Non-Goals

`lain` is not:

- A replacement for libc
- A framework
- A language extension
- A Rust clone

The project borrows ideas where they are useful while remaining
idiomatic C.

---

## Platform

Currently developed and tested on:

- Linux
- POSIX-compatible environments

---

## Status

The project is in an early refactoring stage and the API is expected
to evolve significantly.
