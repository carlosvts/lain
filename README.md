# lain

> Present day, present time

A personal laboratory to explore systems

`lain` reimplements parts of the C standard library and GNU coreutils
from first principles.

Its not a wrapper nor a framework

It is a reconstruction of fundamental Unix behavior,
with strict architectural separation between core logic and interface.

## Design Principles

- Rebuild fundamental routines manually.
- Separate C core from C++ interface.
- Keep implementations explicit.
- Use as much as possible to understand how `libc` and GNU coreutils works

## Architecture

The project enforces a layered model:

```
include/      → Public headers
src/
 ├── lib/         → Core implementations (C)
 └── coreutils/   → CLI utilities (C++)
```

Layer breakdown:

C Core (`lib/`)
- Low-level string handling
- File descriptors
- Direct system interaction

C++ Layer
- Namespaced interface (`lain::`)
- Structured exposure of C core functions

CLI Layer
- Reimplementation of Unix utilities
- Built strictly on top of the library layer


## Implemented Interfaces

### String & Utility

- `unsigned long stringlen(const char* string);`
- `void reverse(char* str, int len);`
- `void itoa(int num, char* str);`
- `int wired_print(const char* buffer, const char* args[]);`
- `int wired_perror(const char* str);`

These functions operate directly on raw buffers and avoid hidden allocation
or implicit behavior.

### File & Descriptor I/O

- `int open_file(const char* path);`
- `long read_file(int fd, void* buf, size_t amount);`
- `long write_file(int fd, const void* buf, size_t data);`
- `int close_file(int fd);`
- `int open_folder(const char* path, mode_t mode);`
- `int ocreat(const char* path);`
- `int isDir(const char* path);`
- `int fileExists(const char* path);`

All file operations are built around file descriptors and system calls.
No high-level stream abstractions are used.

---

## Coreutils

Currently implemented:

- `echo`
- `cat`
- `cp`

Each utility is implemented in C++ and depends strictly on the C core layer.

Example — simplified `cat` loop:

```cpp
#include "strings.h"
#include "io.h"

char buffer[4096];
int bytes_read;

while ((bytes_read = lain::read_file(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    lain::write_file(STDOUT_FILENO, buffer, bytes_read);
```

The utility reads from standard input and writes directly to standard output
using the core descriptor-based interface.


The CLI layer does not access system calls directly.
All interaction goes through the library interface.

---

## Roadmap

- Argument and flag parsing system
- Standardized error handling model
- Directory traversal utilities
- Pipe support
- Static library target
- Unit testing
- Behavior comparison against glibc/coreutils

The roadmap focuses on structural completeness,
not feature breadth.

---

## Build


A proper build system will be added in the future.  
For now, you can compile the project manually using `g++`.

Example:

```
g++ src/coreutils/*.cpp src/lib/*.c -o lain
```
This produces a single executable containing the available utilities.

## Scope

`lain` is not intended to replace libc (nor be better).

The objective is to:

- Understand internal behavior
- Control low-level execution
- Study Unix design decisions
- Explore architectural separation

Every component is written intentionally.
Functionality is added only when necessary.




