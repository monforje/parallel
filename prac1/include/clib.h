// Интерфейс C-части (src/c/*.c). Одна строка на функцию.
#ifndef CLIB_H
#define CLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

unsigned sum(const unsigned *V, size_t n);      // src/c/sum.c
unsigned sum_par(const unsigned *V, size_t n);  // src/c/sum_par.c

#ifdef __cplusplus
}
#endif

#endif  // CLIB_H
