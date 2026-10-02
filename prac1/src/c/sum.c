#include <stddef.h>

#include "clib.h"

unsigned sum(const unsigned *V, size_t n) {
    unsigned acc = 0;
    for (size_t i = 0; i < n; i++) acc += V[i];

    return acc;
}
