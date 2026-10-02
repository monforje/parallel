#include <omp.h>

#include <cstdio>
#include <vector>

int main() {
    constexpr long n = 100'000'000;
    std::vector<double> v(n, 1.0);

    double t0 = omp_get_wtime();
    double sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (long i = 0; i < n; ++i) sum += v[i];
    double t1 = omp_get_wtime();

    std::printf("threads=%d sum=%.0f time=%.3fs\n", omp_get_max_threads(), sum, t1 - t0);
}
