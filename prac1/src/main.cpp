#include <omp.h>

#include <cstdio>
#include <memory>

#include "clib.h"

int main() {
    std::size_t n = 1u << 28;
    auto data = std::make_unique<unsigned[]>(n);

    for (std::size_t i = 0; i < n; i++) data[i] = i;

    {
        // sync
        double t_0 = omp_get_wtime();
        auto r = sum(data.get(), n);
        double t_1 = omp_get_wtime();
        printf("Result if sum_par: %u, it took %gms\n", r, (t_0 - t_1) * 1000);

        // async
        double t_2 = omp_get_wtime();
        auto r_par = sum_par(data.get(), n);
        double t_3 = omp_get_wtime();
        printf("Result if sum_par: %u, it took %gms\n", r_par, (t_2 - t_3) * 1000);
    }

    return 0;
}
