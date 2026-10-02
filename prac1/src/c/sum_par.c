#include <stddef.h>

#include "clib.h"

unsigned sum_par(const unsigned *V, size_t n) {
    unsigned acc = 0;
#pragma omp parallel for reduction(+ : acc)
    for (size_t i = 0; i < n; i++) acc += V[i];

    return acc;
}
