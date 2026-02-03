#ifndef LAIN_H
#define LAIN_H

// Macro to use namespaces at Interface (C++)
#ifdef __cplusplus
    #define LAIN_START namespace lain { extern "C" {
            #define LAIN_END } }
#else 
    #define LAIN_START
    #define LAIN_END
#endif

#include <stddef.h> // For typings
#endif
