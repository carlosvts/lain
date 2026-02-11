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




